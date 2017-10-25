#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

/* function declaration*/
double square(double a, double b, double c);
void output(double result,double a, double b);


int main(){

   	//a,b,c are variables
   	//flag will determine whether or not input is valid for a quadratic equation
   	bool loop = false;
   	while(!loop){
		double a,b,c,result;
		printf("Please input a double value for a: ");
	    	scanf("%lf", &a);
	    	printf("Please input a double value for b: ");
	    	scanf("%lf", &b);
	    	printf("Please input a double value for c: ");
	    	scanf("%lf", &c);
    	
   		result = square(a,b,c); //first call to square====sqrt(b^2-4ac)
	   	if(a == 0){
	   	printf("A cannot be 0");
	   	}
		else if ( result == -1.0){
			printf("Select other numbers");
		}
		else {
		loop = true;
		output(result,a,b);
		}//end else
	}//end while
   return 0;
}

//will take ints a,b,c and do stuff

double square(double a, double b, double c) {

   /* local variable declaration */
	double result;
	
	double b_sq = pow(b,2);
   	if (4*a*c > b_sq){
      	   printf("ERROR: IMAGINARY NUMBER, PLEASE ENTER VALID NUMBERS\n");
      	   return -1.0;
      	 }
	else{
	   result = b_sq - 4*a*c;
      	   return sqrt(result);
      	}
}
//calculate the first 
void output(double result, double a, double b){
	double x1 = 0.0;
	double x2 = 0.0;

	x1 = ((-1*b + result)/(float)(2*a));
	x2 = ((-1*b - result)/(float)(2*a));
	printf("x1 is %lf \n", x1);
	printf("x2 is %lf \n", x2);
}


