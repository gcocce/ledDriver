/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */

#include "ledDriver.h"

void ledDriver_create(uint16_t *address) {
	*address = 0;
}

void ledDriver_TurnLedOn(uint16_t *address, uint16_t led){

	*address=*address|led;
}

void ledDriver_TurnLedOff(uint16_t *address, uint16_t led){

	uint16_t mascara = 0xffff ^ led;

	*address=*address &  mascara;
}

void ledDriver_TurnMultipleLedOn(uint16_t *address, uint16_t led){
	*address=*address|led;
}

void ledDriver_TurnMultipleLedOff(uint16_t *address, uint16_t led){
	uint16_t mascara = 0xffff ^ led;

	*address=*address &  mascara;
}

void ledDriver_TurnAllOn(uint16_t *address){
	*address=0xffff;
}

void ledDriver_TurnAllOff(uint16_t *address){
	*address=0x0000;
}

bool ledDriver_LedStatus(uint16_t *address, uint16_t led){

	uint16_t res= *address & led;

	if (res){
		return true;
	}else{
		return false;
	}
}
