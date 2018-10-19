

#include "IO_Task.h"


// Initialize.
void IO_Init( void )
{
  //uint32_t temp;

  // DAC write protect off.
  //temp = DACC->DACC_WPMR;
  //temp &= 0x00000001;
  //if( temp )
  //{
    //DACC->DACC_WPMR = 0x44414300;
  //}
  // DAC channel off..
  DACC->DACC_CHDR = 0x00000003; // DAC0, DAC1 off.  

  // ADC write protect off. 
  //temp = ADC->ADC_WPMR;
  //temp &= 0x00000001;
  //if( temp )
  //{
    //ADC->ADC_WPMR = 0x41444300;
  //}
  // ADC channel off.
  ADC->ADC_CHDR = 0x00003c00; // AD11, AD10, AD12, AD13 off.

  // Port B
  // PB3, output for extruder #4 motor step control.
  // PB4, output for extruder #4 motor direct control.
  // PB5, output for extruder #4 motor enable control.
  // PB6, output for extruder #5 motor step control.
  // PB7, output for extruder #5 motor direct control.  
  // PB8, output for extruder #5 motor enable control.
  // PB15 ( DAC0 by Arduino DUE ), output for Z axis motor direct control.  
  // PB16 ( DAC1 by Arduino DUE ), output for Z axis motor step control.
  // PB17, output for X axis motor direct control.
  // PB18, output for X axis motor step control.
  // PB19, output for Y axis motor direct control.
  // PB20, output for Y axis motor step control.  
  PIOB->PIO_PER |= 0x001f81f8; // Enable GPIO, disable multiplex.
  PIOB->PIO_OER |= 0x001f81f8; // Enable output port.
  
  // Heater output control pins.
  pinMode( IO_HT_BED, OUTPUT ); // Heatbed.
  pinMode( IO_HT_ETD1, OUTPUT ); // Extruder #1.
  pinMode( IO_HT_ETD2, OUTPUT ); // Extruder #2.
  pinMode( IO_HT_ETD3, OUTPUT ); // Extruder #3.
  // Fan output control pins.
  pinMode( IO_FAN_DEV1, OUTPUT ); // Fan #1.
  pinMode( IO_FAN_DEV2, OUTPUT ); // Fan #2.
  // Motor enable output control pins.
  pinMode( IO_MOT_XEN, OUTPUT ); // X axis motor enable.
  pinMode( IO_MOT_YEN, OUTPUT ); // X axis motor enable.
  pinMode( IO_MOT_ZEN, OUTPUT ); // X axis motor enable.
  pinMode( IO_MOT_ETD1, OUTPUT ); // Extruder #1 motor enable.
  pinMode( IO_MOT_ETD2, OUTPUT ); // Extruder #1 motor enable.
  pinMode( IO_MOT_ETD3, OUTPUT ); // Extruder #1 motor enable.
  pinMode( IO_MOT_E1STEP, OUTPUT ); // Extruder #1 motor step.
  pinMode( IO_MOT_E2STEP, OUTPUT ); // Extruder #2 motor step.
  pinMode( IO_MOT_E3STEP, OUTPUT ); // Extruder #3 motor step.
  pinMode( IO_MOT_E1DIR, OUTPUT ); // Extruder #1 motor dir.
  pinMode( IO_MOT_E2DIR, OUTPUT ); // Extruder #2 motor dir.
  pinMode( IO_MOT_E3DIR, OUTPUT ); // Extruder #3 motor dir.
  // Limit switch.
  pinMode( IO_LMT_XMIN, INPUT ); // X axis limit switch lower.
  pinMode( IO_LMT_XMAX, INPUT ); // X axis limit switch upper.
  pinMode( IO_LMT_YMIN, INPUT ); // Y axis limit switch lower.
  pinMode( IO_LMT_YMAX, INPUT ); // Y axis limit switch upper.
  pinMode( IO_LMT_ZMIN, INPUT ); // Z axis limit switch lower.
  pinMode( IO_LMT_ZMAX, INPUT ); // Z axis limit switch upper.
  
}

