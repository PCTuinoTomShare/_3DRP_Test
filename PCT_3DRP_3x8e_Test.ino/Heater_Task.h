

#include <stdint.h>

#ifndef _HEATER_TASK_H_
#define _HEATER_TASK_H_

// Hearter device polling count.
volatile uint8_t ht_dev_cnt;

// Heater flag.
// bit #0, On/off.
volatile uint8_t ht_flag[4]; 

// Heater on function pointer.
void (*pHT_ON[4])(void);
// Heater off function pointer.
void (*pHT_OFF[4])(void);

// Initialize.
void Heater_Init( void );
// Heater task.
void Heater_Task( void );

#endif
