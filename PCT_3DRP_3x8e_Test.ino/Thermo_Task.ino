
#include "Thermo_Task.h"

// Device ADC channel.
const uint8_t  Thermo_ADC_Port[4] = {0,1,2,3};

// Thermo task.
void Thermo_Task( void )
{
  // Read thermos ADC.
  tmo_value[ tmo_dev_cnt] = analogRead( Thermo_ADC_Port[ tmo_dev_cnt ] );
  // For next thermo sensor.
  ++tmo_dev_cnt;
  if( tmo_dev_cnt == 4 )
  {
    tmo_dev_cnt = 0;
  }
}

