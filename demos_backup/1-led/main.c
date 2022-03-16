//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT |= LED_GREEN;
  P1OUT |= LED_RED;

  // using P1OUT we can turn on both the green and red LEDs, using the '|=' operator

  or_sr(0x18);		/* CPU off, GIE on */
}
