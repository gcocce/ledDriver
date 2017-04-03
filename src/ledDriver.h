/****************************************************************************
 * Copyright (C) 2012 by Gaston Cocce                                       *
 *                                                                          *
 * Este archivo es parte del trabajo práctico para Ing de Software          *
 *                                                                          *
 ****************************************************************************/

/**
 * @file ledDriver.h
 * @author Gastón Coccé
 * @date 3 Apr 2017
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief A simple function to create the Driver.
 *
 * @param address Es la dirección de memoria que mapea el driver
 *
 * @return void is always returned.
 */
void ledDriver_create(uint16_t * address);

/**
 * @brief A simple function to turn on a specific led.
 *
 * @return Void is always returned.
 */
void ledDriver_TurnLedOn(uint16_t * address /*! Address of the driver */,
		uint16_t led /*! The led to turn on */);

/*! \details This function turns off a specific led.
  *\param address is the driver's address.
 *\param led is the a 16 bits mask indicating the led to turn off
 * \return Void.
 */
void ledDriver_TurnLedOff(uint16_t *, uint16_t led);

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  \sa ledDriver_TurnAllOff()
 *
 *  @param address es la direccion de memoria que mapea el driver
 *
 *  Detailed description starts here.
 */
void ledDriver_TurnAllOn(uint16_t *address);

//! @brief A simple function to turn All Leds Off.
/*!
  \sa ledDriver_TurnAllOn()
  \param address is the driver's address.
*/
void ledDriver_TurnAllOff(uint16_t * address);

/**
 * @brief A simple function to create the Driver.
 *
 * @param address Es la dirección de memoria que mapea el driver
 *
 * @return void is always returned.
 */
bool ledDriver_LedStatus(uint16_t *, uint16_t led);

void ledDriver_TurnMultipleLedOn(uint16_t *, uint16_t led);

void ledDriver_TurnMultipleLedOff(uint16_t *, uint16_t led);
