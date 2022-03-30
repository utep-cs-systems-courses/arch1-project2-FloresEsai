#include "libTimer.h"
#include "buzzer.h"
#include <msp430.h>

static int counterForSWTheme = 0; //Counter to keep track of the notes in the Star Wars Theme song

void buzzer_init(){
  /*
    Direct timer A output "TA0.1" to P2.6.
    According to table 21 from data sheet:
    P2SEL2.6, P2SEL2.7, and P2SEL.7 must be zero
    P2SEL.6 must be 1
    Also: P2.6 direction must be output
  */
  timerAUpmode(); //used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //enable output to speaker (P2.6)
}

void siren_buzzer(){
  for (int pitch = 30; pitch < 2000; pitch++){
    buzzer_set_period(pitch);
    delay(5);
  }
}

/*
  starWarsTheme is a method which calls the buzzer_set_period method
  from the buzzer.h file to produce the sound of the frequency specified on
  each case. When the method is called consistently, the song from the Star Wars
  movie is played on the MSP430's speaker.
*/
void starWarsTheme(){
  switch(counterForSWTheme){
  case 0: buzzer_set_period(950); counterForSWTheme++; break; //Lower C note
  case 1:
  case 6:
  case 11: buzzer_set_period(630); counterForSWTheme++; break; //G note
  case 2:
  case 7:
  case 12:
  case 14: buzzer_set_period(710); counterForSWTheme++; break; //F note
  case 3:
  case 8:
  case 13: buzzer_set_period(750); counterForSWTheme++; break; //E note
  case 4:
  case 9:
  case 15: buzzer_set_period(840); if(counterForSWTheme==15){counterForSWTheme = 0;} else{counterForSWTheme++;}; break;//D note
  case 5:
  case 10: buzzer_set_period(475); counterForSWTheme++; break; //C note
  }
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1; //one half cycle
}
