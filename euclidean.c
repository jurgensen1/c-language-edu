 /**
 * @file euclidean.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2022 March 11
 *
 * @brief This program implements a euclidean and manhattan distance calculator. 
 *
 * @details This program implements takes two points and prints the
 *       corresponding euclidean and manhattan distances.
 * 
 */
#include <stdio.h>
#include <math.h>


struct points_t
{
        double x;
        double y;
};

double euclidean(struct points_t a[])
{
        return sqrt(((a[0].x-a[1].x)*(a[0].x-a[1].x))+((a[0].y-a[1].y)*(a[0].y-a[1].y)));
}
double manhattan(struct points_t a[])
{
        return fabs(a[0].x-a[1].x) + fabs(a[0].y-a[1].y);
}


int main()
{       
        struct points_t a[2];
        a[0].x = 0;
        a[0].y = 0;
        a[1].x = 2;
        a[0].y = 2;
        printf("Please input two points:\n");
        printf("x1:");
        scanf("%lf", &a[0].x);
        printf("y1:");
        scanf(" %lf", &a[0].y);
        printf("x2:");
        scanf(" %lf", &a[1].x);
        printf("y2:");
        scanf(" %lf", &a[1].y);
       // printf("Please input point two as (x,y) in the format (00,00):");
        //scanf("(%2lf,%2lf)", &a[1].x, &a[1].y);
        printf("The euclidean distance: %lf\n", euclidean(a));
        printf("The manhattan distance: %lf\n", manhattan(a));
        return 0;
}