// Heatbed on.
void IO_HT_Bed_On( void )
{
  digitalWrite( IO_HT_BED, HIGH );
}
// Heatbed off.
void IO_HT_Bed_Off( void )
{
  digitalWrite( IO_HT_BED, LOW );  
}
// Extruder #1 on.
void IO_HT_ETD1_On( void )
{
  digitalWrite( IO_HT_ETD1, HIGH );  
}
// Extruder #1 off.
void IO_HT_ETD1_Off( void )
{
  digitalWrite( IO_HT_ETD1, LOW );    
}
// Extruder #2 on.
void IO_HT_ETD2_On( void )
{
  digitalWrite( IO_HT_ETD2, HIGH );  
}
// Extruder #2 off.
void IO_HT_ETD2_Off( void )
{
  digitalWrite( IO_HT_ETD2, LOW );    
}
// Extruder #3 on.
void IO_HT_ETD3_On( void )
{
  digitalWrite( IO_HT_ETD3, HIGH );  
}
// Extruder #3 off.
void IO_HT_ETD3_Off( void )
{
  digitalWrite( IO_HT_ETD3, LOW );    
}

// Fan #1 on.
void IO_Fan1_On( void )
{
  digitalWrite( IO_FAN_DEV1, HIGH );
}
// Fan #1 off.
void IO_Fan1_Off( void )
{
  digitalWrite( IO_FAN_DEV1, LOW );  
}
// Fan #2 on.
void IO_Fan2_On( void )
{
  digitalWrite( IO_FAN_DEV2, HIGH );  
}
// Fan #2 off.
void IO_Fan2_Off( void )
{
  digitalWrite( IO_FAN_DEV2, LOW );  
}

// Motor X axis enable on.
void IO_MOT_XEN_On( void )
{
  digitalWrite( IO_MOT_XEN, LOW );
}
// Motor X axis enable on.
void IO_MOT_XEN_Off( void )
{
  digitalWrite( IO_MOT_XEN, HIGH );  
}
// Motor Y axis enable on.
void IO_MOT_YEN_On( void )
{
  digitalWrite( IO_MOT_YEN, LOW );  
}
// Motor Y axis enable on.
void IO_MOT_YEN_Off( void )
{
  digitalWrite( IO_MOT_YEN, HIGH );  
}
// Motor Z axis enable on.
void IO_MOT_ZEN_On( void )
{
  digitalWrite( IO_MOT_ZEN, LOW );  
}
// Motor Z axis enable on.
void IO_MOT_ZEN_Off( void )
{
  digitalWrite( IO_MOT_ZEN, HIGH );  
}

// Motor extruder #1 enable on.
void IO_MOT_E1EN_On( void )
{
  digitalWrite( IO_MOT_ETD1, LOW );
}
// Motor extruder #1 enable off.
void IO_MOT_E1EN_Off( void )
{
  digitalWrite( IO_MOT_ETD1, HIGH );  
}
// Motor extruder #2 enable on.
void IO_MOT_E2EN_On( void )
{
  digitalWrite( IO_MOT_ETD2, LOW );  
}
// Motor extruder #2 enable off.
void IO_MOT_E2EN_Off( void )
{
  digitalWrite( IO_MOT_ETD2, HIGH );  
}
// Motor extruder #3 enable on.
void IO_MOT_E3EN_On( void )
{
  digitalWrite( IO_MOT_ETD3, LOW );  
}
// Motor extruder #3 enable off.
void IO_MOT_E3EN_Off( void )
{
  digitalWrite( IO_MOT_ETD3, HIGH );  
}
// Motor extruder #4 enable on.
void IO_MOT_E4EN_On( void )
{
  // PB5.
  PIOB->PIO_CODR = 0x00000020;
}
// Motor extruder #4 enable off.
void IO_MOT_E4EN_Off( void )
{
  // PB5.
  PIOB->PIO_SODR = 0x00000020;  
}
// Motor extruder #5 enable on.
void IO_MOT_E5EN_On( void )
{
  // PB8.
  PIOB->PIO_CODR = 0x00000100;  
}
// Motor extruder #5 enable off.
void IO_MOT_E5EN_Off( void )
{
  // PB8.
  PIOB->PIO_SODR = 0x00000100;    
}


