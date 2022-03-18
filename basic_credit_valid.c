/**
 * @file basic_credit_valid.c
 * @author Stephen Jurgensen
 * @date 2020 Feb 21
 * @brief This program determines if a credit card is valid using Luhn's 
 *      algorithm.
 * 
 * @details This program employs four functions to implement Luhn's algorithm. 
 *      (A fifth print function is used merely to check that the number is
 *       correct.)
 *      First, every other digit except the last, starting from postion 0, is
 *      doubled. These doubled numbers are summed. Then every other number, 
 *      starting from postion 1, are summed. The two sums are added then divided
 *      by ten. If the remaider is zero, then the card number is valid.     
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1
#define SIZE 32


void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);
int sum_of_doubles(int a[], int size);
int sum_of_other(int a[], int size);
void is_card_valid(int sum_other, int sum_multi);


int main(void)
{
	int card[NUM_DIGITS];
        char visa[NUM_DIGITS+1];
        
        /* use visa to store the credit card number from stdin */

	int sum_multi = 0;
	int sum_other = 0;
        size_t size = sizeof(card) / sizeof(int);

        fgets(visa, NUM_DIGITS+1, stdin);
        convert_card(card, visa, NUM_DIGITS);
	print_card(card, NUM_DIGITS);
        sum_multi = sum_of_doubles(card, size);
        sum_other = sum_of_other(card, size);
        is_card_valid(sum_other, sum_multi);

	return 0;

}

/* 
* Converts an array of char into an array of int. 
* @param num_digits is the size of the final int array.
* @param num[] is the original array of string values. 
* @param card[] is the destination/final array of integers.
* @return void. 
*/
void convert_card(int card[], char num[], int num_digits)
{
	int i;
	for(i = 0; i < num_digits; i++)
		card[i] = num[i] - '0';

}

/* 
* Prints the elements in an array. 
* @param card[] is the array to be printed
* @param size is the size of the array to be printed. 
* @return void. 
*/
void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

/* 
* Doubles every other element in an array except the last element and them sums
         all doubled elements. Products over ten have their digits added.
* @param a[] is the array. 
* @param size is the size of the array. 
* @return the sum of doubled elements. 
*/
int sum_of_doubles(int a[], int size)
{
        int product=0, i, sum_multi =0, splipt_ones=0;
	for (i = 0; i <= (size-1); i+=2){
		product = 2 * a[i];
		if (product < 10){
			sum_multi = product + sum_multi;
		} else if (product > 10){
                        splipt_ones = product - 10;
                        sum_multi = sum_multi + splipt_ones + 1;
                }
	}
        return sum_multi; 
}
/* 
* Sums every other elements in an array starting from the second element 
* @param a[] is the array. 
* @param size is the size of the array. 
* @return the sum of every other element. 
*/
int sum_of_other(int a[], int size)
{
        int sum_other = 0, i; 
	for (i = 1; i <= (size-1); i+=2){
		sum_other = sum_other + a[i];
	}
        return sum_other; 
}
/* 
* Prints the corresponding validity statement, using the modulus of the sum of
        two parameters.  
* @param sum_other is an integer representing the sum of every other digit in 
        an credit card. 
* @param sum_multi is an integer representing the sum of every other digit
         doubled, except the last, in an credit card. 
* @return void, printed validity statement. 
*/
void is_card_valid(int sum_other, int sum_multi)
{
	double mod = (sum_other + sum_multi) % 10;
	if (mod == 0){
		printf("Credit Card Number Is Valid!\n");
	} else
		printf("Credit Card Number Is Not Valid\n");
}
