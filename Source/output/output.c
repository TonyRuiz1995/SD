#include "output.h"

void output(int status, double x1, double x2, char outs[])
{
	char params[255];
	sprintf(params, "status=%d, x1=%lf, x2=%lf", status, x1, x2);
	myLog("output.c", "output", params);

	switch(status)
	{
		case 0: sprintf(outs, "x = {%lf, %lf}\n", x1, x2); break;
		case 1: sprintf(outs, "x = {%lf}\n", x1); break;
		case 2: sprintf(outs, "Imaginary Roots!\n"); break;
		case 3: sprintf(outs, "a=0\n"); break;
	}
}

void output_validation(int status, char outs[])
{
	char params[255];
	sprintf(params, "status=%d", status);
	myLog("output.c", "output_validation", params);

	switch(status)
	{
		case 0: sprintf(outs, "Input is valid.\n"); break;
		case 1: sprintf(outs, "Not enough numbers entered!\n"); break;
		case 2: sprintf(outs, "Not all input are numbers!\n"); break;
		case 3: sprintf(outs, "Numbers are too big!\n"); break;
	}
}