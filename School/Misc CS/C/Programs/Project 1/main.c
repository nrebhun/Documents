//Nick Rebhun, Compsci-235, Worland, Summer 2009
#include <stdio.h>

int main (void) 
{
	float cent;
	float meter;
	float feet;
	float inch;
	
	printf("Enter a height in centimeters \n");
	
	while (scanf("%f" ,&cent ) > 0 && cent > 0)
	
	{
		meter= cent/100;
		feet= cent/2.54/12;
		inch= (feet-(int)feet)*12;
		
		printf("%.1f cm = %.2f meters, or  %i feet and %.1f inches \n" ,cent ,meter ,(int)feet ,inch);
		printf("Enter a height in centimeters: \n");
	}
}