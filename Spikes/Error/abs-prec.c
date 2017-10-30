
#include<stdio.h>
#include<curses.h>
#include<math.h>
#define MAX 5

void main()
{
	//clrscr();
	float d[MAX],b,c,a[MAX];
	for(int i=0;i<=5;i++)
	 {
		 printf("Please Enter a Value\n");
		 scanf("%f",&a[i]);
		 printf("Please Enter a second value to compare errors\n");
		 scanf("%f",&d[i]);
		 
		  b=(a[i]-d[i])/d[i];
		  printf(" The Relative Error is: %f \n",b);
		 
		  c=(a[i] -d[i]);
		  printf("The Absolute Error is: %f\n",c);
		 
		
	 }
 }
