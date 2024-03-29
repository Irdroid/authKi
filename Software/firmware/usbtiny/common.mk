# ======================================================================
# Common Makefile for USBtiny applications
#
# Macros to be defined before including this file:
#
# USBTINY	- the location of this directory
# TARGET_ARCH	- gcc -mmcu= option with AVR device type
# OBJECTS	- the objects in addition to the USBtiny objects
# FLASH_CMD	- command to upload main.hex to flash
# STACK		- maximum stack size (optional)
# FLASH		- flash size (optional)
# SRAM		- SRAM size (optional)
# SCHEM		- Postscript version of the schematic to be generated
#
# Copyright (C) 2006 Dick Streefland
#
# This is free software, licensed under the terms of the GNU General
# Public License as published by the Free Software Foundation.
# ======================================================================

CC	= avr-gcc
CFLAGS	= -Os -g -Wall -I. -I$(USBTINY)

# temporary workaround for the �error: attempt to use poisoned "SIG_INTERRUPT0"�
CFLAGS += -D__AVR_LIBC_DEPRECATED_ENABLE__=1

ASFLAGS	= -Os -g -Wall -I.
LDFLAGS	= -g
MODULES = crc.o int.o usb.o $(OBJECTS)
UTIL	= ./

main.hex:

all:		main.hex $(SCHEM)

clean:
	rm -f main.hex main.elf *.o tags  

clobber:	clean
	rm -f main.hex $(SCHEM)

main.elf:	$(MODULES)
	$(LINK.o) -o $@ $(MODULES)

main.hex:	main.elf 
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

disasm:		main.elf
	avr-objdump -S main.elf

flash:		main.hex
	$(FLASH_CMD)

crc.o:		$(USBTINY)/crc.S $(USBTINY)/def.h usbtiny.h
	$(COMPILE.c) $(USBTINY)/crc.S
int.o:		$(USBTINY)/int.S $(USBTINY)/def.h usbtiny.h
	$(COMPILE.c) $(USBTINY)/int.S
usb.o:		$(USBTINY)/usb.c $(USBTINY)/def.h $(USBTINY)/usb.h usbtiny.h
	$(COMPILE.c) $(USBTINY)/usb.c

main.o:		$(USBTINY)/usb.h


