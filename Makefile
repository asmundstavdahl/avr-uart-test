# Your MCU as named by:
#     ls /usr/lib/gcc/avr/*/device-specs/specs-* | cut -d- -f 3,4 | sort -u
MCU_GCC = at90usb1287

# Your MCU as named by:
#     avrdude -p ?
MCU_AVRDUDE = at90usb1287

# Your programmer as named by:
#     avrdude -c ?
PROGRAMMER = atmelice

FUSES = -U lfuse:w:0x4e:m -U hfuse:w:0x99:m -U efuse:w:0xff:m

# Configure the common avrdude options here
AVRDUDE=avrdude -c $(PROGRAMMER) -p $(MCU_AVRDUDE)

NAME = uart-test
F_SRC = $(NAME).c uart.c
F_HEX = $(NAME).hex

all: build flash

build:
	avr-gcc -mmcu=$(MCU_GCC) -O1 -o $(F_HEX) $(F_SRC)

flash:
	$(AVRDUDE) -U flash:w:$(F_HEX)

clean:
	test -f $(F_HEX) && rm $(F_HEX) || true

fuses:
	$(AVRDUDE) $(FUSES)
