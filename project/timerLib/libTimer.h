#ifndef libTimer_included
#define libTimer_included

void configureClocks();
void enableWDRInterrupts();
void timerAUpmode();

unsigned char gert_sr();
void set_sr(), or_sr(), and_sr();

#endif
