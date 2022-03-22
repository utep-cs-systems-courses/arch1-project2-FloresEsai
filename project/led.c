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
