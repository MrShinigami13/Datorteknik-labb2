/* mipslabwork.c

   This file written 2015 by F Lundevall

   This file should be changed by YOU! So add something here:

   This file modified 2015-12-24 by Ture Teknolog 

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

volatile int* trise = (volatile int*) 0xbf886100;
volatile int* porte = (volatile int *) 0xbf886110;

#define TMR2PERIOD ((80000000 / 64) / 100)

int prime = 1234567;
int mytime = 0x5957;
int timeoutcount = 0;
char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
	if (IFS(0) & 0x100){
		if (timeoutcount == 100){
			timeoutcount = 0;
			time2string(textstring, mytime);
			display_string(3, textstring);
			display_update();
			tick(&mytime);
		}
		timeoutcount++;
		IFS(0) &= 0x100;
	}
}

/* Lab-specific initialization goes here */
void labinit( void )
{
	*porte = *porte & 0x0;
	*trise = *trise & 0x200;
	PORTD |= 0xfe0;
	
	IPC(1) = 0x1c000000;			// external interrupt 1
	IPC(2) = 0x1c000000;			// external interrupt 2
	IPC(3) = 0x1c000000;			// external interrupt 3
	IPC(4) = 0x1c000000;			// external interrupt 4
	
	T2CON = 0x0;
	TMR2 = 0x0;
	PR2 = TMR2PERIOD;
	//PR2 = 0x30d4;
	T2CONSET = 0x8000;
	
	IPC(2) = 0x1c;
	IEC(0) = 0x8100;
	//IEC(0) = 0x88980; // för interrupts sw1-4 och timer2
	enable_interrupt();
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
	prime = nextprime(prime);
	display_string(0, itoaconv(prime));
	display_update();
  /*delay( 1000 );
  if (IFS(0) & 0x100){
	  if(timeoutcount == 1000){
		  timeoutcount = 0;
		time2string( textstring, mytime );
		display_string( 3, textstring );
		display_update();
		tick( &mytime );
	  }
	timeoutcount++;
	IFS(0) &= ~0x100;
  }
  int btns = getbtns();
  if(btns != 0){
	  int sw = getsw();
	  int toadd = sw;
	  int toadd2 = sw;
	  int toadd3 = sw;
	  switch(btns){
		  case 4 :
			toadd = toadd << 12;
			toadd &= 0xffff;
			mytime &= 0x0fff;
			mytime |= toadd;
			break;
		
		case 2 :
			toadd = toadd << 8;
			toadd &= 0xffff;
			mytime &= 0xf0ff;
			mytime |= toadd;
			break;
		
		case 1 : 
			toadd = toadd << 4;
			toadd &= 0xffff;
			mytime &= 0xff0f;
			mytime |= toadd;
			break;
			
		case 3 :
			toadd2 = toadd2 << 4;
			toadd = toadd << 8;
			toadd |= toadd2;
			toadd &= 0xffff;
			mytime &= 0xf00f;
			mytime |= toadd;
			break;
			
		case 5 :
			toadd2 = toadd2 << 8;
			toadd = toadd << 12;
			toadd |= toadd2;
			toadd &= 0xffff;
			mytime &= 0x0f0f;
			mytime |= toadd;
			break;
		
		case 6 :
			toadd2 = toadd2 << 8;
			toadd = toadd << 12;
			toadd |= toadd2;
			toadd &= 0xffff;
			mytime &= 0x00ff;
			mytime |= toadd;
			break;
			
		case 7 : 
			toadd3 = toadd3 << 4;
			toadd2 = toadd2 << 8;
			toadd = toadd << 12;
			toadd |= toadd2;
			toadd |= toadd3;
			toadd &= 0xffff;
			mytime &= 0x000f;
			mytime |= toadd;
			break;
	  }
  }
  *porte = *porte + 1; 
  display_image(96, icon);*/
}