// Motor X axis direction CW.
void IO_MOT_XCW( void )
{
  // PB17.
  PIOB->PIO_CODR = 0x00020000;
}
// Motor X axis direction CCW.
void IO_MOT_XCCW( void )
{
  // PB17.
  PIOB->PIO_SODR = 0x00020000;  
}
// Motor Y axis direction CW.
void IO_MOT_YCW( void )
{
  // PB19.
  PIOB->PIO_CODR = 0x00080000;
}
// Motor Y axis direction CCW.
void IO_MOT_YCCW( void )
{
  // PB19.
  PIOB->PIO_SODR = 0x00080000;  
}
// Motor Z axis direction CW.
void IO_MOT_ZCW( void )
{
  // PB15.
  PIOB->PIO_CODR = 0x00008000;  
}
// Motor Z axis direction CCW.
void IO_MOT_ZCCW( void )
{
  // PB15.
  PIOB->PIO_SODR = 0x00008000;    
}
// Motor extruder #1 direction CW.
void IO_MOT_E1CW( void )
{
  digitalWrite( IO_MOT_E1DIR, LOW );  
}
// Motor extruder #1 direction CCW.
void IO_MOT_E1CCW( void )
{
  digitalWrite( IO_MOT_E1DIR, HIGH );    
}
// Motor extruder #2 direction CW.
void IO_MOT_E2CW( void )
{
  digitalWrite( IO_MOT_E2DIR, LOW );    
}
// Motor extruder #2 direction CCW.
void IO_MOT_E2CCW( void )
{
  digitalWrite( IO_MOT_E2DIR, HIGH );      
}
// Motor extruder #3 direction CW.
void IO_MOT_E3CW( void )
{
  digitalWrite( IO_MOT_E3DIR, LOW );    
}
// Motor extruder #3 direction CCW.
void IO_MOT_E3CCW( void )
{
  digitalWrite( IO_MOT_E3DIR, HIGH );      
}
// Motor extruder #4 direction CW.
void IO_MOT_E4CW( void )
{
  // PB4.
  PIOB->PIO_CODR = 0x00000010;
}
// Motor extruder #4 direction CCW.
void IO_MOT_E4CCW( void )
{
  // PB4.
  PIOB->PIO_SODR = 0x00000010;  
}
// Motor extruder #5 direction CW.
void IO_MOT_E5CW( void )
{
  // PB7.
  PIOB->PIO_CODR = 0x00000080;  
}
// Motor extruder #5 direction CCW.
void IO_MOT_E5CCW( void )
{
  // PB7.
  PIOB->PIO_SODR = 0x0000080;    
}

// Motor X axis step on.
void IO_MOT_XSTEP_On( void )
{
  // PB18.
  PIOB->PIO_SODR = 0x00040000;
}
// Motor X axis step off.
void IO_MOT_XSTEP_Off( void )
{
  // PB18.
  PIOB->PIO_CODR = 0x00040000;  
}
// Motor Y axis step on.
void IO_MOT_YSTEP_On( void )
{
  // PB20.
  PIOB->PIO_SODR = 0x00100000;  
}
// Motor Y axis step off.
void IO_MOT_YSTEP_Off( void )
{
  // PB20.
  PIOB->PIO_CODR = 0x00100000;    
}
// Motor Z axis step on.
void IO_MOT_ZSTEP_On( void )
{
  // PB16.
  PIOB->PIO_SODR = 0x00010000;    
}
// Motor Z axis step off.
void IO_MOT_ZSTEP_Off( void )
{
  // PB16.
  PIOB->PIO_CODR = 0x00010000;      
}

// Motor E1 step on.
void IO_MOT_E1STEP_On( void )
{
  digitalWrite( IO_MOT_E1STEP, HIGH );
}
// Motor E1 step off.
void IO_MOT_E1STEP_Off( void )
{
  digitalWrite( IO_MOT_E1STEP, LOW );  
}

// Motor E2 step on.
void IO_MOT_E2STEP_On( void )
{
  digitalWrite( IO_MOT_E2STEP, HIGH );  
}
// Motor E2 step off.
void IO_MOT_E2STEP_Off( void )
{
  digitalWrite( IO_MOT_E2STEP, LOW );  
}

// Motor E3 step on.
void IO_MOT_E3STEP_On( void )
{
  digitalWrite( IO_MOT_E3STEP, HIGH );  
}
// Motor E3 step off.
void IO_MOT_E3STEP_Off( void )
{
  digitalWrite( IO_MOT_E3STEP, LOW );  
}

// Motor E4 step on.
void IO_MOT_E4STEP_On( void )
{
  // PB3.
  PIOB->PIO_SODR = 0x00000008;            
}
// Motor E4 step off.
void IO_MOT_E4STEP_Off( void )
{
  // PB3.
  PIOB->PIO_CODR = 0x00000008;          
}

// Motor E5 step on.
void IO_MOT_E5STEP_On( void )
{
  // PB6.
  PIOB->PIO_SODR = 0x00000040;          
}
// Motor E5 step off.
void IO_MOT_E5STEP_Off( void )
{
  // PB6.
  PIOB->PIO_CODR = 0x00000040;            
}




