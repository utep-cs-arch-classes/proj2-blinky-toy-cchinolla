#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
     if(state == 3 && ++blink_count == 1){
       state_advance();
       // dim();
       blink_count = 0;
     }else if(++blink_count == 250){
       state_advance();
       blink_count = 0;
     }

  
    
}
