#include "output.h"
#include "../qsolve/qsolve.h"

void test(double, double, double);

int main()
{
	log_start("TEST_OUTPUT", "output/test.c");
	test(0, 1, 1); // a=0
	test(1, 0, -1); // x={1, -1}
	test(1, 2, 1); // x=-1
	test(1, 1, 1); // imaginary roots

	return 0;
}

void test(double a, double b, double c)
{
	double x1, x2;
	int status = qsolve(a, b, c, &x1, &x2);

	output(status, x1, x2);
}