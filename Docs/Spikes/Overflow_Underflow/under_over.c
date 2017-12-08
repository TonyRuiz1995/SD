//Underflow and overflow spike

#include <stdlib.h>
#include <stdio.h>
int main(){

//formula for overflow: TYPE_MIN_LIMIT+(CURRENT_VALUE – TYPE_MAX_LIMIT) – 1
//formula for underflow: TYPE_MAX_LIMIT – (CURRENT_VALUE – TYPE_MIN_LIMIT) +1
	 short int x=-32768; //min for short int
	 short int y=32767; //max for short int
	 printf("-------------\n");
	 printf("Displaying type limits for signed short int\n");
	 printf("%d\n",x);
	 printf("%d\n",y);
	 printf("-------------\n");
	 printf("Displaying type limits +/- 1 for signed short int\n");
	 short int x1=-32769;
	 short int y1=32768;
	 printf("%d\n",x1); //UNDERFLOW: TYPE_MIN_LIMIT -1 = RESULT: TYPE_MAX_LIMIT
 	 printf("%d\n",y1); //OVERFLOW: TYPE_MAX_LIMIT +1 = RESULT: TYPE_MIN_LIMIT
 	 printf("-------------\n");
	 printf("Displaying underflow for 40000\n");
 	 short int neg_curr = -40000;
 	 short int pos_curr = 40000;
 	 printf("OVERFLOW : 40,000: %d\n",pos_curr); //result : -25536
 	 printf("UNDERFLOW : -40,000: %d\n",neg_curr); //result : -25536
 	 short int UNDERFLOW_formula = x + (neg_curr-y)-1;
 	 short int OVERFLOW_formula = y - (neg_curr - x) + 1;
 	 printf("%d\n", OVERFLOW_formula); //formula for overflow 
	 printf("%d\n", UNDERFLOW_formula); //formula for overflow 
	 
 	 printf("-------------\n\n\n");
	 printf("Displaying type limits for floats\n");
	 
	 float max = 3.4e38;
	 float min = -3.4e38;
	 
	 printf("%f\n",max);
	 printf("%f\n",min);
	 
	 printf("Displaying type limits +/- 1 for floats\n");
	 
 	 float max_overflow = max + 1.00;
	 float min_underflow = min - 1.00;
	 printf("%f\n",min_underflow); //UNDERFLOW: TYPE_MIN_LIMIT -1 = RESULT: TYPE_MAX_LIMIT
 	 printf("%f\n",max_overflow); //OVERFLOW: TYPE_MAX_LIMIT +1 = RESULT: TYPE_MIN_LIMIT
 	 
	 return 0;
}

