#include<stdio.h>
#include<stdlib.h>

void printcards(int a[]);
int checkhand(int a[]);
void checkempty(int a);
void exchangecards(int a, int b, int c);
void randomget(int);
int countcards(int a[]);
int checkinput(int a);
void tossline(void);
void reshuffle(int a);

int ourhand[13];
int ourdiscards[13];
int comphand[13];
int compdiscards[13];

int ourselect;

int main(void)
{
	int i, compselect, result, tempresult;
	int playerwin = 0;
	int compwin = 1;
	
	for(i=0; i<13; i++)
	{
		ourhand[i] = comphand[i] = 1;
		ourdiscards[i] = compdiscards[i] = 0;
	}
	printf("Our Cards: ");
	printcards(ourhand);
	printf("Comp Cards: ");
	printcards(comphand);
	printf("Which card would you like to play? (Enter 0(A)-12(K) - q to quit):");
	
	tempresult = scanf("%d", &ourselect);
	tossline();
	result = checkinput(tempresult);
	
	while(result)
	{
		compselect = checkhand(comphand);
		printf("You chose: %d\nThe computer chose: %d\n\n", ourselect + 1, compselect);
		
		if(ourselect > compselect && compselect != 0)
		{
			exchangecards(ourselect, compselect, playerwin);
			checkempty(playerwin);
		}
		else if(ourselect < compselect && ourselect != 0)
		{
			exchangecards(compselect, ourselect, compwin);
			checkempty(compwin);
		}
		else if(ourselect == 0 && compselect != 0)
		{
			exchangecards(ourselect, compselect, playerwin);
			checkempty(playerwin);
		}
		else if(compselect == 0 && ourselect != 0)
		{
			exchangecards(compselect, ourselect, compwin);
			checkempty(compwin);
		}
		else
		{
			if(ourselect < 8 && ourselect != 0)
			{
				exchangecards(ourselect, compselect, playerwin);
				randomget(playerwin);
			}
			else
			{
				exchangecards(compselect, ourselect, compwin);
				randomget(compwin);
			}
		}
		
		printf("Our Cards: ");
		printcards(ourhand);
		printf("Comp Cards: ");
		printcards(comphand);
		printf("Our Discards: ");
		printcards(ourdiscards);
		printf("Comp Discards: ");
		printcards(compdiscards);
		if(countcards(ourhand) + countcards(ourdiscards) == 0)
		{
			printf("<<Game Over>>\n");
			break;
		}
		else if(countcards(comphand) + countcards(compdiscards) == 0)
		{
			printf("Congratulations! You win!\n");
			break;
		}
		
		printf("Which card would you like to play? (Enter 0(A)-12(K)) - q to quit:");
		tempresult = scanf("%d", &ourselect);
		tossline();
		result = checkinput(tempresult);
	}
}

void randomget(int a)
{
	int count = 0, taken = 0, selected = 0, i = 0;
	
	if(a == 0)
		count = countcards(comphand);
	else
		count = countcards(ourhand);
	
	if(count == 0)
	{
		printf("No cards to take.\n");
		reshuffle(a);
		count = countcards(!a);
		if(count == 0)
			reshuffle(!a);
	}
	else if(count == 1 || count == 2)
	{
		if(a == 0)
			for(i = 0; i < 13; i++)
			{
				ourdiscards[i] += comphand[i];
				comphand[i] -= comphand[i];
			}
		else
			for(i = 0; i < 13; i++)
			{
				compdiscards[i] += ourhand[i];
				ourhand[i] -= ourhand[i];
			}
	}
	else
	{
		if(a == 0)
			while(taken < 3)
			{
				selected = rand() % 13;
				if (comphand[selected] != 0)
				{
					ourdiscards[selected]++;
					comphand[selected]--;
					taken++;
					if(selected > 0 && selected < 10)
						printf("You randomly won a %d.\n", selected+1);
					else
						printf("You randomly won a face card.\n");
				}
			}
		else
			while(taken < 3)
			{
				selected = rand() % 13;
				if (ourhand[selected] != 0)
				{
					compdiscards[selected]++;
					ourhand[selected]--;
					taken++;
					if(selected > 0 && selected < 10)
						printf("The computer randomly won a %d.\n", selected+1);
					else
						printf("The computer randomly won a face card.\n");
				}
			}
	}
}


void reshuffle(int a)
{
	int i;
	if(a == 0)
	{
		for(i = 0; i<13; i++)
		{
			ourhand[i] = ourdiscards[i];
			ourdiscards[i] = 0;
		}
	}
	else
	{
		for(i = 0; i<13; i++)
		{
			comphand[i] = compdiscards[i];
			compdiscards[i] = 0;
		}
	}
}

int countcards(int a[])
{
	int i = 0, count = 0;
	for(i = 0; i < 13; i++)
		if(a[i] > 0)
			count += a[i];
	return count;
}

void checkempty(int a)
{
	int count = 0;
	if(a == 0)
	{
		count = countcards(comphand);
		if(count == 0)
			reshuffle(1);
		count = countcards(ourhand);
		if(count == 0)
			reshuffle(0);
	}
	else
	{
		count = countcards(ourhand);
		if(count == 0)
			reshuffle(0);
		count = countcards(comphand);
		if(count == 0)
			reshuffle(1);
	}
}

int checkinput(int a)
{
	while(1)
	{
		if(a == 0)
		{
			printf("Please enter an integer or q again to quit: ");
			a = scanf("%d", &ourselect);
			if(a == 0)
				break;
			tossline();
		}
		else if (ourselect > 12 || ourselect < 0)
		{
			printf("Number must be between 0 and 12: ");
			a = scanf("%d", &ourselect);
			tossline();
		}
		else if (ourhand[ourselect] == 0)
		{
			printf("You do not have that card. Pick another: ");
			a = scanf("%d", &ourselect);
			tossline();
		}
		else
			return a;
	}
}	

void exchangecards(int a, int b, int c)
{
	if(c == 0)
	{
		ourhand[a]--;
		ourdiscards[a]++;
		comphand[b]--;
		ourdiscards[b]++;
	}
	else
	{
		comphand[a]--;
		compdiscards[a]++;
		ourhand[b]--;
		compdiscards[b]++;
	}
}

int checkhand(int a[])
{
	int num;
	while(1)
	{
		num = rand() % 13;
		if( a[num] > 0 )
			return num;
	}
}

void printcards(int a[])
{
	int i;
	for(i=0; i<13; i++)
		if(a[i] > 0)
		{
			switch(i)
			{
				case 0:
					if(a[i] == 1)
						printf("A ");
					else
						printf("A A ");
					break;
				case 10:
					if(a[i] == 1)
						printf("J ");
					else
						printf("J J ");
					break;
				case 11:
					if(a[i] == 1)
						printf("Q ");
					else
						printf("Q Q ");
					break;
				case 12:
					if(a[i] == 1)
						printf("K");
					else
						printf("K K");
					break;
				default:
					if(a[i] == 1)
						printf("%d ", i+1);
					else
						printf("%d %d ", i+1, i+1);
			}
		}
	printf("\n");
}

void tossline(void)
{
	while(getchar()!='\n')
		continue;
}