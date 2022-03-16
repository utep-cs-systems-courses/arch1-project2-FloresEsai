#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
    
    int period = 0;
    
    
    
    buzzer_init();
    buzzer_set_period(period); /* start buzzing!! 2MHz/1000 = 2kHz*/

    
    or_sr(0x18);          // CPU off, GIE on
}
