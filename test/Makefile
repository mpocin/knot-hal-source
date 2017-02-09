/*
* Copyright (c) 2016, CESAR.
* All rights reserved.
*
* This software may be modified and distributed under the terms
* of the BSD license. See the LICENSE file for details.
*
*/

# Makefile to test all possible code with CPPUTest

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = hal_source_test

#--- Inputs ----#
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = knot-hal-source/

SRC_DIRS = \
	src/hal \

TEST_SRC_DIRS = \
	test/ \

INCLUDE_DIRS =\
	$(CPPUTEST_HOME)/include\
	include/ \

CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror
#CPPUTEST_CFLAGS = -std=c89
CPPUTEST_CFLAGS += -Wall -Wstrict-prototypes -pedantic
LD_LIBRARIES = -lpthread

CPPUTEST_HOME = $(HOME)/Programs/cpputest-3.8

CC      := gcc
CFLAGS    := -g -Wall
CFLAGS  += -std=c99
CFLAGS  += -D CPPUTEST            # Compile the test file, ignore the main function of sample.c, the sample.c code with the CPPUTEST macro

# CPPUTest is C++Write, so using g++ To compile the test file
CPP     := g++
CPPFLAGS  := -g -Wall
CPPFLAGS  += -I$(CPPUTEST_HOME)/include
LDFLAGS := -L$(CPPUTEST_HOME)/lib -lCppUTest

# A memory leak detection
MEMFLAGS = -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

#sample: sample.o

#sample.o: sample.h sample.c
#	$(CC) -c -o sample.o sample.c $(CFLAGS) $(MEMFLAGS)

# Additional compiled test program
test: comm_avr_test.o
	$(CPP) -o $@ comm_avr_test.o $(LDFLAGS)

test.o: comm_avr_test.cpp
	$(CPP) -c -o comm_avr_test.o comm_avr_test.cpp $(CPPFLAGS)  $(MEMFLAGS)

.PHONY: clean
clean:
	@echo "clean..."
	rm -f test
	rm -f test.o comm_avr_test.o
