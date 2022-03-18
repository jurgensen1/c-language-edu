/**
 * @file array.h
 * 
 * @author Stephen Jurgensen
 *
 * @date 2022 Mar 11
 *
 * @brief header file for array_fucntions_struct.c
 *
 * @details see array_fucntions_struct.c for details
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h> 		
struct summary_t {
        size_t size; 
        int max; 
        int min; 
        int mid_point;
        int great_count; 
        int less_count; 
        int search_midpoint; 
        int sum;
        double average; 
        int median; 
        int even; 
        int odd;
        int div_test;
        int div_count;
};

void get_summary(int a[], size_t size, struct summary_t *summary);
void print_summary(int a[], size_t size, struct summary_t summary);
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

