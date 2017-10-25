#include "input.h"

void input (double* a, double* b, double* c)
{
	int status = 0;
	while(status != 1){
		printf("Please input a double value for a: ");
	    status = scanf("%lf", a);
	}

	status = 0;
	while(status != 1){
		printf("Please input a double value for b: ");
	    status = scanf("%lf", b);
	}

	status = 0;
	while(status != 1){
		printf("Please input a double value for c: ");
	    status = scanf("%lf", c);
	}
}