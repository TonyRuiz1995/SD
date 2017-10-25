#include "qsolve.h"

/* qsolve: takes in coefficient values and outputs an array
	returns: status
		0: 2 real roots
		1: 1 real root
		2: complex roots
		3: a = 0
	parameters:
		a, b, c: coefficients
		*x1, *x2: roots
*/
int qsolve(double a, double b, double c, double* x1, double* x2)
{
	int status = 0;
	double disc = b*b - 4*a*c;

	if(a== 0){
		status = 3;
	}
	else if(disc < 0){
		status = 2;
	}
	else if(disc == 0){
		status = 1;
		*x1 = b/(-2*a);
		*x2 = *x1;
	}
	else{;
		*x1 = ((-1*b)+sqrt(disc)) / (2*a);
		*x2 = ((-1*b)-sqrt(disc)) / (2*a);
	}

	return status;
}