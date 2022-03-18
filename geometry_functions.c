/**
 * @file geometry_functions.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2019 Feb 7
 *
 * @brief contains the function definitions for interactive_geometry_calculator.c 
 *
 */

#include "geometry_functions.h"
#include <stdio.h>

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
