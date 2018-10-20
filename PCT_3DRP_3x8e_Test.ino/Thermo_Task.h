
#include <stdint.h>

#ifndef _THERMO_TASK_H_
#define _THERMO_TASK_H_

// Thermo device count.
volatile uint8_t tmo_dev_cnt;

// Thermo ADC converted value. 
volatile int tmo_value[4];

// Thermo task.
void Thermo_Task( void );

#endif
