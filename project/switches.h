#ifndef switches_included
#define switches_included

#define SW1 BIT0 //SWITCH1 IS P2.0
#define SW2 BIT1//SWITCH2 IS P2.1
#define SW3 BIT2//SWITCH3 IS P2.2
#define SW4 BIT3//switch4 is p2.3
#define SWITCES (SW1 | SW2 | SW3 | SW4)//four switches

void switch_init();
void switch_interrupt_handler();

extern char button_state, state;

#endif//included
