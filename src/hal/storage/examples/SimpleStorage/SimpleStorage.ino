/*
 * Copyright (c) 2017, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */

#include "KNoTThing.h"
#include "hal/storage.h"

static char str[] = "Value that is stored in the EEPROM";
static char vector[50];
static int bytes_read;

void setup()
{
	Serial.begin(9600);
	while(!Serial) {;}
}

void loop()
{
	// record string in EEPROM
	hal_storage_write(0, str, sizeof(str));

	delay(100);

	// read the EEPROM and return the number of bytes read
	bytes_read = hal_storage_read(0, vector, sizeof(str));

	Serial.println(vector);
	Serial.println(bytes_read);

	while(true);
}
