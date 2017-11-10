#include "output.h"
#include "../qsolve/qsolve.h"
#include "../validation/validate.h"

void test(double, double, double);
void test2(char buff[]);

int main()
{
	log_start("TEST_OUTPUT", "output/test.c");
	test(0, 1, 1); // a=0
	test(1, 0, -1); // x={1, -1}
	test(1, 2, 1); // x=-1
	test(1, 1, 1); // imaginary roots

	printf("\n");
	test2("1 2 3");
	test2("1 a 3");
	test2("1 23");

	char buff[1000];
	sprintf(buff, "%Lf 2 3", ((long double)DBL_MAX)*((long double)2));
	test2(buff);

	return 0;
}

void test(double a, double b, double c)
{
	double x1, x2;
	int status = qsolve(a, b, c, &x1, &x2);

	output(status, x1, x2);
}

void test2(char buff[])
{
	double a, b, c;
	int status = validate(buff, &a, &b, &c);
	output_validation(status);
}