// Checks to make sure that the given input is valid
#include "validate.h"

// Simple function that detects if a string is a number
int is_numeric(char *str)
{
   while(*str != '\0')
   {
       if(*str < '0' || *str > '9')
       {
           if(*str != '.' && *str != '-')
               return false;
       }
       str++;
   }
   return true;
}

// Makse sure that the input is valid and reads it into numbers
	// buff: buffer to read numbers from
	// a, b, c: (out) numbers to read into 
	// returns status indicating output cases
		// 0: valid inputs
		// 1: not enough numbers entered
		// 2: not all input is numeric
		// 3: numbers are beyond float values
int validate(char buff[], double* a, double* b, double* c)
{
	char params[3300];
	sprintf(params, "buff='%s'", buff);
	my_log("valdiate.c", "valdiate", params);

	// Makes sure there are 3 inputs to be read
	char a_s[1000], b_s[1000], c_s[1000];
	if(sscanf(buff, "%s %s %s", a_s, b_s, c_s) != 3)
		return 1;

	// Makes sure all three are numeric
	if(!is_numeric(a_s) || !is_numeric(b_s) || !is_numeric(c_s))
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


