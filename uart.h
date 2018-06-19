#ifndef _UART_TEST_UART_H_
#define _UART_TEST_UART_H_

#include <stdio.h>

#include "mcu.h"

#define BAUD 9600UL
#define BAUDRATE (F_CPU / (16UL*BAUD) - 1)


void uart_init();
char uart_rx_ready();
char uart_tx_complete();
char uart_receive();
void uart_transmit(char data);

// Initialize this with fdevopen():
FILE *io_stream;
// Use these for io_stream (std{in,out,err})
int uart_put(char, FILE*);
int uart_get(FILE*);

#endif
