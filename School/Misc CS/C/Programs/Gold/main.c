#include <stdio.h>

int main (int argc, const char * argv[]) 

{
	float weight;						//user's weight
	float value;
	
	printf("Are you worth your weight in gold?\n");
	printf("Please enter your weight in pounds to find out!\n");
	
	scanf("%f" , &weight);
	
	value = 14960 * weight;
	
	printf("Your weight in gold is worth $%.2f .\n" ,value);
	printf("You are easily worth that! If gold prices drop, \n");
	printf("eat more to maintain your value! \n");
	
	return 0;
}