/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */

 /* TODO: return RUN_ALL_TESTS(argc, argv); */
#include <CppUTest/CommandLineTestRunner.h>

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}
