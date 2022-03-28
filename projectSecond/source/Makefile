COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS			 = -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc # C COMPILER
AS              = msp430-elf-as  # ASSEMEBLY


all: toy.elf

toy.elf: ${COMMON_OBJECTS} buzzer.o dim_sequence.o led.o switches.o state_machines.o  wdInterruptHandler.o p2_interrupt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# *.elf *#


main.o: buzzer.h led.h state_machines.h switches.h

buzzer.o: buzzer.h
led.o: led.c led.h
switches.o: led.h switches.h

dim_sequence.o: led.c led.h state_machines.h
state_machines.o: buzzer.h buzzer_notes.h led.h state_machines.h switches.h

wdInterruptHandler.o:  buzzer.h led.h state_machines.h switches.h
p2_interrupt_handler.o: switches.h