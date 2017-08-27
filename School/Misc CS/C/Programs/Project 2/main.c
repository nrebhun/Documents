#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_choice(void);
float get_number(void);

int calculator(void)
{
	int choice;
	int idnum1;
	int idnum2;
	int remainder;
	float num1;
	float num2;
	
	
	while((choice = get_choice()) != 'q')
	{
					switch (choice)
			{
				case 'a' :	printf("Please enter a number: \n");			//for addition
							num1 = get_number();
							printf("Please enter a second number: \n");
							num2 = get_number();
							printf("%.1f+%.1f=%.1f \n \n",num1 ,num2 ,num1+num2);		//displays entered numbers, the operation used, and the result
							break;
					
				case 's' :	printf("Please enter a number: \n");			//for subtraction
							num1 = get_number();
							printf("Please enter a second number: \n");
							while (1)				//for "will not accept zero" portion of subtraction operation
							{
								num2 = get_number();
								if (num2 == 0)
								{
									printf("Error: subtracting 0 from a number is pointless. Please enter a different number: ");
								}
								else
								{
								break;
								}
							}
							printf("%.1f-%.1f=%.1f \n \n",num1 ,num2 ,num1-num2);		//displays entered numbers, the operation used, and the result
					
							break;
					
				case 'm' :	printf("Please enter a number: \n");			//for multiplication
							num1 = get_number();
							printf("Please enter a second number: \n");
							num2 = get_number();
							printf("%.1f*%.1f=%.1f \n \n",num1 ,num2 ,num1*num2);		//displays entered numbers, the operation used, and the result
							break;
					
				case 'd' :	printf("Please enter a number: \n");			//for division
							num1 = get_number();
							printf("Please enter a second number: \n");
							num2 = get_number();
							printf("%.1f/%.1f=%.1f \n \n",num1 ,num2 ,num1/num2);		//displays entered numbers, the operation used, and the result
					
							break;
					
				case 'i' :	printf("Please enter a number: \n");			//for integer division
							idnum1 = get_number();
							printf("Please enter a second number: \n");
							idnum2 = get_number();
							printf("%d/%d=%d \n \n",idnum1 ,idnum2 ,idnum1/idnum2);		//displays entered numbers, the operation used, and the result
							break;
					
				case 'o':	printf("Please enter a number: \n");			//for modulus
							idnum1 = get_number();
							printf("Please enter a second number: \n");
							idnum2 = get_number();
							remainder = idnum1 % idnum2;
							printf("The modulus of %d and %d is %d \n \n" ,(int)idnum1 ,(int)idnum2 ,(int)remainder);		//displays entered numbers, the operation used, and the result
							break;
			}
					
		}
	
		
	
}

char get_choice(void)					//the menu
{
    int ch;
	
    printf("Enter the letter of your choice: \n");
    printf("a. addition			s. subtraction \n");
    printf("m. multiplication		d. division \n");
    printf("i. integer division		o. modulus \n");
    printf("q. quit \n");
	
	ch = getchar();
	getchar();
	return ch;

}

float get_number(void)					//the anti-letter function
{
    double value;
    char buffer[1];
    char *ptr;
	
    while (1)
    {
        scanf("%s" , buffer);								//scan the first number entered in the string
        ptr = buffer + strlen(buffer);			//check for error
        value = strtod(buffer, &ptr);			//try to convert
		
        if (ptr != buffer)						//check if input is a valid number
		{
			getchar();
            return value;
        }
        else
        {
            printf("Error: That is not a number. Please try again: \n"); 
        }
    }
}