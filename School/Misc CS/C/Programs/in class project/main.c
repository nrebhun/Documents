#include <stdio.h>

int main (void) 

{
	char first;
	char second;
	char third;
	int a;
	int b;
	int c;
	
	scanf("%c %d \n" ,&first ,&a);
	scanf("%c %d \n" ,&second ,&b);
	scanf("%c %d" ,&third ,&c);
	
	printf("%c \t %c \t %c \n" ,first ,second ,third);
	printf("The average is %d. \n" ,((a+b+c)/3));
	return 0;
}