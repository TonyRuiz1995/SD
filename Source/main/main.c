// This program pulls together functions from the 
	// other file to solve the quadratic equation
#include "../log/log.h"
#include "../output/output.h"
#include "../qsolve/qsolve.h"
#include "../validation/validate.h"
#include "../input/input.h"

int main()
{
	char buff[3000], outs[250], outs_validate[250];
	double a, b, c, x1, x2;
	int qstat, vstat;
	log_start("MAIN", "main/main.c");

	// Get user input and validate
	printf("Enter values for coefficients a, b, and c: ");
	input(buff);
	vstat = validate(buff, &a, &b , &c);
	
	// If user input is valud, print so
	if(vstat != 0)
	{
		output_validation(vstat, outs_validate);
		printf(outs_validate);
	}

	// Else print not so
	else
	{
		qstat = qsolve(a, b, c, &x1, &x2);
		output(qstat, x1, x2, outs);
		printf(outs);
	}
}