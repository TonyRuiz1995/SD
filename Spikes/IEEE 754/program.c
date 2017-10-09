#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>

#define add(l, r) printf("%e + %e = %e\n", l, r, l + r);
#define sub(l, r) printf("%e - %e = %e\n", l, r, l - r);
#define mult(l, r) printf("%e * %e = %e\n", l, r, l * r);
#define div(l, r) printf("%e / %e = %e\n", l, r, l / r);
#define printn(n) printf("%.1f\n", n);
#define println() printf("\n");

int main()
{
	// Infinity
	sub(INFINITY, INFINITY);
	div(INFINITY, INFINITY);
	div(0.0, INFINITY);
	mult(INFINITY, -1.0);
	mult(INFINITY, 0.0);
	mult(INFINITY, 2.0);
	println();

	// NaN
	add(NAN, INFINITY);
	add(NAN, 0.0);
	mult(NAN, INFINITY);
	println();

	// Divide by 0
	div(1.0, 0.0);
	div(-1.0, 0.0);
	println();

	// Max Double
	printf("DBL_MAX = %e\n", DBL_MAX);
	add(DBL_MAX, 1.0);
	add(DBL_MAX, pow(10, 308));
	sub(-1*DBL_MAX, pow(10, 308));
	mult(DBL_MAX, 0.0);

	println();
	div(1.0, DBL_MAX);
	div(1.0/DBL_MAX, pow(10.0, 15));
	div((1.0/pow(10.0, 15))/DBL_MAX, 10.0);
	printf("10e+309 = %e\n", pow(10, 309));

	return 0;
}