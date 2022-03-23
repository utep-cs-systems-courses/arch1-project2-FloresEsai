#include <msp430.h>

#include "buzzer.h"

#include "led.h"

#include "libTimer.h"

#include "switches.h"







int main(void) {



  led_init();

  buzzer_init();

  switch_init();



  configureClocks();  /* setup master oscillator, CPU & peripheral clocks */

  enableWDTInterrupts();/* enable periodic interrupt */



  or_sr(0x18);      /* CPU off, GIE on */

}
