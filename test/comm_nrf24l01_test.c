/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */

#include <CppUTest/TestHarness.h>

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
        FAIL("Fail me!");
}
