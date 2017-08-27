#include <stdio.h>

int main (void) 

{
	float num;
	
	printf("I am a program designed to see if a number you give me is positive or negative");
	printf("Please enter a number. (If you don't give a damn, enter '0') \n");
	
    while (scanf("%d", &num))
	{
		if(num > 0)
			printf("Congratulations! You picked a positive number! \n");
			
			else if(num = 0)
				printf("Congratulations! You have entered 0. Because this number holds no value, it is neither"),
				printf("positive or negative!\n");
				
				else if(num < 0)
					printf("Congratulations! You picked a negative number!\n");
		scanf("%d", &num);
	}
	
	
	return 0;
}
