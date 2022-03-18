/**
 * @file basic_geometry_calculator.c
 * @brief Implements a geometry calculator with a limited set of features, exibiting each feature. 
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
 * @author Stephen Jurgensen
 * @date 2022 Jan 31
 * @bug None
 */

/* preproccessor directives */
#include <stdio.h>
#include <math.h>

/*prototypes*/
double area_rectangle(int rh,int rw);
double perimeter_rectangle(int rh,int rw);
double diagonal_rectangle(int rh,int rw);
double area_circle(double r);
double circumference(double r);
double area_triangle(double th,double tw);
double hypotenuse(double th,double tw);
double perimeter_triangle(double th,double tw);
double exterior_angle(int ns);
double sum_interior_angle(int ns);
double interior_angle(int ns);
double area_regular_polygon(double sl, int ns);

/* main function */
int main(void)
{
        int rectangle_height;
        int rectangle_width;
        double radius;
        double triangle_height;
        double triangle_width;
        int number_of_sides;
        double side_length; 

        printf("\nYou have initiated the computationally-precise-(repeatable)-but-not-overwhelmingly-accurate-(truncated significant figures)-geometry calculator. Good luck.\n\n");
        printf("For the rectangle calculations please input a height and width:\n");
        printf("   -------- \n");
        printf("  |        |\n");
        printf("  |        |\n");
        printf("  |        |\n");
        printf("  |        |\n");
        printf("  |        |\n");
        printf("   -------- \n");
        printf("Input height: "); 
        scanf("%d", &rectangle_height);
        printf("Input width: "); 
        scanf("%d", &rectangle_width);
        printf("Given a rectangle with height %d and width %d:\n", 
                rectangle_height, rectangle_width); 
        printf("       - area:                   %lf\n",
                area_rectangle(rectangle_height,rectangle_width));
        printf("       - perimeter:              %lf\n",
                perimeter_rectangle(rectangle_height,rectangle_width));
        printf("       - diagonal's length:      %lf\n\n",
                diagonal_rectangle(rectangle_height,rectangle_width));

        printf("For the circle calculations please input a radius:\n");
        printf("            .             \n");
        printf("      .           .       \n");
        printf("     .             .      \n");
        printf("    .               .     \n");
        printf("     .             .      \n");
        printf("      .           .       \n");
        printf("            .             \n");
        printf("Input radius: "); 
        scanf("%lf", &radius);
        printf("Given a circle with a radius of %lf:\n",
                radius);
        printf("       - area:                   %lf\n",
                area_circle(radius));
        printf("       - circumference:          %lf\n\n",
                circumference(radius));

        printf("For the right-triangle calculations please input a height and base width:\n");
        printf("        |\\\n");
        printf("        | \\\n");
        printf("        |  \\\n");
        printf("        |   \\\n");
        printf("        |    \\\n");
        printf("        |     \\\n");
        printf("        |      \\\n");
        printf("        ---------\n");
        printf("Input height: "); 
        scanf("%lf", &triangle_height);
        printf("Input base width: "); 
        scanf("%lf", &triangle_width);
        printf("Given a right-triangle with height %lf and base width %lf:\n",
                triangle_height, triangle_width);
        printf("       - area:                   %lf\n",
                area_triangle(triangle_height, triangle_width));
        printf("       - hypotenuse length:      %lf\n",
                hypotenuse(triangle_height,triangle_width));
        printf("       - perimeter:              %lf\n\n",
                perimeter_triangle(triangle_height, triangle_width));

        printf("For the regular-polygon calculations please input the number of sides and a side length:\n");
        printf("                                 \n");
        printf("                     .....       \n");
        printf("                  .         .    \n");
        printf("                  .         .    \n");
        printf("                  .         .    \n");
        printf("                     .....       \n");
        printf("                                 \n");
        printf("Input number of sides: "); 
        scanf("%d", &number_of_sides);
        printf("Input side length: "); 
        scanf("%lf", &side_length);
        printf("Given a regular polygon with %d sides and a side length of %lf:\n",
                number_of_sides, side_length);
        printf("       - exterior angle:         %lf\n",
                exterior_angle(number_of_sides));
        printf("       - interior angle:         %lf\n",
                interior_angle(number_of_sides));
        printf("       - area:                   %lf\n",
                area_regular_polygon(side_length,number_of_sides));
        return 0;
}

/* 
* Calculates the area of a rectangle 
* @param rh is the height of the rectangle.
* @param rw is the width of the rectangle.
* @return area of cicle
*/
double area_rectangle(int rh,int rw)
{
        return rh * rw;
}
/* 
* Calculates the perimeter of a rectangle 
* @param rh is the height of the rectangle.
* @param rw is the width of the rectangle.
* @return perimeter
*/
double perimeter_rectangle(int rh,int rw)
{
        return (rh + rw) * 2;
}
/* 
* Calculates the length of the diagonal of a rectangle.
* @param rectangle_height is the height of the rectangle.
* @param rectangle_width is the width of the rectangle.
* @return diagonal length of a rectangle
*/
double diagonal_rectangle(int rh,int rw)
{
        return hypotenuse(rh, rw);
}
/* 
* Calculates the area of a circle
* @param r is the radius of the circle.
* @return area of circle
*/
double area_circle(double r)
{
        return 3.141593 * pow(r, 2);
}
/* 
* Calculates the circumference of a circle 
* @param r is the radius of the circle.
* @return circumference of cicle
*/
double circumference(double r)
{
        return 3.141593 * 2 * r;
}
/* 
* Calculates the area of a triangle 
* @param th is the height of the triangle.
* @param tw is the base/width of the triangle.
* @return area of a triangle 
*/
double area_triangle(double th,double tw)
{
        return 0.5 * th * tw;
}
/* 
* Calculates the length of the hypotenuse
* @param th is the height of the triangle.
* @param tw is the base/width of the triangle.
* @return length of the hypotenuse
*/
double hypotenuse(double th,double tw)
{
        return sqrt(pow(th, 2) + pow(tw, 2));
}
/* 
* Calculates the perimeter of a triangle 
* @param th is the height of the triangle.
* @param tw is the base/width of the triangle.
* @return perimeter of a triangle.
*/
double perimeter_triangle(double th,double tw)
{
        return th + tw + hypotenuse(th, tw);
}
/* 
* Calculates the exterior angle of a regular polygon.
* @param ns is the number of sides of a regular polygon.
* @return exterior angle of a regular polygon.
*/
double exterior_angle(int ns)
{
        return 360 / ns;
}
/* 
* Calculates the sum interior angles of a regular polygon. 
* @param ns is the number of sides of a regular polygon.
* @return sum of interior angles of a regular polygon. 
*/
double interior_angle(int ns)
{
        return (180 * ((double) ns - 2))/ns;
}
/* 
* Calculates the interior angle of a regular polygon. 
* @param ns is the number of sides of a regular polygon.
* @return interior angle of a regular polygon. 
*/
double sum_interior_angle(int ns)
{
        return 180 * ((double) ns - 2);
}
/* 
* Calculates the area of a regular polygon. 
* @param sl is the length of one side of a regular polygon.
* @param ns is the number of sides of a regular polygon.
* @return area of a regular polygon. 
*/
double area_regular_polygon(double sl,int ns)
{
        return ((double) pow(sl, 2) * ns) / ((double) 4 * tan((3.141593/ns)));
}