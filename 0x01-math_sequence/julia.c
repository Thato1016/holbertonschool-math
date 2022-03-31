#include "julia.h"

/**
* add - add complex
* @a: complex
* @b: complex
* Return: complex
*/

complex add(complex a, complex b)
{
	complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

/**
* sqr - sqr complex
* @a: complex
* Return: complex
*/

complex sqr(complex a)
{
	complex c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

/**
* modulus - modulus of complex
* @a: complex
* Return: complex
*/

double modulus(complex a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

/**
* drawp - detremine point
* @width: canva w
* @height: canva h
* @radius: distance
* @x: int
* @y: int
* Return: complex
*/

complex drawp(int width, int height, double radius, int x, int y)
{
	complex c;
	int l = (width < height) ? width : height;

	c.x = 2 * radius * (x - width / 2.0) / l;
	c.y = 2 * radius * (y - height / 2.0) / l;

	return (c);
}

/**
* julia - do the julia
* Return: void
* @width: canva w
* @height: canva h
* @c: complex
* @radius: distance factor
* @n: iterations
*/

void julia(int width, int height, complex c, double radius, int n)
{
int x, y, i;
complex z0, z1;
FILE *pgmimg;

printf("Holberton School\n");
printf("Julia's set image created in julia.pgm file\n\n");
printf("Test: ./julia 800 800 0 0 1.4 60 for circle\n");
printf("Test: ./julia 800 800 -0.50 0.55 1.4 60 for tardigrade like\n");
printf("Test: ./julia 1200 1200 -0.646 0.408 1.3 100 for Unespected beauty\n");
printf("Test: ./julia 1200 1200 -0.70 0.26 1.3 100 for More beauty\n");
pgmimg = fopen("julia.pgm", "wb");
fprintf(pgmimg, "P2 \n");
fprintf(pgmimg, "%d %d \n", width, height);
fprintf(pgmimg, "255 \n");

	for (x = 0; x < width; x++)
	{
		for (y = 0; y < height; y++)
		{
		z0 = drawp(width, height, radius, x, y);
			for (i = 1; i <= n; i++)
			{
				z1 = add(sqr(z0), c);
				if (modulus(z1) > radius)
				{
					fprintf(pgmimg, " 16 ");
					break;
				}
				z0 = z1;
			}
			if (i > n)
			{
				fprintf(pgmimg, " 255 ");
			}
		}
	fprintf(pgmimg, "\n");
	}
fclose(pgmimg);
}
