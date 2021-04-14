#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
//#include <libTimer.h>
#include "buzzer.h"





char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  static char state = 0;

  switch(state){
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  
  return 1;
}


char toggle_both(){
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    green_on = 0;
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 0;
    break;
  }
  return 1;
}

char turn_off(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  return 1;
}

void dim25(){
  char changed_led = 0;
  static char dimState = 0;
  switch(dimState){
  case 0:
    red_on = 1;
    dimState = 1;
    break;
  case 1:
    red_on = 0;
    dimState = 2;
    break;
  case 2:
    red_on = 0;
    dimState = 3;
    break;
  case 3:
    red_on = 0;
    dimState = 0;
    break;
  }
  changed_led = 1;
  led_update();
}

void dim50(){
  char changed_led = 0;
  static char dimState = 0;
  switch(dimState){
  case 0:
    red_on = 1;
    dimState = 1;
    break;
  case 1:
    red_on = 0;
    dimState = 2;
    break;
  case 2:
    red_on = 1;
    dimState = 3;
    break;
  case 3:
    red_on = 0;
    dimState = 0;
    break;
  }
  changed_led = 1;
  led_update();
}

void dim75(){
  char changed_led = 0;
  static char dimState = 0;
  switch(dimState){
  case 0:
    red_on = 1;
    dimState = 1;
    break;
  case 1:
    red_on = 0;
    dimState = 2;
    break;
  case 2:
    red_on = 1;
    dimState = 3;
    break;
  case 3:
    red_on = 1;
    dimState = 0;
    break;
  }
  changed_led = 1;
  led_update();
}

dim(){
  static char dimS = 0;
  switch(dimS){
  case 0:
    dim25();
    dimS = 1;
    break;
  case 1:
    dim50();
    dimS = 2;
    break;
  case 2:
    dim75();
    dimS = 0;
    break;
  }
}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;
  switch(state){
  case 1:
    changed = toggle_red(); break;
  case 2:
    changed = toggle_green(); break;
  case 3:
    changed = toggle_both();
    mario();
    break;
  case 4:
    changed = turn_off();
    buzzer_set_period(0);
    break;
  }
  led_changed = changed;
  led_update();
}



