/**
 * This program gives a continuously updated buffered echo on UART.
 * 
 * By Åsmund Stavdahl, 2018
 */

#include "mcu.h"

#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>

#include "uart.h"

#define BUFFER_LENGTH 80

int main (void){
    uart_init();

    unsigned char a;
    unsigned char buf[BUFFER_LENGTH + 1];
    int i = 0;

    while(1){
        a = uart_receive();

        switch(a){
            case 0x7F: // Backspace
                i--;
                if(i < 0) i = 0;
                buf[i] = '\0';
                break;
            case 0x0D: // Enter
                buf[i] = '\\';
                i = (++i) % BUFFER_LENGTH;
                a = 'n';
            default:
                buf[i] = a;
                i = (++i) % BUFFER_LENGTH;
        }

        buf[i+1] = '\0';

        printf("(0x%02x)  %s\r\n", a, buf);
    }
}
