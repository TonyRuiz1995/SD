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
/*
char *strtok_r(char *str, const char *delim, char **saveptr);
int checkNum(char * a);

int main(){

char input[] = "123.232 12222.22 43333.222";
char * delim = " ";
char *saveptr1;
char *header = strtok_r(input, delim, &saveptr1);
char **dataArr = malloc(3);
char a[1000], b[1000], c[1000] = {}; //size is 1000
//printf(" %s\n", header);
int i = 0;
  for (i=0; i< 2; i++) {
    dataArr[i] =  strtok_r(NULL, delim, &saveptr1);
    if (dataArr[i] == NULL)
        break;
 //   printf(" %s\n", dataArr[i]);
  }

//need some sort of error checking for buffer overflow
strcat(a,header);
strcat(b,dataArr[0]);
strcat(c,dataArr[1]);

printf(" %s\n",a);
printf(" %s\n",b);
printf(" %s\n",c);

if (isNumeric(a) == -1) printf("A is not a number\n");
if (isNumeric(b) == -1) printf("B is not a number\n");
if (isNumeric(c) == -1) printf("C is not a number\n");
free(dataArr);
}



*/