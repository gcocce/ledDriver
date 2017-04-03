/****************************************************************************
 * Copyright (C) 2012 by Matteo Franchin                                    *
 *                                                                          *
 * This file is part of Box.                                                *
 *                                                                          *
 *   Box is free software: you can redistribute it and/or modify it         *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

/**
 * @file ledDriver.h
 * @author Gastón Coccé
 * @date 3 March 2017
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
 *
 * @return @c Void is always returned.
 */
void ledDriver_create(uint16_t * address);

/**
 * @brief A simple function to turn on a specific led.
 *
 *
 * @return @c Void is always returned.
 */
void ledDriver_TurnLedOn(uint16_t * address /*! Address of the driver */,
		uint16_t led /*! The led to turn on */);

/*! \details This function turns off a specific led.
  *\param address is the driver's address.
 *\param led is the a 16 bits mask indicating the led to turn offc*
 * \return Void.
 */
void ledDriver_TurnLedOff(uint16_t *, uint16_t led);

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
void ledDriver_TurnAllOn(uint16_t *);

//! @brief A simple function to turn All Leds Off.
/*!
  \sa testMe()
  \param address is the driver's address.
*/
void ledDriver_TurnAllOff(uint16_t * address);

bool ledDriver_LedStatus(uint16_t *, uint16_t led);

void ledDriver_TurnMultipleLedOn(uint16_t *, uint16_t led);

void ledDriver_TurnMultipleLedOff(uint16_t *, uint16_t led);
