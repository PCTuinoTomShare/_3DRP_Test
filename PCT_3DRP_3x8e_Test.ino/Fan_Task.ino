
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

  // Reset count.
  fn_dev_cnt = 0;  
}

// Fan task.
void Fan_Task( void )
{
  uint8_t temp1;

  temp1 = fn_flag[fn_dev_cnt];
  temp1 &= 0x01;
  if( temp1 )
  {
    // Turn on.
    pFAN_ON[fn_dev_cnt]();
  }
  else
  {
    // Turn off.
    pFAN_OFF[fn_dev_cnt]();      
  }

  // Next device to polling.
  ++fn_dev_cnt;
  if( fn_dev_cnt == 2 )
  {
    fn_dev_cnt = 0;
  }  
}

