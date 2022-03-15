/*
* 4-addition.c - Addition of complex
* Author: Rodrigo Zárate Algecira
* Date: July 30, 2021
*/

#include "holberton.h"
#include <math.h>

/**
* addition - return the addition
* @c1: complex
* @c2: complex
* @c3: complex pointer
* Return: void
*/

void addition(complex c1, complex c2, complex *c3)
{
	c3->re = c1.re + c2.re;
	c3->im = c1.im + c2.im;
}
