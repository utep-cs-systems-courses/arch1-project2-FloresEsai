#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
/*
  Interrupt to play each song loaded in the MSP430

  for a certain amount of time. The variable "tempo"

  is used to calculate at how many interrrupts per

  second each song will be played. Each song loaded

  in the MSP430 has their own tempo pre-determined

  in the header file "switches". Also, a while loop

  is used to make a short pause after each note from 

  the song that is playing on the MSP430's speaker. 

  The method switch_interrupt_hadler is used to

  check is a button on the MSP430 was pressed.
*/
void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char decisecond_count = 0;
  if(++decisecond_count == tempo){
    int repeat = 1;
    while(repeat <= 5){
      int cnt = 0;
      buzzer_set_period(0);
      while(cnt < 30000){
	cnt++;
      }
      repeat++;
    }
    switch_interrupt_handler();
    decisecond_count = 0;
  }
}
