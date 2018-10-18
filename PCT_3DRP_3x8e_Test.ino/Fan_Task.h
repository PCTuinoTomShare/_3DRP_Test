

#include <stdint.h>

#ifndef _FAN_TASK_H_
#define _FAN_TASK_H_

// Fan flag.
// bit #0, fan on/off.
volatile uint8_t fn_flag[2];

// Fan on function pointer.
void (*pFAN_ON[2])();
// Fan off function pointer.
void (*pFAN_OFF[2])();

// Initialize.
void Fan_Init( void );
// Fan task.
void Fan_Task( void );

#endif
