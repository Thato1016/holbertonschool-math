#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "holberton.h"


// Conjugate
complex *Conjugate(complex c)
{
    static complex c1;
    c1.re = c.re;
    c1.im = -(c.im);
    return (&c1);
}

// Modulus
double modulus(complex c)
{
    double m = sqrt(c.re * c.re + c.im * c.im);
    return m;
}

// Argument
double Argument(complex c)
{
    double a;
    if (c.re == 0 && c.im == 0)
    {
        a = 0;
    }
    else if (c.re != 0)
    {
        if ((c.re < 0) && (c.im < 0))
        {
            a = atan(c.im / c.re) - M_PI;
        }
        else if ((c.re < 0) && (c.im > 0))
        {
            a = atan(c.im / c.re) + M_PI;
        }
        else
        {
            a = atan(c.im / c.re);
        }
    }
    else
    {
        if (c.im < 0)
        {
            a = -M_PI / 2;
        }
        else
        {
            a = M_PI / 2;
        }
    }
    return a;
}

// Addition
void addition(complex c1, complex c2, complex *c3)
{
    c3->re = c1.re + c2.re;
    c3->im = c1.im + c2.im;
}

// Subtraction
void substraction(complex c1, complex c2, complex *c3)
{
    c3->re = c1.re - c2.re;
    c3->im = c1.im - c2.im;
}

// Multiplication
void multiplication(complex c1, complex c2, complex *c3){
    c3->re = c1.re * c2.re - c1.im * c2.im;
    c3->im = c1.re * c2.im + c1.im * c2.re;
}

// Division
void division(complex c1, complex c2, complex *c3)
{
    c3->re = (c1.re * c2.re + c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im);
    c3->im = (-c1.re * c2.im + c1.im * c2.re) / (c2.re * c2.re + c2.im * c2.im);
}

// Real and imaginary parts of a complex number given from modulus and arguments
void complex_from_mod_arg (double m, double arg, complex *c3)
{
    c3->re = m * cos(arg);
    c3->im = m * sin(arg);
}

// Display of the complex number
void ComplexNumber(complex c)
{
    if (c.im == -1)
    {
        printf("%g -  i", c.re);
    }
    else if (c.im < 0)
    {
        printf("%g - %g i", c.re, -c.im);
    }
    else if (c.im == 0)
    {
        printf("%g", c.re);
    }
    else if (c.im == 1)
    {
    printf("%g +  i", c.re);
    }
    
    else
    {
        printf("%g + %g i", c.re, c.im);
    }
}

// Enter complex number
void EnterComplex(complex *c)
{
    printf("Enter the real Part: ");
    scanf("%lf", &c->re);
    printf("Enter the imaginary Part: ");
    scanf("%lf", &c->im);
}


