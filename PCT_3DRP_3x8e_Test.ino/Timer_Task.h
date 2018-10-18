

#include <stdint.h>

#ifndef _TIMER_TASK_H_
#define _TIMER_TASK_H_

// Millis tick count current value.
volatile uint32_t ms_current;
// Millis tick count previous value.
volatile uint32_t ms_previous;
// Millis tick count past value.
volatile uint32_t ms_past;

// Timer task.
void Timer_Task( void );

#endif
