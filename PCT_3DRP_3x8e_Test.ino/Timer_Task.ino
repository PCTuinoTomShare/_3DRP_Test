

#include "Timer_Task.h"
#include "Serial_Task.h"
#include "Motor_Task.h"

// Timer task.
void Timer_Task( void )
{
  // Get current count.
  ms_current = millis();
  ms_past = ms_current;
  ms_past -= ms_previous;

  // Check past count.
  if( ms_past < 10 )
  {
    return;
  }
  // 10ms past.
  // Keep current count as previous.
  ms_previous = ms_current;  

  // Set moto toggle flag.
  mt_toggle = 1;

  // UART time out.
  if( uart_rx_cnt )
  {
    // Hold data not empty.
    if( uart_rx_to )
    {
      // Descrease timeout count.
      --uart_rx_to;
    }
    else
    {
      // Timeout, clear received hold count.
      uart_rx_cnt = 0;
      Serial_Println("Input timeout");
    }
  }

  
}

