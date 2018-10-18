
#include "Fan_Task.h"
#include "IO_Task.h"

// Initialize.
void Fan_Init( void )
{
  // On function pointer setting.
  pFAN_ON[0] = IO_Fan1_On;
  pFAN_ON[1] = IO_Fan2_On;
  // Off function pointer setting.
  pFAN_OFF[0] = IO_Fan1_Off;
  pFAN_OFF[1] = IO_Fan2_Off;  
}

// Fan task.
void Fan_Task( void )
{
  uint8_t temp1;
  uint8_t temp2;

  temp1 = 0;
  while( temp1 < 2 )
  {
    temp2 = fn_flag[temp1];
    temp2 &= 0x01;

    if( temp2 == 0 )
    {
      pFAN_OFF[temp1]();
    }
    else
    {
      pFAN_ON[temp1]();      
    }

    // Next device.
    ++temp1;
  }
  
}

