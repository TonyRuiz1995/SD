#include "output.h"

void output(int status, double x1, double x2)
{
	char params[255];
	sprintf(params, "status=%d, x1=%lf, x2=%lf", status, x1, x2);
	myLog("output.c", "output", params);

	switch(status)
	{
		case 0: printf("x = {%lf, %lf}\n", x1, x2); break;
		case 1: printf("x = {%lf}\n", x1); break;
		case 2: printf("Imaginary Roots!\n"); break;
		case 3: printf("a=0\n"); break;
	}
}

void output_validation(int status)
{
	switch(status)
	{
		case 0: printf("Input is valid.\n"); break;
		case 1: printf("Not enough numbers entered!\n"); break;
		case 2: printf("Not all input are numbers!\n"); break;
		case 3: printf("Numbers are too big!\n"); break;
	}
}