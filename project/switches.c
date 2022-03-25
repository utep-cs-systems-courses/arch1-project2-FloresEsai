#include <msp430.h>
#include "switches.h"
#include "led.h"

void switch_init()
/* similarly to modular demo 10 we swap the switches to correspond to p2.0-3 */
{

  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

}



// state variables representing which switch was pressed down last

int sw1 = 0;

int sw2 = 0;

int sw3 = 0;

int sw4 = 0;



void switch_interrupt_handler() // determine which switch was pressed down

{

  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES); // if switch up, sense down

  sw1 = (p2val & SW1) ? 0 : 1; // if button1 up == 0 otherwise button down == 1

  sw2 = (p2val & SW2) ? 0 : 1; // if button2 up == 0 otherwise button down == 1

  sw3 = (p2val & SW3) ? 0 : 1; // if button3 up == 0 otherwise button down == 1

  sw4 = (p2val & SW4) ? 0 : 1; // if button4 up == 0 otherwise button down == 1

}
