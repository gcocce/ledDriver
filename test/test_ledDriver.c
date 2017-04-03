
#include "unity.h"
#include "ledDriver.h"
#include "defines.h"

uint16_t address;

void setUp() {

}

void tearDown() {
	address = 0;
}

// Test 1
void testDriverCreateDebeApagarTodosLosLeds() {

	address = 0xFFFF;
	ledDriver_create(&address);

	TEST_ASSERT_EQUAL_HEX16(0, address);
}

// Test 2
void testDriverTurnLedOnChangeOneAtATime() {

	// Inicialmente todos apagados y se prende un led
	address = ALL_LEDS_OFF;
	ledDriver_TurnLedOn(&address, LED_1);
	TEST_ASSERT_EQUAL_HEX16(LED_1, address);

	address = ALL_LEDS_OFF;
	ledDriver_TurnLedOn(&address, LED_9);
	TEST_ASSERT_EQUAL_HEX16(LED_9, address);

	address = ALL_LEDS_OFF;
	ledDriver_TurnLedOn(&address, LED_16);
	TEST_ASSERT_EQUAL_HEX16(LED_16, address);

	// Varios leds prendidos inicialmente y se prende otro led
	address = LED_1 | LED_5 | LED_15;
	ledDriver_TurnLedOn(&address, LED_6);
	TEST_ASSERT_EQUAL_HEX16(LED_1 | LED_5 | LED_15 | LED_6, address);
}

// Test 3
void testDriverTurnLedOffChangeOneAtATime() {

	// Todos prendidos inicialmente y se apaga un led
	address = ALL_LEDS_ON;
	ledDriver_TurnLedOff(&address, LED_1);
	TEST_ASSERT_EQUAL_HEX16(LED_1 ^ ALL_LEDS_ON, address);

	address = ALL_LEDS_ON;
	ledDriver_TurnLedOff(&address, LED_16);
	TEST_ASSERT_EQUAL_HEX16(LED_16 ^ ALL_LEDS_ON, address);

	address = ALL_LEDS_OFF;
	ledDriver_TurnLedOff(&address, LED_4);
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, address);

	// Varios leds prendidos inicialmente y se apaga uno de esos leds
	address = LED_1 | LED_5 | LED_15;
	ledDriver_TurnLedOff(&address, LED_5);
	TEST_ASSERT_EQUAL_HEX16(LED_1 | LED_15, address);
}

// Test 4
void testDriverTurnMultipleLedOnOffAtATime() {

	// Inicialmente todos apagados y se prende un grupo de leds
	address = ALL_LEDS_OFF;
	ledDriver_TurnMultipleLedOn(&address, LED_1 | LED_5 | LED_15);
	TEST_ASSERT_EQUAL_HEX16(LED_1 | LED_5 | LED_15, address);

	// Todos prendidos inicialmente y se apaga un grupo led
	address = ALL_LEDS_ON;
	ledDriver_TurnMultipleLedOff(&address, LED_1 | LED_5 | LED_15);
	TEST_ASSERT_EQUAL_HEX16((LED_1 | LED_5 | LED_15) ^ ALL_LEDS_ON, address);
}

// Test 5
void testDriverTurnAllOff() {

	// Todos prendidos inicialmente y se apagan todos
	address = ALL_LEDS_ON;
	ledDriver_TurnAllOff(&address);
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, address);

	// Varios leds prendidos inicialmente y se apagan todos
	address = LED_1 | LED_5 | LED_15;
	ledDriver_TurnAllOff(&address);
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, address);
}

// Test 6
void testDriverTurnAllOn() {

	// Inicialmente todos apagados y se prende todos los leds
	address = ALL_LEDS_OFF;
	ledDriver_TurnAllOn(&address);
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON, address);

	// Inicialmente algunos prendidos y prende los leds
	address = LED_1 | LED_5 | LED_15;
	ledDriver_TurnAllOn(&address);
	TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON, address);
}

// Test 7
void testDriverGetLedStatus() {

	// Todos prendidos inicialmente y se apagan todos
	address = LED_1 | LED_5 | LED_15;;
	bool status=ledDriver_LedStatus(&address, LED_5);
	TEST_ASSERT_EQUAL_UINT(status, true);


	address = LED_1 | LED_5 | LED_15;;
	status=ledDriver_LedStatus(&address, LED_4);
	TEST_ASSERT_EQUAL_UINT(status, false);

}



