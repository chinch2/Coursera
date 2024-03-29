#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

# Add your Source files to this variable
# The list of source files that will need to be compiled (Platform Specific)
ifeq ($(PLATFORM),HOST)
  SOURCES =                 \
  	./src/main.c        \
  	./src/memory.c      \
        ./src/course1.c     \
        ./src/data.c        \
        ./src/stats.c
endif	
ifeq ($(PLATFORM),MSP432)
  SOURCES =		\
  	./src/course1.c \
        ./src/data.c    \
        ./src/main.c	\
  	./src/memory.c	\
        ./src/stats.c   \
	./src/interrupts_msp432p401r_gcc.c	\
	./src/startup_msp432p401r_gcc.c	        \
	./src/system_msp432p401r.c
endif

# Add your include paths to this variable
# The list of include directories (Hing: Use the -I flag)
ifeq ($(PLATFORM),MSP432)
  INCLUDES =                   \
	-I./include/msp432/   \
	-I./include/common/   \
	-I./include/CMSIS/
endif
ifeq ($(PLATFORM),HOST)
  INCLUDES = -I./include/common/
endif

