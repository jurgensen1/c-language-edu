/**
 * @file interactive_geometry_calculator.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2019 Feb 7
 *
 * @brief A program that uses the function in geometry_functions.c, implementing a 
 *              user-input-directed geometery calculator. 
 *
 * @details Implements these functions as features:
 *      area_rectangle()
 *      perimeter_rectangle()
 *      diagonal_rectangle()
 *      area_circle()
 *      circumference()
 *      area_triangle()
 *      hypotenuse()
 *      perimeter_triangle()
 *      exterior_angle()
 *      interior_angle()
 *      sum_interior_angle()
 *      area_regular_polygon()
 *      
 *
 * @bugs Dealing with the buffer character was hapazardly fixed 
 * with an addtional getchar(). But this is not ideal.
 *
 * @todo none
 */

#include "geometry_functions.h"
#include <stdio.h>
#include <math.h>

int main(void) {
        int rectangle_height;
        int rectangle_width;
        double radius;
        double triangle_height;
        double triangle_width;
        int number_of_sides;
        double side_length;
        char mop; 
        char circle_mop;
        char polygon_mop;
        char rectangle_mop;
        char triangle_mop;
        char buffer_catch;


        printf("Which operation do you want to use (input c, p, r, or t):\n");
        printf("        Circle (c)\n");
        printf("        Regular Polygon (p)\n");
        printf("        Rectangle (r)\n");
        printf("        Triangle (t)\n");
        printf("        --- Input: ");
        mop = getchar();
        buffer_catch = getchar();

        switch (mop){
        case 'c':
        case 'C':
                printf("You picked circle, now pick an option (input a or c):\n");
                printf("        Calculate area: A\n");
                printf("        Calculate circumference: C\n");
                printf("        Your choice: ");
                circle_mop = getchar();
                switch (circle_mop){
                case 'A':
                case 'a':
                        printf("        Input radius: "); 
                        scanf("%lf", &radius);
                        if (!(radius >= 0)){
                                printf("        Radius must be larger than zero. Try again");
                                break;
                        } 
                        printf("        Given a circle with a radius of %lf:\n", radius);
                        printf("        Area: %lf\n",
                        area_circle(radius));
                        break;
                case 'C':
                case 'c':
                        printf("        Input radius: "); 
                        scanf("%lf", &radius);
                        if (!(radius >= 0)){
                                printf("        Radius must be larger than zero. Try again");
                                break;
                        }
                        printf("        Given a circle with a radius of %lf:\n", radius);
                        printf("        Circumference:  %lf\n\n",
                        circumference(radius));
                        break;
                default:
                        printf("        You didn't input A or C: try again.");
                        break;
                }
                break;
        case 'p':
        case 'P':
                printf("You picked polygon, now pick an option:\n");
                printf("        Calculate exterior angle: E\n");
                printf("        Calculate interior angle: I\n");
                printf("        Calculate area: A\n");
                printf("        Input: ");
                polygon_mop = getchar();

                switch (polygon_mop){
                case 'E':
                case 'e':
                        printf("        Input number of sides: "); 
                        scanf("%d", &number_of_sides); 
                        if (!(number_of_sides >= 0)){
                                printf("        Number of sides must be larger than zero and an integer. Try again");
                                break;
                        }    
                        printf("        Given a regular polygon with %d sides:\n",
                                number_of_sides);
                        printf("        Exterior angle: %lf\n",
                        exterior_angle(number_of_sides));
                        break;
                case 'I':
                case 'i':
                        printf("        Input number of sides: "); 
                        scanf("%d", &number_of_sides); 
                        if (!(number_of_sides >= 0)){
                                printf("        Number of sides must be larger than zero and an integer. Try again");
                                break;
                        }    
                        printf("        Given a regular polygon with %d sides:\n",
                                number_of_sides);
                        printf("        Interior angle: %lf\n",
                        interior_angle(number_of_sides));
                        break;
                case 'A':
                case 'a':
                        printf("        Input number of sides: "); 
                        scanf("%d", &number_of_sides); 
                        if (!(number_of_sides >= 0)){
                                printf("        Number of sides must be larger than zero and an integer. Try again");
                                break;
                        }    
                        printf("        Input side length: ");
                        scanf("%lf", &side_length);
                        if (!(side_length >= 0)){
                                printf("        Side length must be larger than zero and an integer. Try again\n");
                                break;
                        }    
                        printf("        Given a regular polygon with %d sides and a side length of %lf:\n",
                        number_of_sides, side_length);
                        printf("        Area: %lf\n",
                        area_regular_polygon(side_length,number_of_sides));
                        break;
                default:
                        printf("        You didn't input E, I, or A intially, try again.\n");
                        break;
                }
                break;
        case 'r':
        case 'R':
                printf("You picked rectangle, now pick an option:\n");
                printf("        Calculate perimeter: P\n");
                printf("        Calculate area: A\n");
                printf("        Calculate diagonal's length: D\n");
                printf("        Input: ");
                rectangle_mop = getchar();

                switch (rectangle_mop){
                case 'A':
                case 'a':
                        printf("        Now, input height and width: \n");
                        printf("        Input height: "); 
                        scanf("%d", &rectangle_height);
                        printf("        Input width: "); 
                        scanf("%d", &rectangle_width);
                        if (!(rectangle_width >= 0) && !(rectangle_height >= 0)){
                                printf("        Width and hieght must both be greater that zero. Try again\n");
                                break;
                        }
                        printf("        Given a rectangle with height %d and width %d:\n", 
                                rectangle_height, rectangle_width); 
                        printf("        Area: %lf\n",
                                area_rectangle(rectangle_height,rectangle_width));
                        break;
                case 'P':
                case 'p':
                        printf("        Now, input height and width: \n");
                        printf("        Input height: "); 
                        scanf("%d", &rectangle_height);
                        printf("        Input width: "); 
                        scanf("%d", &rectangle_width);
                        if (!(rectangle_width >= 0) && !(rectangle_height >= 0)){
                                printf("        Width and hieght must both be greater that zero. Try again\n");
                                break;
                        }
                        printf("        Given a rectangle with height %d and width %d:\n", 
                                rectangle_height, rectangle_width); 
                        printf("        Perimeter: %lf\n",
                                perimeter_rectangle(rectangle_height,rectangle_width));
                        break;
                case 'D':
                case 'd':
                        printf("        Now, input height and width: \n");
                        printf("        Input height: "); 
                        scanf("%d", &rectangle_height);
                        printf("        Input width: "); 
                        scanf("%d", &rectangle_width);
                        if (!(rectangle_width >= 0) && !(rectangle_height >= 0)){
                                printf("        Width and hieght must both be greater that zero. Try again\n");
                                break;
                        }
                        printf("        Given a rectangle with height %d and width %d:\n", 
                                rectangle_height, rectangle_width); 
                        printf("        Diagonal's length: %lf\n\n",
                        diagonal_rectangle(rectangle_height,rectangle_width));
                        break;
                
                default:
                        printf("        You didn't input P, A, or D intially, try again.");
                        break;
                }
                break;
        case 't':
        case 'T':
                printf("You picked triangle, now pick an option:\n");
                printf("        Calculate perimeter: P\n");
                printf("        Calculate area: A\n");
                printf("        Calculate hypotenuse length: H\n");
                printf("        Input: ");
                triangle_mop = getchar();

                switch (triangle_mop){
                case 'A':
                case 'a':
                        printf("        Input height: "); 
                        scanf("%lf", &triangle_height);
                        printf("        Input base width: "); 
                        scanf("%lf", &triangle_width);
                        if (!(triangle_width >= 0) && !(triangle_height >= 0)){
                                printf("        Width and height must both be greater that zero. Try again");
                                break;
                        }
                        printf("        Given a right-triangle with height %lf and base width %lf:\n",
                                triangle_height, triangle_width);
                        printf("        Area: %lf\n",
                        area_triangle(triangle_height, triangle_width));
                        break;
                case 'H':
                case 'h':
                        printf("        Input height: "); 
                        scanf("%lf", &triangle_height);
                        printf("        Input base width: "); 
                        scanf("%lf", &triangle_width);
                        if (!(triangle_width >= 0) && !(triangle_height >= 0)){
                                printf("        Width and height must both be greater that zero. Try again");
                                break;
                        }
                        printf("        Given a right-triangle with height %lf and base width %lf:\n",
                                triangle_height, triangle_width);
                        printf("        Hypotenuse length: %lf\n",
                        hypotenuse(triangle_height,triangle_width));
                        break;
                case 'P':
                case 'p':
                        printf("        Input height: "); 
                        scanf("%lf", &triangle_height);
                        printf("        Input base width: "); 
                        scanf("%lf", &triangle_width);
                        if (!(triangle_width >= 0) && !(triangle_height >= 0)){
                                printf("        Width and height must both be greater that zero. Try again");
                                break;
                        }
                        printf("        Given a right-triangle with height %lf and base width %lf:\n",
                                triangle_height, triangle_width);
                        printf("        Perimeter: %lf\n\n",
                        perimeter_triangle(triangle_height, triangle_width));
                        break;
                default:
                        printf("        You didn't input P, H, or A intially, try again.");
                        break;
                }
                break;
        default: 
                printf("        Try again. Input C, P, R, or T.\n");
        }
        return 0;
}
