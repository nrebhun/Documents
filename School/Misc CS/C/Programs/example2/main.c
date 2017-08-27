#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float get_number(void);

int main(int argc, char *argv[])
{
    float mynum;
	
    // This is pretty straightforward
    printf("Please enter a number: ");
    mynum = get_number();
    printf("You typed in: %f\n", mynum);
    // Done!
    return 0;
}

// Feel free to rename this function
float get_number(void)
{
    double value;
    char mybuffer[256];
    char *ptr;
	
    while (1)
    {
        // Okay, so this line will scan a string up to the first whitespace
        // character encountered
        scanf("%s", mybuffer);
        // This is necessary for error checking
        ptr = mybuffer + strlen(mybuffer);
        // Try to convert
        value = strtod(mybuffer, &ptr);
        // Is it valid?
        if (ptr != mybuffer)
        {
            // Valid number! Rejoice!
            return value;
        }
        else
        {
            // FAIL!
            printf("That is not a valid number. Please try again: ");
        }
    }
}
