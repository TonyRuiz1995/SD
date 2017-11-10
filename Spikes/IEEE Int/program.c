#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>

#define add(l, r) printf("%d + %d = %d\n", l, r, l + r)
#define sub(l, r) printf("%d - %d = %d\n", l, r, l - r)
#define mult(l, r) printf("%d * %d = %d\n", l, r, l * r)
#define div(l, r) printf("%d / %d = %d\n", l, r, l / r)
#define println() printf("\n");

int main()
{
	// Casts
	printf("(int)%e = %d\n", NAN, (int)NAN);
	printf("(int)%e = %d\n", INFINITY, (int)INFINITY);
	printf("(int)%e = %d\n", -INFINITY, (int)(-INFINITY));
	printf("(int)FLT_MAX = %d\n", (int)FLT_MAX);
	printf("(int)DBL_MAX = %d\n", (int)DBL_MAX);
	println();
	
	// Max Int
	printf("INT_MAX = %d\n", INT_MAX);
	add(INT_MAX, 1);
	sub(-INT_MAX, 1);
	sub(-INT_MAX, 2);
	mult(INT_MAX, INT_MAX);
	div(INT_MAX, INT_MAX);
	
	printf("%d / %d = ", 1, 0);
	fflush(stdout);
	printf("%d", 1/0);
	println();
	
	return 0;
}