/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */

#include <CppUTest/TestHarness.h>
#include "all_tests.cpp"

//START: testGroup
TEST_GROUP(FirstTestGroup)
{
        // initial setup
        void setup()
        {
                memset(output, 0xaa, sizeof output);
                expected = "";
        }

        // cleanup
        void teardown()
        {

        }

        // helper functions accessible to all test() cases in testGroup
};
//END: testGroup

// All keys are loaded

// MAC address do not exist on thing

// Gateway key do not exist on thing

// Size of MAC address is wrong

// Size of gateway key is wrong

// There is no MAC address on eeprom

// There is no keys on eeprom

TEST(FirstTestGroup, FirstTest)
{
   FAIL("Fail me!");
}

TEST(FirstTestGroup, SecondTest)
{
   STRCMP_EQUAL("hello", "world");
   LONGS_EQUAL(1, 2);
   CHECK(false);
}
