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
 * @file stats.h 
 * @brief Declarations and documentation for stats functions
 *
 * @author Diana Compagnone
 * @date May 10, 2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints out statistics on data array
 *
 * Prints statistics of data array including minimum, maximum, mean, and median.
 *
 * @param array The array to be analyzed
 *
 * @return none
 */
void print_statistics();

/**
 * @brief Prints array to the screen
 *
 * Given an array of data and length, prints the array to the screen
 *
 * @param array The array to be printed
 *
 * @return <Add Return Informaiton here>
 */
void print_array( unsigned char *array );

/**
 * @brief Finds median of array
 *
 * Returns mean of all elements in array
 *
 * @param array The array to find the median
 *
 * @return The median of array
 */
unsigned int find_median( unsigned char *array );

/**
 * @brief Finds mean of array
 *
 * Returns mean of all elements in array
 *
 * @param array The array to find mean
 *
 * @return The mean of array
 */
unsigned int find_mean( unsigned char *array );

/**
 * @brief Finds maximum of array
 *
 * Returns maximum value of all elements in array
 *
 * @param array	The array to find the maximum
 *
 * @return The maximum of array
 */
unsigned int find_maximum( unsigned char *array );

/**
 * @brief Finds minimum of array
 *
 * Returns minimum value of all elements in arrray
 *
 * @param array The array to find the maximum
 *
 * @return The minimum of array
 */
unsigned int find_minimum( unsigned char *array );

/**
 * @brief Sorts array from largest to smallest
 *
 * Given an array of data and a length, sorts array from largest to smallest.
 * Element 0 is largest value, last elemenet is smallest value
 *
 * @param array The array to sort
 *
 * @return The sorted array
 */
unsigned char[] sort_array( unsigned char *array );

#endif /* __STATS_H__ */
