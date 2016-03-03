#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
LINK = g++
CFLAGS = -std=c++0x -Wall -Ofast
LFLAGS = -std=c++0x -Wall -Ofast

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: weaponTest

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
weaponTest:  procGen.o main.o 
	$(LINK) $(LFLAGS) -o PWG procGen.o main.o

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
procGen.o:  Weapons/procGen.cpp Weapons/procGen.h
	$(CC) $(CFLAGS) -c Weapons/procGen.cpp 

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
main.o:  Weapons/main.cpp Weapons/main.h
	$(CC) $(CFLAGS) -c Weapons/main.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) PWG *.o *~ Weapons/*~
