
#include "Serial_Task.h"
#include "Motor_Task.h"
#include "Heater_Task.h"
#include "fan_task.h"

// Initialize.
void Serial_Init( void )
{
  if( serial_type )
  {
    // Use USART.
    pUSART_USE->begin( 9600 ); 
  }
  else
  {
    // Use UART.
    pUART_USE->begin( 9600 );    
  }
}

// Receive task.
void Serial_Rx_Task( void )
{
  // Receive empty check.
  // and hold received data.
  if( serial_type )
  {
    if( pUSART_USE->available() == 0 )
    {
      // Empty.
      return;
    }
    // Read received data.
    uart_rx_cur = pUSART_USE->read();
  }
  else
  {
    if( pUART_USE->available() == 0 )
    {
      // Empty.
      return;
    }
    // Read received data.      
    uart_rx_cur = pUART_USE->read();    
  }
  // Hold received data.
  uart_rx_data[ uart_rx_cnt ] = uart_rx_cur;
  // Next byte to hold.
  if( uart_rx_cnt < 8 )
  {
    ++uart_rx_cnt;
  }
  // Reset timeout count.
  uart_rx_to = 500;

  // Check received data.
  Serial_Rx_Check();
}

// Received check.
void Serial_Rx_Check( void )
{
  uint8_t temp1;
  uint8_t temp2;

  // Check for new line character.
  if( uart_rx_cur != 0x0d )
  {
    // Not carry return character input.
    if( serial_type )
    {
      // Input feed back.
      pUSART_USE->write( uart_rx_cur );                   
    }
    else
    {
      // Input feed back.
      pUART_USE->write( uart_rx_cur );             
    }
    return;  
  }
  
  // New line.
  Serial_Println(" ");

  // Command byte check.
  switch( uart_rx_data[0] )
  {
    // Motor control.
    case 'M':
    case 'm':
      // Received count check.
      if( uart_rx_cnt < 5 )
      {
        // Too few.
        Serial_Println("input too few < Motor control >");
        break;
      }    
      // Motor device index.
      temp1 = uart_rx_data[1];
      temp1 &= 0x0f;
      if( temp1 > 7 )
      {
        temp1 = 7;
      }
      // On/off.
      temp2 = uart_rx_data[2];
      if( temp2 == 0x30 ) // '0'.
      {
        mt_flag[temp1] &= 0xfe; 
      }
      else
      {
        mt_flag[temp1] |= 0x01;
      }
      // CW/CCW
      temp2 = uart_rx_data[3];
      if( temp2 == 0x30 )// '0'.
      {
        // CW.
        mt_flag[temp1] &= 0xfd; 
      }
      else
      {
        // CCW.
        mt_flag[temp1] |= 0x02;
      }
      break;

    // Heater control.
    case 'H': 
    case 'h':
      // Received count check.
      if( uart_rx_cnt < 4 )
      {
        // Too few.
        Serial_Println("input too few < Heater control >");        
        break;
      }        
      // Heater device index.
      temp1 = uart_rx_data[1];
      temp1 &= 0x0f;
      if( temp1 > 3 )
      {
        temp1 = 3;
      }
      // On/Off.
      temp2 = uart_rx_data[2];
      if( temp2 == 0x30 )// '0'.
      {
        // Off.
        ht_flag[temp1] &= 0xfe;        
      }
      else
      {
        // On.
        ht_flag[temp1] |= 0x01;
      }     
      break;

    // Fan control.
    case 'F':
    case 'f':
      // Received count check.
      if( uart_rx_cnt < 4 )
      {
        // Too few.
        Serial_Println("input too few < Fan control >");        
        break;
      }        
      // Heater device index.
      temp1 = uart_rx_data[1];
      temp1 &= 0x0f;
      if( temp1 > 1 )
      {
        temp1 = 1;
      }
      // On/Off.
      temp2 = uart_rx_data[2];
      if( temp2 == 0x30 )// '0'.
      {
        // Off.
        fn_flag[temp1] &= 0xfe;        
      }
      else
      {
        // On.
        fn_flag[temp1] |= 0x01;
      }     
      break;

    default:    
      break;  
  }
  // Count clear.
  uart_rx_cnt = 0;
 
}

// Message dump.
void Serial_Println( const String &msg )
{
  if( serial_type )
  {
    // Input feed back, new line.
    pUSART_USE->println(msg);                   
  }
  else
  {
    // Input feed back. new line.
    pUART_USE->println(msg);             
  }  
}



