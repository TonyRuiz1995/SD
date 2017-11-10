#include "../log/log.h"
#include "../output/output.h"
#include "../qsolve/qsolve.h"
#include "../validation/validate.h"
#include "../input/input.h"

int main()
{
	char buff[3000];
	double a, b, c, x1, x2;
	int qstat, vStat;
	log_start("MAIN", "main/main.c");

	printf("Enter values for coefficients a, b, and c: ");
	input(buff);
	vStat = validate(buff, &a, &b , &c);
	
	if(vStat != 0)
	{
		output_validation(vStat);
	}
	else
	{
		qstat = qsolve(a, b, c, &x1, &x2);
		output(qstat, x1, x2);
	}
}