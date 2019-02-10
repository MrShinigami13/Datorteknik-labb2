#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int getsw(void){
	int switches = PORTD;
	switches = switches >> 8;
	switches &= 0xf;
	return switches;
}

int getbtns(void){
	int buttons = PORTD;
	buttons = buttons >> 5;
	buttons &= 0x7;
	return buttons;
}


