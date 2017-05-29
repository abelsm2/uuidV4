/**
 * Version 4 UUID Generator by Micah L. Abelson
 *
 * @author Micah Abelson
 * @date May 20, 2017
 *
 * MIT License
 *
 * Copyright (c) 2017 Micah L. Abelson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

// This will load the definition for common Particle variable types
#include "Particle.h"

#ifndef uuidV4_h
#define uuidV4_h

#include "Particle.h"

namespace uuid {

	/**
	 * The procedure to generate a version 4 UUID
	 *
	 * REFERENCE: RFC 4122, A Universally Unique IDentifier (UUID) URN, IETF, July 2005.
	 *
	 * @param uuid char[37] array to store formatted UUID string
	 *
	 * @note This is not a class so you do not need to create an instance.  Simply call it from within
	 *       any application that includes it.
	 */
	inline void generateUuidV4 (char uuid[]) {

		uint8_t bytes[16] = {0};

		// Generate 16 random bytes
		for (auto& val: bytes) val = HAL_RNG_GetRandomNumber() % 256;

		// Adjust certain bits according to RFC 4122 section 4.4 as follows:
		// set the four MSB of the 7th byte to 0100b so the high nibble is "4"
		bytes[6] = 0x40 | (bytes[6] & 0x0F);

		// set the two MSB of the 9th byte to 10b so the high nibble will be one of '8', '9', 'A', or 'B'.
		bytes[8] = 0x80 | (bytes[8] & 0x3F);

		// Convert the adjusted bytes to 32 hexadecimal digits
		// Output the resulting 36-character string "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX"

		sprintf (uuid, "%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X",
				bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7],
				bytes[8], bytes[9], bytes[10],bytes[11],bytes[12],bytes[13],bytes[14],bytes[15]);
	}
}
#endif