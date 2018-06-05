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
 * @file data.h 
 * @brief Declarations and documentation for stats functions
 *
 * @author Diana Compagnone
 * @date June 3, 2018
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>

#define BASE_2     (2)
#define BASE_8     (8)
#define BASE_10   (10)
#define BASE_16   (16)

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Converts data from a standard integer type to an ASCII string.
 *
 * Converts data from a standard interger type to an ASCII string. All operations need to be
 * performed using pointer arithmetic, not array indexing. The number you with to convert
 * is passed in as a signed 32-bit integer. Should be able to support bases 2 to 16 by
 * specifying the interger value to the base you with to convert to. Copy the converted
 * character string to the uint8_t* pointer passed in as a parameter. The signed 32-bit
 * number will have a maximum string size. You must place a null terminator at the end of the
 * converted c-string. Function should return the length of the converted data including
 * the negative sign. Example: my_itoa(ptr, 1234, 10) should return an ASCII string length of 5.
 * This function needs to handle signed data. You may not use any string functions or libraries.
 *
 * @param data Number to convert to ASCII
 * @param ptr Pointer to store converted ASCII data
 * @param base Base of the input number
 *
 * @return converted Converted ASCII string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Prints array to the screen
 *
 * Converts data from an ASCII string to a standard integer type. All operations need to be
 * performed using pointer arithmetic, not array indexing. The character string to convert
 * is passed in as a uint8_t* pointer. The number of digits in your character set is passed 
 * in as a uint8_t integer. You should be able to support bases 2 to 16. The converted 32-bit
 * signed integer should be returned. This function needs to handle signed data. You may not 
 * uses any string functions or libraries.
 *
 * @param ptr ASCII string to convert to an integer
 * @param digits Number of digits to convert to
 * @param base Base to convert to
 *
 * @return converted Converted 32-bit integer
 */
int32_t my_atoi(uint8_t * ptr,  uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
