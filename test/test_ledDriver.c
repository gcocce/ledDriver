
#include "unity.h"
#include "ledDriver.h"

uint16_t address;

void setUp() {

}

void tearDown() {
	address = 0;
}

void testDriverCreateDebeApagarTodosLosLeds() {

	address = 0xFFFF;
	ledDriver_create(&address);

	TEST_ASSERT_EQUAL_HEX16(0, address);
}