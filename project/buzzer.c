#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "stateMachines.h"

static short E4 =  303;
static short C4 = 382;
static short G_note =  255;
static short G4 = 510;


void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

char buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void mario(){
  //  static char state = 0;
  char mario[] ="ECG";
  static int i = 0;
  char length = mario[i];
  switch(length){
  case 'E':
    buzzer_set_period(E4);
    break;
  case 'C':
    buzzer_set_period(C4);
    break;
  case 'G':
    buzzer_set_period(G4);
    break;
  }
  // state_advance();
  if(i == sizeof(mario)-1){
    i = 0;
  }else{
    i++;
  }

  // buzzer_set_period(C4);
  /* while(i<sizeof(mario)){
    buzzer_set_period(mario[i]);
    state_advance();
    i++;
   }
  */
  

  
}
