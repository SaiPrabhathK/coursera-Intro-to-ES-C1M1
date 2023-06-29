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
 * @brief Implementation file for performing statistical analysis
 *
 * This file contains C source code for performing statistical analytics such as
 * finding median, mean, maximum & minimum values and sorting given dataset in
 * decreasing order. It contains various function definitions for performing
 * these operations.
 *
 * @author Sai Prabhath Koneru
 * @date 06/27/2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);
  
  return;

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char *array_ptr, unsigned int array_size) {

  unsigned char median, mean, max,  min =  0;

  median = find_median(array_ptr, SIZE);
  mean = find_mean(array_ptr, SIZE);
  max = find_maximum(array_ptr, SIZE);
  min = find_minimum(array_ptr, SIZE);
  printf("\n\t Statistical Analysis of the Given Data\n");
  printf("\t --------------------------------------\n");
  printf("\n\t Median\t Mean\t Maximum\t Minimum\n");
  printf("\t %d\t %d\t %d\t\t %d\n", median, mean, max, min);
  printf("\n\t The Sorted Dataset:\n");
  
  print_array(array_ptr, array_size);

  return;
}

void print_array(unsigned char *array_ptr, unsigned int array_size) {

  printf("\t[");
  for(unsigned int i = 1; i <= SIZE; i++) {
    printf(" %hhu,", array_ptr[i - 1]);
    if ((i % 8 == 0) && (i < 40)) {
      printf("\n\t");
    }
  }
  printf(" \b\b ]\n\n");

  return;
}

unsigned char find_median(unsigned char *array_ptr, unsigned int array_size) {

  unsigned char median = 0;
  // finding the middle index of array
  int mid = array_size / 2;
  
  sort_array(array_ptr, 0, array_size - 1);
  if(array_size % 2 == 0) {
    median = (array_ptr[mid - 1] + array_ptr[mid]) / 2;
  }
  else {
    median = array_ptr[mid];
  }

  return median;
}

unsigned int find_mean(unsigned char *array_ptr, unsigned int array_size) {

  unsigned int array_sum = 0;

  for(unsigned int i = 0; i < array_size; i++) {
    array_sum += array_ptr[i];
  }

  return (array_sum / array_size);
}

// The array is already sorted in decreasing order
unsigned char find_maximum(unsigned char *array_ptr, unsigned int array_size) {

  return array_ptr[0];
}

unsigned char find_minimum(unsigned char *array_ptr, unsigned int array_size) {

  return array_ptr[array_size - 1];
}

void sort_array(unsigned char *array_ptr, int i, int j) {

  if(i < j) {
  int pivot = partition(array_ptr, i, j);
  sort_array(array_ptr, i, pivot - 1);
  sort_array(array_ptr, pivot + 1, j);
  }

  return;
}

int partition(unsigned char *array_ptr, int l, int h) {

  unsigned char pivot = array_ptr[h];
  int i = l - 1;
  for (int j = l; j < h; j++) {
    if (array_ptr[j] > pivot) {
      i++;
      swap(&array_ptr[i], &array_ptr[j]);
    }
  }
  swap(&array_ptr[i + 1], &array_ptr[h]);
  
  return (i + 1);
}

void swap(unsigned char *array_element_ptr_1,
	  unsigned char *array_element_ptr_2) {

  unsigned char temp = *array_element_ptr_1;
  *array_element_ptr_1 = *array_element_ptr_2;
  *array_element_ptr_2 = temp;

  return;
}
