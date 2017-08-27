#include <stdio.h>
#include <string.h>
#define STARS "***"
int main (void)
{
	char first[40], last[40]; 
	char middle; 
	
	printf("Please enter your first name, middle initial, and last name.\n");
	
	scanf("%s %c %s" ,first ,&middle ,last);
	
	printf("There are %d letters in your first name.\n" ,strlen(first));
	printf("%d is the ASCII value of %c.\n" ,middle ,middle);
	printf("%s%s%s" ,STARS ,last ,STARS);
	return 0;
}
