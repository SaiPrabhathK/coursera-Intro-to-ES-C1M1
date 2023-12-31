/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *p****************************************************************************/
/**
 * @file stats.h
 * @brief Header file containing statistical function prototypes
 *
 * This file declares all the functions that perform statistical operations such
 * as finding median, mean, maximum, minimum and sorting the dataset.
 *
 * @author Sai Prabhath Koneru
 * @date 06/27/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Function to print statistics
 *
 * This function invokes calls to corresponding functions for finding the
 * required statistics such as the median, mean, maximum, minimum and prints the
 * values returned to the console.
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param array_size - unsigned integer as the size of the array
 *
 * @return void
 */
void print_statistics(unsigned char *array_ptr, unsigned int array_size);

/**
 * @brief Function to print the Array
 *
 * This function uses a for loop to iterate through each element in the array
 * and prints the element value to the console.
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param array_size - unsigned integer as the size of the array
 *
 * @return void
 */
void print_array(unsigned char *array_ptr, unsigned int array_size);

/**
 * @brief Function to find the median element of the array
 *
 * This function calls the sort_array() to sort the array and returns the
 * median element in the array.
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param array_size - unsigned integer as the size of the array
 *
 * @return The median of the array elements
 */
unsigned char find_median(unsigned char *array_ptr, unsigned int array_size);

/**
 * @brief Function to find the mean of the array
 *
 * This function finds the mean value of all the array elements by adding the
 * elements and dividing the sum with the size of the array.
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param array_size - unsigned integer as the size of the array
 *
 * @return The mean value of array elements
 */
unsigned int find_mean(unsigned char *array_ptr, unsigned int array_size);

/**
 * @brief Function to find the maximum element of the array
 *
 * This function returns the maximum element i.e., the first element of the
 * sorted array by the sort_array().
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param array_size - unsigned integer as the size of the array
 *
 * @return The maximum of the array elements
 */
unsigned char find_maximum(unsigned char *array_ptr, unsigned int array_size);

/**
 * @brief Function to find the minimum element of the array
 *
 * This function returns the minimum element i.e., the last element of the
 * sorted array by the sort_array().
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param array_size - unsigned integer as the size of the array
 *
 * @return The minimum of the array elements
 */
unsigned char find_minimum(unsigned char *array_ptr, unsigned int array_size);

/**
 * @brief Function to sort the elements of the array
 *
 * This function uses quick-sort sorting technique to sort the array elements
 * in decreasing order. Largest to Smallest value. The array is sorted
 * in-place
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param i - signed integer as the lowest index of an array partition
 * @param j - signed integer as the highest index of an array partition
 *
 * @return void
 */
void sort_array(unsigned char *array_ptr, int i, int j);

/**
 * @brief Function to partition the elements of the array w.r.t. pivot
 *
 * This function uses quick-sort sorting technique's partitioning algorithm to
 * partition the array based on a selected pivot element where all the
 * elements to the left of the pivot are greater than it (but not necessarily
 * sorted) and all the elements to the right of the pivot are less than it
 * (but not necessarily sorted)
 *
 * @param array_ptr - unsigned char pointer to an n-element array
 * @param l - signed integer as the lowest index of an array partition
 * @param h - signed integer as the highest index of an array partition
 *
 * @return index of the pivot element after partitioning
 */
int partition(unsigned char *array_ptr, int l, int h);

/**
 * @brief Function to swap two elements of the array
 *
 * This function swaps two elements in the array by using pointers to the
 * elements
 *
 * @param array_element_ptr_1 - unsigned char pointer to array element
 * @param array_element_ptr_1 - unsigned char pointer to array element
 *
 * @return void
 */
void swap(unsigned char *array_element_ptr_1,
	  unsigned char *array_element_ptr_2);

#endif /* __STATS_H__ */
