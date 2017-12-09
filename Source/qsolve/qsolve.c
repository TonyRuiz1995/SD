// This applies the qaudratic formula
#include "qsolve.h"

// qsolve: takes in coefficent values and outputs the roots
	// a, b, c: coefficients
	// x1, x2: (out) root values outputed
	// returns status indicating output cases
		// 0: 2 real roots
		// 1: 1 real root
		// 2: imaginary roots
		// 3: a=0
int qsolve(double a, double b, double c, double* x1, double* x2)
{
	char params[256];
	sprintf(params, "a=%lf b=%lf c=%lf", a, b, c);
	my_log("qsolve.c", "qsolve", params);

	int status = 0;
	double disc = b*b - 4*a*c;

	if(a == 0)
		status = 3;
	else if(disc < 0)
		status = 2;
	else if(disc == 0)
	{
		status = 1;
		*x1 = b/(-2*a);
		*x2 = *x1;
	}
	else
	{
		*x1 = ((-1*b)+sqrt(disc)) / (2*a);
		*x2 = ((-1*b)-sqrt(disc)) / (2*a);
	}

	return status;
}
