#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int countdown;
	
	while(countdown != 'q')
	{
		printf("Enter an integer to start the countdown! (enter 'q' to explode)\n");
		scanf("%d" ,&countdown);
			while(countdown != 0)
			{
				printf("%d... \n" ,countdown--);
			}
	}
	return 0;
}