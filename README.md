# Hardware UART test for AVR

Implementation is for the AT90USB1287 but it should be easy to port to other
chips.

## Connection

Use something like `screen /dev/ttyS0 9600` to speak to the MCU once it's
connected to your computer via RS232.

## Porting to other chips

- configure Makefile; see Makefile for instructions
- tweak uart.c, specifically:
  - uart_init
  - uart_rx_ready
  - uart_tx_complete
  - uart_receive
  - uart_transmit

## Example behaviour
```
(0xc3)  �
(0x85)  Å
(0x73)  Ås
(0x6d)  Åsm
(0x75)  Åsmu
(0x6e)  Åsmun
(0x64)  Åsmund
(0x20)  Åsmund 
(0x45)  Åsmund E
(0x7f)  Åsmund 
(0x65)  Åsmund e
(0x20)  Åsmund e 
(0x62)  Åsmund e b
(0x65)  Åsmund e be
(0x73)  Åsmund e bes
(0x74)  Åsmund e best
(0x21)  Åsmund e best!

```
