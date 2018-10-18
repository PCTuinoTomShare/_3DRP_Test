

#include "Heater_Task.h"
#include "IO_Task.h"

// Initialize.
void Heater_Init( void )
{
  // Heater on function pointer setting.
  pHT_ON[0] = IO_HT_Bed_On;
  pHT_ON[1] = IO_HT_ETD1_On;
  pHT_ON[2] = IO_HT_ETD2_On;
  pHT_ON[3] = IO_HT_ETD3_On;
  // Heater off function pointer setting.
  pHT_OFF[0] = IO_HT_Bed_Off;
  pHT_OFF[1] = IO_HT_ETD1_Off;
  pHT_OFF[2] = IO_HT_ETD2_Off;
  pHT_OFF[3] = IO_HT_ETD3_Off;
  
}

// Heater task.
void Heater_Task( void )
{
  uint8_t temp1;
  uint8_t temp2;

  // Heaters on/off.
  temp1 = 0;
  while( temp1 < 4 )
  {
    temp2 = ht_flag[temp1];
    temp2 &= 0x01;
    if( temp2 )
    {
      pHT_ON[temp1]();
    }
    else
    {
      pHT_OFF[temp1]();      
    }

    ++temp1;    
  }
  
}

