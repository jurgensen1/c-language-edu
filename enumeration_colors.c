 /**
 * @file enumeration_colors.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2022 March 11
 *
 * @brief This program implements a enumeration of colors. 
 *
 * @details This program takes a number and prints the corresponding number
 *       and color based on enumeration.
 * 
 */
#include <stdio.h>


enum color
{
        YELLOW = 5, 
        GREEN, 
        BLUE, 
        INDIGO = 14, 
        VIOLET,
        RED = 18, 
        ORANGE 
};

int main()
{
        int the_color;
        printf("Please input 5, 6, 7, 14, 15, 18, or 19: ");
        scanf("%d", &the_color);
        switch (the_color)
        {
        case YELLOW:
                printf("Color: YELLOW\n");
                printf("Number: 5\n");
                break;
        case GREEN:
                printf("Color: GREEN\n");
                printf("Number: 6\n");
                break;
        case BLUE:
                printf("Color: BLUE\n");
                printf("Number: 7\n");
                break;
        case INDIGO:
                printf("Color: INDIGO\n");
                printf("Number: 14\n");
                break;
        case VIOLET:
                printf("Color: VIOLET\n");
                printf("Number: 15\n");
                break;
        case RED:
                printf("Color: RED\n");
                printf("Number: 18\n");
                break;
        case ORANGE:
                printf("Color: ORANGE\n");
                printf("Number: 19\n");
                break;
        default:
                printf("Color number is not 5, 6, 7, 14, 15, 18, or 19\n");
                break;
        }
        return 0;
}