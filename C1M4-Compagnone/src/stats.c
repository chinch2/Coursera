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
 * @file stats.c 
 * @brief Reads in arrays, analyses, sorts and prints data.
 *
 * <Add Extended Description Here>
 *
 * @author Diana Compagnone
 * @date May 10, 2018
 *
 */



#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

void main_stats() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_array(test, SIZE);
  print_statistics(test);
  print_array(test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics( unsigned char *array ) {
  unsigned int median;
  unsigned int mean;
  unsigned int max;
  unsigned int min;
  
  median = find_median(array);
  mean = find_mean(array);
  max = find_maximum(array);
  min = find_minimum(array);

  printf("Median: %i\n", median);
  printf("Mean: %i\n", mean);
  printf("Maximum: %i\n", max);
  printf("Minimum: %i\n", min);

}

void print_array( unsigned char *array, unsigned char size ) {
  
#ifdef VERBOSE
  unsigned char i;

  printf( "Printing array: [");
  for( i = 0; i < size; i++ ){
     printf("%i, ", array[i]);
  }
  printf( "]\n");
#endif
}

unsigned char find_mean( unsigned char *array ) {
  
  unsigned int temp = 0;

  for( int i = 0; i < SIZE; i++ ) {
    temp = temp + array[i];
  }  

  temp = temp / SIZE;

  return temp;

}

unsigned char find_median( unsigned char *array ) {
  
  sort_array(array);
  
  return array[SIZE/2];
}

unsigned char find_maximum( unsigned char *array ) {
  
  unsigned char temp = 0;

  for( int i = 0; i < SIZE; i++ ) {
    if ( array[i] > temp ) {
      temp = array[i];
    }
  }
  
  return temp;
}

unsigned char find_minimum( unsigned char *array ) {
  
  unsigned char temp = 255;

  for( int i = 0; i < SIZE; i++ ) {
    if ( array[i] < temp ) {
      temp = array[i];
    }
  }

  return temp;

}

void sort_array( unsigned char *array ) {
  unsigned char i;
  unsigned char j;

  for( i = 0; i < SIZE; i++ ) {
    for( j = 0; j < SIZE; j++ ){
      if( array[j] < array[i] ) {
        unsigned char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  
}


