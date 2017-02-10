#
# Copyright (c) 2016, CESAR.
# All rights reserved.
#
# This software may be modified and distributed under the terms
# of the BSD license. See the LICENSE file for details.
#
#

# Makefile to test all possible code with CPPUTest

CPPUTEST_HOME = $(HOME)/Programs/cpputest-3.8

#Set this to @ to keep the makefile quiet
SILENCE = @

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

#SRC_DIRS = \
	include/* \
	src/* \

#TEST_DIRS = \
	test/* \

#INCLUDE_DIRS = \
	$(CPPUTEST_HOME)/include \
	$(SRC_DIRS) \
	$(TEST_DIRS) \

#INCLUDES += $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

CPP_FILE_DIR = test/hal/
CPP_FILE = comm_avr_test

#sample: sample.o

#sample.o: sample.h sample.c
#	$(CC) -c -o sample.o sample.c $(CFLAGS) $(MEMFLAGS)

# Additional compiled test program
test: $(CPP_FILE).o
	$(CPP) -o $@ $(CPP_FILE).o $(LDFLAGS)

test.o: $(CPP_FILE).cpp
	$(CPP) -c -o $(CPP_FILE).o $(CPP_FILE).cpp $(CPPFLAGS) $(MEMFLAGS)

.PHONY: clean
clean:
	@echo "clean..."
	rm -f test
	rm -f test.o $(CPP_FILE).o
