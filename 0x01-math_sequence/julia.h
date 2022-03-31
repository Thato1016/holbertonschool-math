#ifndef JULIA_H
#define JULIA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* struct complex - complex number
* @x: double
* @y: double
*/

typedef struct complex
{
double x;
double y;
} complex;

void julia(int width, int height, complex c, double radius, int n);

#endif
