

#include <stdint.h>

#ifndef _HEATER_TASK_H_
#define _HEATER_TASK_H_

// Heater flag.
// bit #0, On/off.
volatile uint8_t ht_flag[4]; 

// Heater on function pointer.
void (*pHT_ON[4])();
// Heater off function pointer.
void (*pHT_OFF[4])();

// Initialize.
void Heater_Init( void );
// Heater task.
void Heater_Task( void );

#endif
