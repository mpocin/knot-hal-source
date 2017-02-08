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
#include "include/comm.h"
#include "all_tests.cpp"

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
TEST(comm_nrf24l01, all_keys_loaded)
{
        uint64_t addr = 0x1122334455667788;
        uint8_t key[] = {
                0x06, 0xE6, 0x9C, 0xFE, 0x72, 0x2A, 0xAC, 0x71, 0x55, 0xA3, 0x4A,
                 0x9A, 0xD1, 0x6B, 0x21, 0xA7, 0x51, 0xCC, 0xE8, 0xA0, 0x5C, 0x65,
                  0xC2, 0xA8, 0x77, 0xDD, 0x9D, 0x4C, 0x3D, 0xDC, 0x7A, 0x03, 0x84,
                   0x7E, 0x37, 0xC3, 0x08, 0x70, 0x17, 0xDB, 0xCD, 0xF1, 0x31, 0xD0,
                    0x79, 0xEF, 0x2E, 0xB0, 0xF2, 0x09, 0xBA, 0xDF, 0x57, 0xE8, 0xA5,
                     0x3D, 0x47, 0xE1, 0x1D, 0x42, 0x1B, 0x32, 0x3F, 0x96
             };

        LONGS_EQUAL(0, hal_comm_load_keys(addr, key));
}

// MAC address do not exist on thing

// Gateway key do not exist on thing

// Size of MAC address is wrong

// Size of gateway key is wrong

// There is no MAC address on eeprom

// There is no keys on eeprom
