
#include <stdint.h>

#ifndef _MOTOR_TASK_H_
#define _MOTOR_TASK_H_

// Motor toggle flag.
volatile uint8_t mt_toggle;
// Motor speed.
volatile uint8_t mt_speed[8];
// Motor pulse period count.
volatile uint8_t mt_period[8];
// Motor flag.
// bit #0, on/off, 0 = off, others on.
// bit #1, rotation direction, 0 = CW, others CCW.
// bit #2, step on/off, 0 = step off, others on.
volatile uint8_t mt_flag[8];

// Motor enable.
void (*pMOT_EN[8])(void);
// Motor disable.
void (*pMOT_DIS[8])(void);
// Motor CW.
void (*pMOT_CW[8])(void);
// Motor CCW.
void (*pMOT_CCW[8])(void);
// Motor step on.
void (*pMOT_STEP_ON[8])(void);
// Motor step off.
void (*pMOT_STEP_OFF[8])(void);

// Initialize.
void Motor_Init( void );
// Motor task.
void Motor_Task( void );

#endif
