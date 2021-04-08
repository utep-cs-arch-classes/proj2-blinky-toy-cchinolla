#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.c"

char state;
char SW1down;
char SW2down;
char SW3down;
char SW4down;
char switch_state;
char switch_state_changed;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  //updare switch interrupt to detect changes from current buttons
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2vval |= ~SWITCHES);
  return p2val;
}

void switch_init(){
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_ipdate_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  if(p2val & SW! ? 0 : 1){
    state = 1;
  }else if(p2val & SW2 ? 0: 1){
    state = 2;
  }else if(p2val & SW3 ? 0: 1){
    state = 3;
  }else if(p2val & SW4 ? 0: 1){
    state = 4;
  }
  state_advance();
}
