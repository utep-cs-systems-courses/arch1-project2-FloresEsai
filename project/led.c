#include <msp430.h>
#incldue "led.h"
#include "switches.h"

// we tell p1DIR we are going to give I/O instructions to the LEDs
void led_init(){
  P1DIR |= LEDS;
  led_update();
}

// the LEDs will be turned off by default until we tell them otherwise
void led_update(){
  P1OUT &= ~LEDS;
}

// turns the red LED on when the input On is 1, otherwise the LED is turned/left off
void red_on(int on){
  if (on){
    P1OUT |= LED_RED;
  }
  else
    P1OUT &= ~LED_RED;
}

// turns the green LED on when the input On is 1, otherwise the LED is turned/left off
void green_on(int on){
  if (on){
    P1OUT |= LED_GREEN;
  }
  else
    P1OUT &= ~LED_GREEN;
}

// turns on both LEDs when input is 1, otherwise off
void leds_on(int on){
  if (on){
    P1OUT |= LEDS;
  }
  else
    P1OUT &= ~LEDS;
}

// swaps the current states of the LEDs, default state where they are both off
void led_swap(int on){
  switch(on){
  case 0:
    red_on(1);
    green_on(0);
    break;
  case 1:
    red_on(0);
    green_on(1);
    break;
  default:
    leds_on(0);
    break;
  }
}
