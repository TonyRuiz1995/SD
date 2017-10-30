//tokenize buffer using strtok and validate integer values

#include<string.h>
#include<stdio.h>
#include <stddef.h>
#include <stdlib.h>       
#include <ctype.h>

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

int isNumeric(const char *str)
{
   while(*str != '\0')
   {
       if(*str < '0' || *str > '9')
           if(*str != '.')
               return -1;
       str++;
   }
   return 1;
}
