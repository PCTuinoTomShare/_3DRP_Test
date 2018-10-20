

#include <stdint.h>

#ifndef _FAN_TASK_H_
#define _FAN_TASK_H_

// Fan device polling count.
volatile uint8_t fn_dev_cnt;

// Fan flag.
// bit #0, fan on/off.
volatile uint8_t fn_flag[2];

// Fan on function pointer.
void (*pFAN_ON[2])(void);
// Fan off function pointer.
void (*pFAN_OFF[2])(void);

// Initialize.
void Fan_Init( void );
// Fan task.
void Fan_Task( void );

#endif
