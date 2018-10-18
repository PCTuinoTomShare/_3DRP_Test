
#include "Timer_Task.h"
#include "Serial_Task.h"
#include "IO_Task.h"
#include "Motor_Task.h"
#include "Heater_Task.h"
#include "Fan_Task.h"

void setup() {
  // put your setup code here, to run once:

  // IO initialize.
  IO_Init();
  
  // Serial initialize.
  serial_type = 0;
  pUART_USE = &Serial;
  Serial_Init();

  // Motor initialize.
  Motor_Init();
  // Heater initialize.
  Heater_Init();
  // Fan initialize.
  Fan_Init();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // Serial received task. 
  Serial_Rx_Task();

  // Motor task.
  Motor_Task();
  // Heater task.
  Heater_Task();
  // Fan task.
  Fan_Task();
  // Timer task.
  Timer_Task();
}
