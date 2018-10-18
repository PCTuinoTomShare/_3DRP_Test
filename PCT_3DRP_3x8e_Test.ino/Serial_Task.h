

#include <stdint.h>
#include <UARTClass.h> // Arduino DUE.
#include <USARTClass.h> // Arduino DUE.

#ifndef _SERIAL_TASK_H_
#define _SERIAL_TASK_H_

// Use UART or USART.
UARTClass *pUART_USE;
USARTClass *pUSART_USE;

// Serial port type flag.
// 0, UART.
// 1, USART. 
volatile uint8_t serial_type;
// Received data count.
volatile uint8_t uart_rx_cnt;
// Received data.
volatile uint8_t uart_rx_data[16];
// Received time out.
volatile uint8_t uart_rx_to;
// Received data current byte.
volatile uint8_t uart_rx_cur;

// Initialize.
void Serial_Init( void );
// Receive task.
void Serial_Rx_Task( void );
// Received check.
void Serial_Rx_Check( void );

// Message dump.
void Serial_Println( const String &msg );


#endif
