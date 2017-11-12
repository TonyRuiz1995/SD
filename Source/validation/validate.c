#include "validate.h"
int isNumeric(char*);
int validate(char buff[], double* a, double* b, double* c)
{
	char params[3300];
	sprintf(params, "buff='%s'", buff);
	myLog("valdiate.c", "valdiate", params);

	// Makes sure there are 3 inputs to be read
	char a_s[1000], b_s[1000], c_s[1000];
	if(sscanf(buff, "%s %s %s", a_s, b_s, c_s) != 3)
		return 1;

	// Makes sure all three are numeric
	if(!isNumeric(a_s) || !isNumeric(b_s) || !isNumeric(c_s))
		return 2;

	// Converts to quad to double
	*a = strtold(a_s, NULL);
	*b = strtold(b_s, NULL);
	*c = strtold(c_s, NULL);

	// Check to make sure if in double range
	if(fabs(*a) >= FLT_MAX || fabs(*b) >= FLT_MAX || fabs(*c) >= FLT_MAX)
		return 3;
	
	return 0;
}

int isNumeric(char *str)
{
   while(*str != '\0')
   {
       if(*str < '0' || *str > '9')
           if(*str != '.')
               return false;
       str++;
   }
   return true;
}
