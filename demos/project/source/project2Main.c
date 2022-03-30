#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void main(){
  configureClocks();        //setup master oscillator, CPU & peripheral clocks
  switch_init();            //Initializes switches
  buzzer_init();            //Initializes buzzer
  led_init();               //Initializes LEDs
  enableWDTInterrupts();    //Enable Watch Dog Timer
  or_sr(0x18);              //CPU off, GIE on
}
