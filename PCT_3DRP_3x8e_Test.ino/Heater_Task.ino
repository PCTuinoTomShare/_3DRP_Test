

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

  // Reset count.
  ht_dev_cnt = 0;
}

// Heater task.
void Heater_Task( void )
{
  uint8_t temp1;

  // Heaters on/off.
  temp1 = ht_flag[ht_dev_cnt];
  temp1 &= 0x01;
  if( temp1 )
  {
    // Turn on.
    pHT_ON[ht_dev_cnt]();
  }
  else
  {
    // Turn off.
    pHT_OFF[ht_dev_cnt]();      
  }

  // For next device to polling.
  ++ht_dev_cnt;
  if( ht_dev_cnt == 4 )
  {
    ht_dev_cnt = 0;
  }
}

