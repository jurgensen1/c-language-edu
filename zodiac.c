 /**
 * @file zodiac.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2022 March 11
 *
 * @brief This program implements a zodiac teller. 
 *
 * @details This program implements takes a date and prints the
 *       corresponding zodiac sign.
 * 
 */
#include <stdio.h>


enum month{
         JAN = 1, FEB, MAR, APR, MAY, JUNE,
         JUL, AUG, SEPT, OCT, NOV, DEC
};


int main()
{
        while (1) {
                unsigned short day, month, year;
                int select = 0;
                printf("\n");
                printf("Menu:\n");
                printf("1. Enter a date\n");
                printf("2. Quit\n");
                printf("Enter selection (1 or 2): ");
                scanf("%d", &select);
                if (select == 2){
                        printf("You quit with selection %d\n", select);
                        break;
                } else if ((select != 1)) {
                        printf("You entered: %d\n", select);
                        printf("Invaid input caused exit. Input 1 or 2 only.\n");
                        break;
                }


                printf("Please input date, MM/DD/YY: ");
                scanf(" %02hu/%02hu/%02hu/", &month, &day, &year);
                switch (month)
                {
                case JAN:
                        if (day > 31){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 21)
                        {
                                printf("Capricorn\n");
                        } else  {
                                printf("Aquarius\n");
                        }
                        break;
                case FEB:
                        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
                                if (day > 29){
                                        printf("Day is invalid; N.B.: leap year\n");
                                        break;
                                }
                        } else {
                                if (day > 28){
                                        printf("Day is not valid; N.B.: not leap year\n");
                                        break;
                                }
                        }
                        if (day < 20)
                        {
                                printf("Aquarius\n");
                        } else  {
                                printf("Pisces\n");
                        }
                        break;
                case MAR:
                        if (day > 31){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 21)
                        {
                                printf("Pisces\n");
                        } else  {
                                printf("Aries\n");
                        }
                        break;
                case APR:
                        if (day > 30){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 20)
                        {
                                printf("Aries\n");
                        } else  {
                                printf("Taurus\n");
                        }
                        break;
                case MAY:
                        if (day > 31){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 22)
                        {
                                printf("Taurus\n");
                        } else  {
                                printf("Gemini\n");
                        }
                        break;
                case JUNE:
                        if (day > 30){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 22)
                        {
                                printf("Gemini\n");
                        } else  {
                                printf("Cancer\n");
                        }
                        break;
                case JUL:
                        if (day > 31){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 24)
                        {
                                printf("Cancer\n");
                        } else  {
                                printf("Leo\n");
                        }
                        break;
                case AUG:
                        if (day > 31){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 24)
                        {
                                printf("Leo\n");
                        } else  {
                                printf("Virgo\n");
                        }
                        break;
                case SEPT:
                        if (day > 30){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 24)
                        {
                                printf("Virgo\n");
                        } else  {
                                printf("Libra\n");
                        }
                        break;
                case OCT:
                        if (day > 31){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 24)
                        {
                                printf("Libra\n");
                        } else  {
                                printf("Scorpio\n");
                        }
                        break;
                case NOV:
                        if (day > 30){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 23)
                        {
                                printf("Scorpio\n");
                        } else  {
                                printf("Sagittarius\n");
                        }
                        break;
                case DEC:
                        if (day > 31){
                                printf("Day is invalid size");
                                break;
                        }
                        if (day < 23)
                        {
                                printf("Sagittarius\n");
                        } else  {
                                printf("Capricorn\n");
                        }
                        break;
                default:
                        printf("Month is not valid\n");
                        break;
                }
        }
        return 0;
}