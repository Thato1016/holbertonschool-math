/*
* 1-conjugate.c - Conjugate of ocmplex
* Author: Rodrigo Zárate Algecira
* Date: July 30, 2021
*/

#include "holberton.h"
#include <stdio.h>

/**
* conjugate - return the conjugate
* @c: structure complex
* Return: complex
*/

complex conjugate(complex c)
{
c.im *= -1;
return (c);
}
