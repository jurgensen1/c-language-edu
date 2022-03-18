/**
 * @file basic_array_header.h
 * 
 * @author Stephen Jurgensen
 *
 * @date 2022 Feb 23
 *
 * @brief header file for basic_array_manipulation.c
 *
 * @details see basic_array_manipulation.c for details
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h> 		

/* function declarations go here */
void print_array(int a[], size_t size);
void print_summary(int a[], size_t size, int max, int min, int midpoint,
                int g_count, int l_count, int search, int sum,
                double average, int median, int even, int odd, int div_test,
                int div_count);
int find_max(int a[], size_t size);
int find_min(int a[], size_t size);
int midpoint(int a[], size_t size);
int get_count(int a[], size_t size, int test_value, int type);
int linear_search(int a[],size_t size,int test_value);
int sum_array(int a[], size_t size);             
double average_array(int a[], size_t size);
void reverse(int a[], size_t size);
int median_array(int a[], size_t size);
int even_count(int a[], size_t size);
int odd_count(int a[], size_t size); 
int divisible_count(int a[], size_t size, int test);


#endif

