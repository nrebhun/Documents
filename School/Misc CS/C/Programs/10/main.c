#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
	char first, second, third;
	
	printf("\n Welcome! \n");
	printf("Please enter your initials:\n");
	
	scanf("%c" ,&first);
	
	if (first != 'G') {
		printf("Access Denied: \nYour input was invalid. \nGoodbye.\n");
		return 0;
	}
	
	scanf("%c" ,&second);
	
	if (second != 'A') {
		printf("Access Denied: \nYour input was invalid. \nGoodbye.\n");
		return 0;
	}
	
	scanf("%c" ,&third);
	
	if (third != 'M') {
		printf("Access Denied: \nYour input was invalid. \nGoodbye.\n");
		return 0;
	}
	
	printf("Access Granted! \n");
	printf("Welcome, Gabby Miseroy! \n");
	printf("\n");
	printf("\n");
	printf("\n");
	
	printf(" Happy Tenth Monthiversary! \n");
	printf("     ♥♥♥♥♥♥    ♥♥♥♥♥♥     \n");
	printf("   ♥♥♥♥♥♥♥♥♥  ♥♥♥♥♥♥♥♥♥   \n");
	printf("  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥  \n");
	printf("  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥  \n");
	printf("   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥   \n");
	printf("    ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥    \n");
	printf("     ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥     \n");
	printf("      ♥♥♥♥♥♥♥♥♥♥♥♥♥♥      \n");
	printf("        ♥♥♥♥♥♥♥♥♥♥        \n");
	printf("         ♥♥♥♥♥♥♥          \n");
	printf("           ♥♥            \n");
	printf("      I love you ♥        \n");
}

