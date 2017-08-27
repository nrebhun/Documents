#include <stdio.h>
#include <math.h>

int main () {
    
	int integer;			//the integer the user initially enters
	int integerTotal;		//the number of data values entered
	int integerSum;			//the sum of the values entered
	int integerAvg;		//the average of the values entered
	int integerMin;			//the smallest value entered
	int integerMax;			//the largest value entered
	int maxCount;			//number of occurrences of the largest value
	int superNum;			//the largest integer in absolute value entered
	int negCount;			//the number of negative values entered
	int oddCount;			//the number of odd values entered
	
    printf("Please enter an integer. \n");
	scanf("%d" ,&integer);
	
	while(integer != 0){
		
		if (integer < 0) {
			negCount++;
		}
		
		if (integer > integerMax) {
			integerMax = integer;
			maxCount = 1;
		}
		
		else if (integer < integerMin){
			integerMin = integer;
			
		}
		
		integerTotal++;
		integerSum = integer + integerSum;
		
		double fabs(double integer);
		
		if ( integer > superNum){
			superNum = integer;
		}
		
		printf("Please enter another integer. \n");
		scanf("%d" ,&integer);
	}
	
	integerAvg = integerSum/integerTotal;
	
	printf("You entered %d numbers." ,integerTotal);
	printf("The sum of all integers entered is %d." ,integerSum);
	printf("The average of all integers entered is %d." ,integerAvg);
	printf("The smallest value entered is %d." ,integerMin);
	printf("The largest value entered is %d." ,integerMax);
    return 0;
}