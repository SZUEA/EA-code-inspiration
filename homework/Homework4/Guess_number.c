#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	printf("Game Start!\n");
	printf("Please input a number to guess:\n");
	srand((unsigned)time(NULL));
	int ok = rand() % 100 + 1;
	int t = 0, flag = 0;
	while (t++ < 7)
	{
		int att;
		scanf("%d", &att);
		if (att > ok)
			printf("Higher\n");
		else if (att < ok)
			printf("Lower\n");
		else
		{
			flag = 1;
			break;
		}
	}
	printf(flag ? "You won!" : "You lost!");
	return 0;
}