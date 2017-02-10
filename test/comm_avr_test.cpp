/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */

#include <CppUTest/TestHarness.h>
#include <stdio.h>

/*
extern "C"
{
        #include "comm.h"
}*/

TEST_GROUP(comm_nrf24l01)
{
        void setup()
        {
                printf("Testing... \n");
        }

        void teardown()
        {
                printf("Finished");
        }
};

// All keys are loaded

// MAC address do not exist on thing

// Gateway key do not exist on thing

// Size of MAC address is wrong

// Size of gateway key is wrong

// There is no MAC address on eeprom

// There is no keys on eeprom
