
#include <stdint.h>

#ifndef _LIMIT_SW_TASK_H_
#define _LIMIT_SW_TASK_H_

// Limit switch input channel count.
volatile uint8_t lmt_ch_cnt; 
// Limit switch status flag.
volatile uint8_t lmt_flag[3];

// Function pointer, read upper limit switch.
uint8_t (*pLMT_UP[3])(void);
// Function pointer, read lower limit switch.
uint8_t (*pLMT_LO[3])(void);

// Initialize
void Limit_SW_Init( void );
// Limit switch task.
void Limit_SW_Task( void );

#endif
