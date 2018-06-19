#include <avr/io.h>
#include <stdio.h>

#include "uart.h"

void uart_init(){
    UBRR1H = (unsigned char)(BAUDRATE>>8);
    UBRR1L = (unsigned char)BAUDRATE;
    UCSR1B|= (1<<TXEN1)|(1<<RXEN1);
    UCSR1C|= (1<<UCSZ11)|(1<<UCSZ10) | (0<<USBS1);
             // 8 data bits         // 1 stop bit

    // Set up streams for stdio. The first read/write stream(s) opened are
    // automatically used for stdin/stdout+stderr.
    // See: https://www.gnu.org/savannah-checkouts/non-gnu/avr-libc/user-manual/stdio_8h_source.html
    io_stream = fdevopen(
        &uart_put,
        &uart_get
    );
}

// Check if transfer is completed.
char uart_tx_complete(){
    return UCSR1A & (1<<UDRE1);
}

// Check if anything has been received and is ready for reading.
char uart_rx_ready(){
    return UCSR1A & (1<<RXC1);
}

void uart_transmit(char data){
    while(!uart_tx_complete())
        ;
    UDR1 = data;
}

char uart_receive(void){
    while(!uart_rx_ready())
    	;
    return UDR1;
}

int uart_put(char a, FILE *stream){
    uart_transmit(a);
    return 0;
}

int uart_get(FILE *stream){
    return uart_receive();
}
