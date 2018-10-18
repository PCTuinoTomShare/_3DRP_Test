
#include "Motor_Task.h"
#include "IO_Task.h"

// Initialize.
void Motor_Init( void )
{
  // Enable function pointer setting.
  pMOT_EN[0] = IO_MOT_XEN_On;
  pMOT_EN[1] = IO_MOT_YEN_On;
  pMOT_EN[2] = IO_MOT_ZEN_On;
  pMOT_EN[3] = IO_MOT_E1EN_On;
  pMOT_EN[4] = IO_MOT_E2EN_On;
  pMOT_EN[5] = IO_MOT_E3EN_On;
  pMOT_EN[6] = IO_MOT_E4EN_On;
  pMOT_EN[7] = IO_MOT_E5EN_On;
  // Disable function pointer setting.
  pMOT_DIS[0] = IO_MOT_XEN_Off;
  pMOT_DIS[1] = IO_MOT_YEN_Off;
  pMOT_DIS[2] = IO_MOT_ZEN_Off;  
  pMOT_DIS[3] = IO_MOT_E1EN_Off;
  pMOT_DIS[4] = IO_MOT_E2EN_Off;
  pMOT_DIS[5] = IO_MOT_E3EN_Off;
  pMOT_DIS[6] = IO_MOT_E4EN_Off;
  pMOT_DIS[7] = IO_MOT_E5EN_Off;
  // CW function pointer setting.
  pMOT_CW[0] = IO_MOT_XCW;
  pMOT_CW[1] = IO_MOT_YCW;
  pMOT_CW[2] = IO_MOT_ZCW;
  pMOT_CW[3] = IO_MOT_E1CW;
  pMOT_CW[4] = IO_MOT_E2CW;
  pMOT_CW[5] = IO_MOT_E3CW;
  pMOT_CW[6] = IO_MOT_E4CW;
  pMOT_CW[7] = IO_MOT_E5CW;
  // CCW function pointer setting.
  pMOT_CCW[0] = IO_MOT_XCCW;
  pMOT_CCW[1] = IO_MOT_YCCW;
  pMOT_CCW[2] = IO_MOT_ZCCW;
  pMOT_CCW[3] = IO_MOT_E1CCW;
  pMOT_CCW[4] = IO_MOT_E2CCW;
  pMOT_CCW[5] = IO_MOT_E3CCW;
  pMOT_CCW[6] = IO_MOT_E4CCW;
  pMOT_CCW[7] = IO_MOT_E5CCW;
  // Step on function pointer setting.
  pMOT_STEP_ON[0] = IO_MOT_XSTEP_On;
  pMOT_STEP_ON[1] = IO_MOT_YSTEP_On;
  pMOT_STEP_ON[2] = IO_MOT_ZSTEP_On;
  pMOT_STEP_ON[3] = IO_MOT_E1STEP_On;
  pMOT_STEP_ON[4] = IO_MOT_E2STEP_On;
  pMOT_STEP_ON[5] = IO_MOT_E3STEP_On;
  pMOT_STEP_ON[6] = IO_MOT_E4STEP_On;
  pMOT_STEP_ON[7] = IO_MOT_E5STEP_On;
  // Step off function pointer setting.
  pMOT_STEP_OFF[0] = IO_MOT_XSTEP_Off;
  pMOT_STEP_OFF[1] = IO_MOT_YSTEP_Off;
  pMOT_STEP_OFF[2] = IO_MOT_ZSTEP_Off;
  pMOT_STEP_OFF[3] = IO_MOT_E1STEP_Off;
  pMOT_STEP_OFF[4] = IO_MOT_E2STEP_Off;
  pMOT_STEP_OFF[5] = IO_MOT_E3STEP_Off;
  pMOT_STEP_OFF[6] = IO_MOT_E4STEP_Off;
  pMOT_STEP_OFF[7] = IO_MOT_E5STEP_Off;

  mt_speed[0] = 10;
  mt_speed[1] = 10;
  mt_speed[2] = 10;
  mt_speed[3] = 10;
  mt_speed[4] = 10;
  mt_speed[5] = 10;
  mt_speed[6] = 10;
  mt_speed[7] = 10;    
}

// Motor task.
void Motor_Task( void )
{
  uint8_t temp1;
  uint8_t temp2;

  // Motor toggle flag check.
  if( mt_toggle == 0 )
  {
    return;
  }
  mt_toggle = 0;

  temp1 = 0;
  while( temp1 < 8 )
  {

    // Check on off flag bit.
    temp2 = mt_flag[temp1];
    temp2 &= 0x01;
    if( temp2 == 0 )
    {
      // Off.
      pMOT_DIS[temp1]();
      // Reload period count.
      mt_period[temp1] = mt_speed[temp1];
      // Step off.
      pMOT_STEP_OFF[temp1]();        
      mt_flag[temp1] &= 0xfb;        
    }
    else
    {
      // On
      pMOT_EN[temp1]();
      // Check pulse period count.
      if( mt_period[temp1] )
      {
        // Decerase count.
        --mt_period[temp1];
      }
      else
      {
        // Period count down to 0.
        // Reload period count.
        mt_period[temp1] = mt_speed[temp1];

        // Check rotation direction.
        temp2 = mt_flag[temp1];
        temp2 &= 0x02;
        if( temp2 == 0 )
        {
          pMOT_CW[temp1]();        
        }
        else
        {
          pMOT_CCW[temp1]();
        }

        // Check step pulse phase flag bit.
        temp2 = mt_flag[temp1];
        temp2 &= 0x04;
        if( temp2 == 0 )
        {
          // Output high
          pMOT_STEP_ON[temp1]();
          mt_flag[temp1] |= 0x04;
        }
        else
        {
          // Output low.
          pMOT_STEP_OFF[temp1]();        
          mt_flag[temp1] &= 0xfb;        
        }    
      }
    }
    
    // Next device.
    ++temp1;
  }
  
}

