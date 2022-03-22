COMMON_OBJECTS = main.o
CPU    = msp430g2553
CFLAGS = -mmcu-${CPU} -I../h
LDFLAGS= -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc #C Compiler
AS = msp430-elf-as  #Assembly

all: blink_buzz_toy.elf

blink_buzz_toy.elf: ${COMMON_OBJECTS} buzzer.o led.o states.o switches.o
		   ${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: blink_buzz_toy.elf
	msp430loader.sh blink_buzz_toy.elf

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# *.elf

main.o: buzzer.h led.h states.h switches.h

buzzer.o: buzzer.h

led.o: led.c led.h

switches.o: led.h switches.h

states.o: buzzer.h notes.h led.h states.h switches.h
