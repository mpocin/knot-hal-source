/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */

#include <vector>
#include <CppUTest/CommandLineTestRunner.h>

/*
int main(int argc, char** argv)
{
    std::vector<const char*> args(argv, argv + argc);
    args.push_back("-v"); // Verbose output
    args.push_back("-c"); // Colored output

    return RUN_ALL_TESTS(args.size(), &args[0]);
}*/

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}
