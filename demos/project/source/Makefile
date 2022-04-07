# makfile configuration
COMMON_OBJECTS  = project2Main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf

#additional rules for files
toy.elf: ${COMMON_OBJECTS} buzzer.o interrupts.o led.o switches.o project2Main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh $^ toy.elf

clean:
	rm -f *.c~ *.h~ *.o *.elf

buzzer.c: buzzer.h
interrupts.c: led.h switches.h buzzer.h
led.c: led.h
project2Main.c: buzzer.h led.h switches.h 
switches.c: switches.h
