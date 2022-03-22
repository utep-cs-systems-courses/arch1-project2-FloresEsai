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

/* variables to hold the current state of switch */
extern int sw1_status;
extern int sw2_status;
extern int sw3_status;
extern int sw4_status;

extern int sw1_pressed;
extern int sw2_pressed;
extern int sw3_pressed;
extern int sw4_pressed;

/* --------------------------------------------- */
#endif
