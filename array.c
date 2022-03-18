/**
 * @file array.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2022 Mar 11
 *
 * @brief Functions for fundamental array algorithms.
 *
 * @details The functions implemented include:
 *      - basic counting
 *      - summing 
 *      - searching
 *      - average
 *      - median
 *      - max
 *      - min
 *      - reverse
 */



#define LT 1
#define LE 2
#define EE 3
#define GE 4
#define GT 5
#include <stdio.h>
#include "array.h"

/* 
* Updates struct summary_t, adding array statsitics of a[]. 
* @param size is the size of the test array
* @param a[] is the array being searched for its largest number.
* @param *summary is the pointer to the structure.
* @return the largest integer. 
*/
void get_summary(int a[], size_t size, struct summary_t *summary)
{
        summary->size = size;
        summary->max = find_max(a, size);
        summary->min = find_min(a, size);
        summary->mid_point = midpoint(a, size);
        summary->great_count = get_count(a, size, summary->mid_point, GT);
        summary->less_count = get_count(a, size, summary->mid_point, LT);
        summary->search_midpoint = linear_search(a, size, summary->mid_point);
        summary->sum = sum_array(a, size);
        summary->average = average_array(a, size);
        summary->even = even_count(a, size);
        summary->odd = odd_count(a, size);
        summary->div_count = divisible_count(a, size, summary->min); 
        summary->median = median_array(a, size);
}
/* 
* Prints the values form a given array. 
* @param size
* @param max the largest number stored in the test array
* @param min the smallest number stored in the test array
* @param midpoint the midpoint between min and max
* @param g_count the number of elements greater than the midpoint
* @param l_count the number of elements less than the midpoint
* @param linear_search_midpoint
* @param sum
* @param average
* @param median
* @param n_even_elements
* @param n_odd_elements
* @param n_divisible_min
* @return prints thirteen values: all parameters
*/
void print_summary(int a[], size_t size, struct summary_t summary)
{
        printf("Size of array:                  %zu\n", summary.size);
        printf("Largest number:                 %d\n", summary.max);
        printf("Smallest number:                %d\n", summary.min);
        printf("Midpoint:                       %d\n", 
                summary.mid_point);
        printf("Number greater than midpoint:   %d\n", 
                summary.great_count);
        printf("Number less than midpoint:      %d\n",
                        summary.less_count);
        if (summary.search_midpoint == -1)
        {
                printf("--- Midpoint not found in list ---\n");
        } else
                printf("Midpoint found in list, index:  %d\n", 
                summary.search_midpoint);
        printf("Sum:                            %d\n", summary.sum);
        printf("Average:                        %f\n", 
                summary.average);
        printf("The median:                     %d\n", summary.median);
        printf("The number of even:             %d\n", summary.even);
        printf("The number of odd:              %d\n", summary.odd);
        if (summary.div_test == 0) 
        {
                printf("The quantity divisible by %d:    none\n", summary.min);
        }else if (summary.div_test==1)
        {
                printf("The quantity divisible by %d:    %zu\n", summary.min, size);
        } else
                printf("The quantity divisible by %d:   %d\n", summary.min,
                        summary.div_count);
}
/* 
* Finds and returns the largest number in an array. 
* @param size is the size of the test array
* @param a[] is the array being searched for its largest number.
* @return the largest integer. 
*/
int find_max(int a[], size_t size)
{
        int i;
        int max = a[0];
        for(i = 0; i < size; i++)
                if ( max <= a[i] ){
                        max = a[i];
                }
        return max;
}
        /* 
* Finds and returns the smallest number in an array. 
* @param size is the size of the test array
* @param a[] is the array being searched for its smallest number.
* @return the smallest integer  
*/
int find_min(int a[], size_t size)
{
        int i;
        int min = a[0];
        for(i = 0; i < size; i++)
                if ( min >= a[i] ){
                        min = a[i];
                }
        return min;
}
/* 
* Calculates the midpoint using the min & max of an array. 
* @param size is the size of the test array
* @param a[] is the array being searched for its smallest number.
* @return the midpoint as integer 
*/
int midpoint(int a[], size_t size)
{
        int midpoint = (find_min(a, size) + find_max(a, size))/2;
        return midpoint;
}
/* 
* Finds quantity  of numbers in an array <, <=, ==, >=, or > 
*       than a test value. 
* @param size is the size of the test array
* @param a[] is the array being searched for its smallest number.
* @param test_value value to test the array's numbers against.
* @param type is the type of operation applied in the comparison.
* @return number of elements that staisfy the comparison.
*/
int get_count(int a[], size_t size, int test_value, int type)
{
        int i;
        int count = 0;
        switch (type)
        {
        case LT:
                for(i = 0; i < size; i++)
                        if ( a[i] < test_value ){
                                count++;
                        }
                break;
        case LE:
                for(i = 0; i < size; i++)
                        if ( a[i] <= test_value ){
                                count++;
                        }
                break;
        case EE:
                for(i = 0; i < size; i++)
                        if ( a[i] == test_value ){
                                count++;
                        }
                break;
        case GE:
                for(i = 0; i < size; i++)
                        if ( a[i] >= test_value ){
                                count++;
                        }
                break;
        case GT:
                for(i = 0; i < size; i++)
                        if ( a[i] > test_value ){
                                count++;
                        }
                break;
        }
        return count;
}
/* 
* Searches for a value in an array. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return either the index of the value, or -1 if not found 
*/
int linear_search(int a[],size_t size,int test_value)
{
        int i, index = -1;
        for (i = 0; i < size; i++)
        {
                if (test_value == a[i])
                        index = i;
        }
        return index;
}
/* 
* Sums all values in an array. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return the sum as an integer 
*/
int sum_array(int a[], size_t size)
{
        int i;
        int sum = 0;
        for ( i = 0; i < size; i++)
        {
                sum = sum + a[i];
        }
        return sum;
}
/* 
* Finds the average of all values in an array. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return the average as an integer 
*/              
double average_array(int a[], size_t size)
{
        return (double) (sum_array(a, size))/ size;
}
/* 
* Reverses the order of an array. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return array of integers 
*/ 
void reverse(int a[], size_t size)
{
        int i =0;
        int tmp;
        int half = size/2;
        for (i = 0; i < half; i++) 
        {
                tmp = a[i];
                a[i] = a[size-i-1];
                a[size-i-1] = tmp;
        }
}
/* 
* Calculates the median. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return the median as an integer. 
*/ 
int median_array(int a[], size_t size)
{
        int b[size];
        for (int i = 0; i < size; i++){
                b[i] =  a[i];
        }
        int i, j, min_index;
        for (i = 0; i < size - 1 ; i++)
        {
                min_index = i;
                int tmp;
                for (j = i+1 ; j < size; j++){
                        if ((b[j] < b[min_index])){
                                min_index = j;
                        }
                }
                tmp = b[i];
                b[i] = b[min_index];
                b[min_index] = tmp;                
        }
        int mod = size % 2;
        int median;
        if (mod != 0){
                median = b[(size/2)];
        } else
                median = ((b[(size/2)-1] + b[(size/2)]))/2;
        return median;
}
/* 
* Calculates the quantity of even numbers in array. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return quantity of even numbers as integer. 
*/ 
int even_count(int a[], size_t size)
{
        int count = 0;
        for (int i = 0; i < size; i++)
        {
                int mod = a[i] % 2;
                if (mod == 0){
                        count = count + 1;
                }
        }
        return count;
}
/* 
* Calculates the quantity of odd numbers in array. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return quantity of odd numbers as integer. 
*/ 
int odd_count(int a[], size_t size)
{
        int count = 0;
        for (int i = 0; i < size; i++)
        {
                int mod = a[i] % 2;
                if (mod != 0){
                        count = count + 1;
                }
        }
        return count;
}
/* 
* Calculates the quantity of numbers divisible to by a given
        integer. 
* @param size is the size of the test array
* @param a[] is the array being searched.
* @return quantity of numbers divisible by given. 
*/ 
int divisible_count(int a[], size_t size, int test)
{
        int count = 0;
        if (test == 0)
        {
               count = 0;
        }else if (test == 1 | test == -1)
        {
                count = test;
        } else
                for (int i = 0; i < size; i++)
                {
                        int mod = a[i] % test;
                        if (mod == 0){
                                count = count + 1;
                        }
                }
        return count;
}