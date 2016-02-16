#include <msp430.h>
#include "ports.h"

typedef enum {
               R,      //RED LIGTH ON
               RGR,    //RED AND GREEN BLINKING
               G,      //GREEN LIGHT ON
               GRG     //RED AND GREEN BLINKING
}state;

static state s = RGR;
static int period = REDANDGREEN;
int isPressed();

void blink(void){
      {
        switch(s)
          {
          case R:
            if(isPressed()) period = 0;
            if (period >0){
              P1OUT &= LED1;
              P1OUT &= ~LED2;
              period--;
            }
            else{
              period = REDANDGREEN;
              s = RGR;
            }
            break;

          case RGR:
            if (period >0){
              P1OUT |= LED1;
              P1OUT |= LED2;
              period--;
            }
            else{
              period = GREENTIME;
              s = G;
            }
           break;

           case G:

              if (period >0){
                P1OUT &= ~LED1;				// Toggle P1.0 using exclusive-OR
                P1OUT &= LED2;
                period--;
              }
              else{
                period = REDANDGREEN;
                s = GRG;
              }
           break;

           case GRG:
              if (period >0){
                P1OUT |= LED1;
                P1OUT |= LED2;
                period--;
                }
              else{
                period = REDTIME;
                s = R;
            }
           break;
    }
  }
}


//P1OUT ^= (LED1 | LED2);				// Toggle P1.0 using exclusive-OR
