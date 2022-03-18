/**
 * @file english_phrase_number_printer.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2019 Feb 7
 *
 * @brief This program implements a number printer, taking in an two-digit 
 *      input and printing the English phrase equivalent.  
 *
 * @details This program reads in the two-digit integer as two sperate values, 
 *      representing the tens place and the one place respectively, setting
 *      them to variables. The variables are used in switch statements
 *      to print out the correct English phrase. Note that a single-digit 
 *      number’s phrase can be obtained by inputting a zero followed by a 
 *      single digit number. 
 */

#include <stdio.h>

int main(void) 
{
        int tens_digit= 3;
        int ones_digit= 0;

        printf("Enter a two-digit number (or a one digit after a zero, e.g., 03 for 3): ");
        scanf("%1d%1d", &tens_digit, &ones_digit);

        switch (tens_digit)
        {
        case 9:
                printf("Ninety");
                break;
        case 8:
                printf("Eighty");
                break;
        case 7:
                printf("Seventy");
                break;
        case 6:
                printf("Sixty");
                break;
        case 5:
                printf("Fifty");
                break;
        case 4:
                printf("Forty");
                break;
        case 3:
                printf("Thirty");
                break;
        case 2:
                printf("Twenty");
                break;
        case 1:
                switch (ones_digit)
                {
                case 9:
                        printf("Nineteen");
                        break;
                case 8:
                        printf("Eighteen");
                        break;
                case 7:
                        printf("Seventeen");
                        break;
                case 6:
                        printf("Sixteen");
                        break;
                case 5:
                        printf("Fifteenth");
                        break;
                case 4:
                        printf("Fourteen");
                        break;
                case 3:
                        printf("Thirteen");
                        break;
                case 2:
                        printf("Twelve");
                        break;
                case 1:
                        printf("Eleven");
                        break;
                case 0:
                        printf("Ten");
                        break;
                }
                break;
        case 0:
                printf("");
                break;
        default:
                printf("");
                break;
        }

        if ((ones_digit >= 1) && (tens_digit >= 1 )) {
                printf("-");
        }
        

        if (tens_digit != 1) {
                switch (ones_digit)
                {
                case 9:
                        printf("Nine");
                        break;
                case 8:
                        printf("Eight");
                        break;
                case 7:
                        printf("Seven");
                        break;
                case 6:
                        printf("Six");
                        break;
                case 5:
                        printf("Five");
                        break;
                case 4:
                        printf("Four");
                        break;
                case 3:
                        printf("Three");
                        break;
                case 2:
                        printf("Two");
                        break;
                case 1:
                        printf("One");
                        break;
                case 0:
                        if(tens_digit >= 1){
                                printf("");
                        }else
                                printf("Zero");
                        break;
                default:
                        printf("");
                        break;
                }
        }
        return 0;
}







