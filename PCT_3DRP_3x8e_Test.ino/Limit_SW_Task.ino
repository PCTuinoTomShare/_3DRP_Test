
#include "LImit_SW_Task.h"
#include "IO_Task.h"

// Initialize
void Limit_SW_Init( void )
{
  // Upper switch read function pointer setting.
  pLMT_UP[0] = IO_LMT_X_UPPER;
  pLMT_UP[1] = IO_LMT_Y_UPPER;
  pLMT_UP[2] = IO_LMT_Z_UPPER;
  // Lower switch read function pointer setting.
  pLMT_LO[0] = IO_LMT_X_LOWER;
  pLMT_LO[1] = IO_LMT_Y_LOWER;
  pLMT_LO[2] = IO_LMT_Z_LOWER;
  
  // Reset count.
  lmt_ch_cnt = 0;
}

// Limit switch task.
void Limit_SW_Task( void )
{
  // Upper limit switch input.
  if( pLMT_UP[lmt_ch_cnt] )
  {
    // Triggered on.
    lmt_flag[lmt_ch_cnt] |= 0x02;
  }
  else
  {
    // Not Triggered on.
    lmt_flag[lmt_ch_cnt] &= 0xfd;    
  }

  // Lower limit switch input.
  if( pLMT_LO[lmt_ch_cnt] )
  {
    // Triggered on.
    lmt_flag[lmt_ch_cnt] |= 0x01;
  }
  else
  {
    // Not trigger on.
    lmt_flag[lmt_ch_cnt] &= 0xfe;    
  }

  // For next channel switch.
  ++lmt_ch_cnt;
  if( lmt_ch_cnt == 3 )
  {
    lmt_ch_cnt = 0;
  }
}

