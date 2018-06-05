/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c 
 * @brief Reads in arrays, analyses, sorts and prints data.
 *
 * <Add Extended Description Here>
 *
 * @author Diana Compagnone
 * @date June 3, 2018
 *
 */

#include "data.h"
#include "memory.h"
#include <stdio.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  
  uint32_t i = data;
  uint8_t count;
  int8_t sign = 1;
  int32_t remainder;

  if (base == 16) {
    printf("i: %i\n", i);
    while (i != 0) {
      i /= 0x10;
      count++;
    }
  }

  if (base == 10) {
    if (data < 0) {
      sign = -1;
    }
    while (i != 0) {
      i /= 10;
      count++;
    }
  }

  while (data != 0) {
    remainder = data % base;
    *ptr = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
    data = data/base;
    ptr++;
  }

  if (sign == -1) {
    *ptr = '-';
    ptr++;
  }

  *ptr = '\0';

  my_reverse (ptr, count);

  printf("number of digits: %i\n", count);
  return count;
}

int32_t my_atoi(uint8_t * ptr,  uint8_t digits, uint32_t base) {
  int8_t converted;
  uint8_t i;
  int8_t sign = 1;

  if (*ptr == '-') {
    sign = -1;
    ptr++;
  }

  if (base == 16) {
    for (i = 0; *ptr != '\0'; ++i) {
      converted = converted * 0x10 + *ptr - '0';
      ptr++;
    }
  }

  if  (base == 10) {
    for (i = 0; *ptr != '\0'; i++) {
      converted = converted * 10 + *ptr - '0';
      ptr++;
    }
  }


  return sign*converted;
}


