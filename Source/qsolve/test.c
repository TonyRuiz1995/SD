#include "qsolve.h"

void test(double, double, double);

int main ()
{
	test(1, 1, 0);
	test(1, 2, 1);
	test(1, 0, 1);
	test(0, 1, 1);
}

void test(double a, double b, double c)
{
	double x1=NAN, x2=NAN;
	int status;

	printf("a, b, c: %lf %lf %lf\n", a, b, c);
	status = qsolve(a, b, c, &x1, &x2);
	printf("\t%d: x = { %lf, %lf}\n", status, x1, x2);
}