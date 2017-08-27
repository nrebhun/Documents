#include <stdio.h>
#include <stdlib.h>

void printhand(int a[])

int main(void);
{

	int ourhand[13];
	int comphand[13];
	int ourdiscard[13];
	int compdiscard[13];
	int checkempty; 
	int i;
	int ourselect;
	int compselect;
	int result;
	for (i=0, i<13; i++)
		
	{
		ourhand[i] = comphand[i] = 1;
		ourdiscard[i] = compdiscard[i] = 1;
	}

	while(result)
	{
		compselect = checkhand();
		if(ourselect > compselect)			//if user wins
		{
			ourhand[ourselect]--;
			ourdiscard[ourselect]++;
			comphand[compselect]--;
			ourdiscard[compselect]++;
			checkempty(i);
		}
		else(if(compselect > ourselect))		//if computer wins
		{
			ourhand[ourselect]--;
			compdiscard[ourselect]++;
			comphand[compselect]--;
			compdiscard[compselect]++;
			checkempty(i)
		}
		else(if(compselect = ourselect))		//if tie
		{
			if(i<9)							//if tie, <9 (user wins)
			{
				ourhand[ourselect]--;
				ourdiscard[ourselect]++;
				comphand[compselect]--;
				ourdiscard[compselect]++;
				checkempty(i);
			}
			else(if(i<8))
			{
				ourhand[ourselect]--;
				compdiscard[ourselect]++;
				comphand[compselect]--;
				compdiscard[compselect]++;
				checkempty(i)
			}
		}