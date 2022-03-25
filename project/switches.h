#ifndef switches_included
#define switches_included

/* p2.0 - p2.3 will be switches 1-4 */
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1 | SW2 | SW3 | SW4)

void switch_init();
void switch_interrput_handler();

/* -------------------------------  */

extern int sw1, sw2, sw3, sw4;

/* -------------------------------- */
#endif
