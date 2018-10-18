

#ifndef _IO_TASK_H_
#define _IO_TASK_H_

// Arduino DUE digital I/O use define.
#define IO_HT_BED 8 // Heatbed.
#define IO_HT_ETD1 9 // Extruder #1 heater.
#define IO_HT_ETD2 10 // Extruder #2 heater.
#define IO_HT_ETD3 11 // Extruder #3 heater.
#define IO_FAN_DEV1 12 // Fan #1.
#define IO_FAN_DEV2  2 // Fan #2.
#define IO_MOT_XEN 48 // X axis enable.
#define IO_MOT_YEN 46 // Y axis enable.
#define IO_MOT_ZEN 44 // Z axis enable.
#define IO_MOT_ETD1 42 // Extruder #1 motor enable
#define IO_MOT_ETD2 39 // Extruder #2 motor enable
#define IO_MOT_ETD3 45 // Extruder #3 motor enable
#define IO_MOT_E1STEP 36 // Extruder #1 motor step
#define IO_MOT_E2STEP 43 // Extruder #2 motor step
#define IO_MOT_E3STEP 32 // Extruder #3 motor step
#define IO_MOT_E1DIR 28 // Extruder #1 motor direction
#define IO_MOT_E2DIR 41 // Extruder #2 motor direction
#define IO_MOT_E3DIR 47 // Extruder #3 motor direction

#define IO_LMT_XMIN 22 // X axis limit switch lower.
#define IO_LMT_XMAX 30 // X axis limit switch upper.
#define IO_LMT_YMIN 24 // Y axis limit switch lower.
#define IO_LMT_YMAX 38 // Y axis limit switch upper.
#define IO_LMT_ZMIN 26 // Z axis limit switch lower.
#define IO_LMT_ZMAX 34 // Z axis limit switch upper.

// Initialize.
void IO_Init( void );

// Heatbed on.
void IO_HT_Bed_On( void );
// Heatbed off.
void IO_HT_Bed_Off( void );
// Extruder #1 on.
void IO_HT_ETD1_On( void );
// Extruder #1 off.
void IO_HT_ETD1_Off( void );
// Extruder #2 on.
void IO_HT_ETD2_On( void );
// Extruder #2 off.
void IO_HT_ETD2_Off( void );
// Extruder #3 on.
void IO_HT_ETD3_On( void );
// Extruder #3 off.
void IO_HT_ETD3_Off( void );

// Fan #1 on.
void IO_Fan1_On( void );
// Fan #1 off.
void IO_Fan1_Off( void );
// Fan #2 on.
void IO_Fan2_On( void );
// Fan #2 off.
void IO_Fan2_Off( void );

// Motor enable.
// Motor X axis enable on.
void IO_MOT_XEN_On( void );
// Motor X axis enable on.
void IO_MOT_XEN_Off( void );
// Motor Y axis enable on.
void IO_MOT_YEN_On( void );
// Motor Y axis enable on.
void IO_MOT_YEN_Off( void );
// Motor Z axis enable on.
void IO_MOT_ZEN_On( void );
// Motor Z axis enable on.
void IO_MOT_ZEN_Off( void );
// Motor extruder #1 enable on.
void IO_MOT_E1EN_On( void );
// Motor extruder #1 enable off.
void IO_MOT_E1EN_Off( void );
// Motor extruder #2 enable on.
void IO_MOT_E2EN_On( void );
// Motor extruder #2 enable off.
void IO_MOT_E2EN_Off( void );
// Motor extruder #3 enable on.
void IO_MOT_E3EN_On( void );
// Motor extruder #3 enable off.
void IO_MOT_E3EN_Off( void );
// Motor extruder #4 enable on.
void IO_MOT_E4EN_On( void );
// Motor extruder #4 enable off.
void IO_MOT_E4EN_Off( void );
// Motor extruder #5 enable on.
void IO_MOT_E5EN_On( void );
// Motor extruder #5 enable off.
void IO_MOT_E5EN_Off( void );

// Motor rotation direction.
// Motor X axis direction CW.
void IO_MOT_XCW( void );
// Motor X axis direction CCW.
void IO_MOT_XCCW( void );
// Motor Y axis direction CW.
void IO_MOT_YCW( void );
// Motor Y axis direction CCW.
void IO_MOT_YCCW( void );
// Motor Z axis direction CW.
void IO_MOT_ZCW( void );
// Motor Z axis direction CCW.
void IO_MOT_ZCCW( void );
// Motor extruder #1 direction CW.
void IO_MOT_E1CW( void );
// Motor extruder #1 direction CCW.
void IO_MOT_E1CCW( void );
// Motor extruder #2 direction CW.
void IO_MOT_E2CW( void );
// Motor extruder #2 direction CCW.
void IO_MOT_E2CCW( void );
// Motor extruder #3 direction CW.
void IO_MOT_E3CW( void );
// Motor extruder #3 direction CCW.
void IO_MOT_E3CCW( void );
// Motor extruder #4 direction CW.
void IO_MOT_E4CW( void );
// Motor extruder #4 direction CCW.
void IO_MOT_E4CCW( void );
// Motor extruder #5 direction CW.
void IO_MOT_E5CW( void );
// Motor extruder #5 direction CCW.
void IO_MOT_E5CCW( void );

// Motor step.
// Motor X axis step on.
void IO_MOT_XSTEP_On( void );
// Motor X axis step off.
void IO_MOT_XSTEP_Off( void );
// Motor Y axis step on.
void IO_MOT_YSTEP_On( void );
// Motor Y axis step off.
void IO_MOT_YSTEP_Off( void );
// Motor Z axis step on.
void IO_MOT_ZSTEP_On( void );
// Motor Z axis step off.
void IO_MOT_ZSTEP_Off( void );
// Motor E1 step on.
void IO_MOT_E1STEP_On( void );
// Motor E1 step off.
void IO_MOT_E1STEP_Off( void );
// Motor E2 step on.
void IO_MOT_E2STEP_On( void );
// Motor E2 step off.
void IO_MOT_E2STEP_Off( void );
// Motor E3 step on.
void IO_MOT_E3STEP_On( void );
// Motor E3 step off.
void IO_MOT_E3STEP_Off( void );
// Motor E4 step on.
void IO_MOT_E4STEP_On( void );
// Motor E4 step off.
void IO_MOT_E4STEP_Off( void );
// Motor E5 step on.
void IO_MOT_E5STEP_On( void );
// Motor E5 step off.
void IO_MOT_E5STEP_Off( void );



#endif
