#include <msp430.h>
#include "ports.h"
#include <stdio.h>

void blink(void);
void isPressed(void);
void setup(void);

//This starts the timer interrupts for blinking the led.
__attribute__((interrupt(TIMER0_A0_VECTOR))) void Timer_A(void) {
  blink();
}
//__attribute__((interrupt(PORT1_VECTOR))) void Port_1(void) {
//  s = RGR;
//  period = REDANDGREEN;
//}
int main(void){
  setup();
  while(1);
  for(;;) {
    volatile unsigned int i;    //volatile to prevent optimization
  }
  return 0;
}
