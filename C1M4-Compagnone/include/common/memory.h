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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves values in memory based on length
 *
 * Takes two byte pointers (once source, one destination) and a lengh
 * of bytes to move from the source location to the destination. Behaviour
 * should handle overlap of source and destination. Copy should occur, 
 * with no data corruption. All operations need to be performed using 
 * pointer arithmetic, not array indexing. Should return a pointer to 
 * the destination. 
 *
 * @param src Pointer to source memory
 * @param dst Pointer to destination memory
 * @param length Length of bytes to copy
 *
 * @return dst Pointer to destination data.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy values in memory based on length
 *
 * Takes two byte pointers (once source, one destination) and a lengh
 * of bytes to move from the source location to the destination. Behaviour
 * is undefined if there is overlap of source and destination. Copy should 
 * occur, with data corruption. All operations need to be performed using 
 * pointer arithmetic, not array indexing. Should return a pointer to 
 * the destination. 
 *
 * @param src Pointer to source memory
 * @param dst Pointer to destination memory
 * @param length Length of bytes to copy
 *
 * @return dst Pointer to destination data.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a location in memory to a given value.
 *
 * Takes a pointer to a source memory location, a length in bytes and set
 * all locations of that memory to a given value. All operations need to 
 * be performed using pointer arithmetic, not array indexing.  Should 
 * return a pointer to the source. Should NOT reuse the set_all() function. 
 *
 * @param src Pointer to source memory
 * @param length Length of bytes to copy
 * @param value Value to set memory
 *
 * @return src Pointer to source data.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a location in memory to zero.
 *
 * Takes a pointer to a source memory location, a length in bytes and zero
 * out all of the memory. All operations need to be performed using pointer 
 * arithmetic, not array indexing.  Should return a pointer to the source. 
 * Should NOT reuse the clear_all() function. 
 *
 * @param src Pointer to source memory
 * @param length Length of bytes to copy
 *
 * @return src Pointer to source data.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the bytes in memory of a given source.
 *
 * Takes a pointer to a source memory location, a length in bytes and reverse
 * order of all the bytes. All operations need to be performed using pointer 
 * arithmetic, not array indexing.  Should return a pointer to the source. 
 *
 * @param src Pointer to source memory
 * @param length Length of bytes to copy
 *
 * @return src Pointer to source data.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserves a number of wordes in dynamic memory.
 *
 * Takes number of words to allocate in dynamic memory. All operations 
 * need to be performed using pointer arithmetic, not array indexing.  
 * Should return a pointer to memory if successful, or a null pointer if not.
 *
 * @param length Length of bytes to copy
 *
 * @return src Pointer to memory if successful, null pointer if not.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamic memory.
 *
 * Should free a dynamic memory allocation by providing the pointer src to
 * the function. All operations need to be performed using pointer arithmetic,
 * not array indexing. 
 *
 * @param src Pointer to source
 *
 * @return null
 */
void free_words(uint32_t * src);


#endif /* __MEMORY_H__ */
