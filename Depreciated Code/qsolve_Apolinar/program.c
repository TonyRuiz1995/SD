#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* findRoots (double[], int*);

int main()
{
	double coeffs[4];
	int i, result, count;

	printf("Enter in the coefficient for 'a', 'b', and 'c': ");
	result = scanf("%lf %lf %lf", &coeffs[0], &coeffs[1], &coeffs[2]);
	printf("%lf %lf %lf\n", coeffs[0], coeffs[1], coeffs[2]);
	
	if(result == EOF)
	{
		perror("End of File!");
		exit(0);
	}
	else if(result < 3)
	{
		perror("Error reading from stdin");
		exit(0);
	}

	double* roots = findRoots(coeffs, &count);

	switch(count)
	{
		case 0: 
			printf("Imaginary roots!\n"); break;
		case 1: 
			printf("x = {%lf}\n", roots[0]); break;
		case 2: 
			printf("x = {%lf, %lf}\n", roots[0], roots[1]); break;		
	}

	return 0;
}

// Needs further testing
double* findRoots(double coeffs[], int* count)
{
	double sqPart = pow(coeffs[1], 2) - 4 * coeffs[0] * coeffs[2];
	double* ret;

	if(sqPart < 0)
	{
		*count = 0;
		ret = malloc(0);
	}
	else if(sqPart == 0)
	{
		*count = 1;
		ret = malloc(sizeof(double)*1);
		ret[0] = coeffs[1] / (-2 * coeffs[0]);
	}
	else
	{
		*count = 2;
		ret = malloc(sizeof(double)*2);
		ret[0] = (pow(sqPart, 0.5) - coeffs[1]) / (2 * coeffs[0]);
		ret[1] = ((-1 * pow(sqPart, 0.5)) - coeffs[1]) / (2 * coeffs[0]);
	}

	return ret;
}
