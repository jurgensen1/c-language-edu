/**
 * @file geometry_functions.h
 *
 * @author Stephen Jurgensen
 *
 * @date 2019 Feb 7
 *
 * @brief header file for interactive_geometry_calculator.c
 *
 * @details see geometry_functions.c for details
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>

/* Function prototyes go here */
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

#endif
