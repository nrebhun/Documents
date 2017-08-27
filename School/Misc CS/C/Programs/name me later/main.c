#include <stdio.h>

int main (int argc, const char * argv[])
{
	float inches;
	float feet;
	float value;
	
	int age;
	
	age = 71;
	
	printf("\n");
	printf("Happy %dst Birthday, Grandpa Bob! \n" ,age);				  //change later?
	printf("Before we get started, I just need to ask a few questions... \n");	  //add questions?(beyond this point)
	printf("First off, how many feet tall are you? (do NOT include inches) \n");
	printf("Press Enter when finished. \n");
	
	scanf("%f" ,&feet);					//to acquire height (feet only) from user
	
	printf("Thank you! \n");
	printf("Now I need to know how many inches taller than %.0f feet you are. \n" ,feet);
	
	scanf("%f" ,&inches);				//to acquire height (inches only) from user
	
	printf("Great! \n");
	
	value = 15124032000/(inches+(feet*12));		//formula for calculating # of clones the user needs to reach the moon
	
	printf("Cool fact: If you had about %.0f clones, you could stand on each others' \n" ,value);
	printf("shoulders and touch the moon! \n");
	printf("\n");
	
return 0;
}