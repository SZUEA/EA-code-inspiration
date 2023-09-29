#include <stdio.h>
#include <math.h>
int main()
{
	for (int i = '!'; i <= '>'; i++)
	{
		printf("%c  ", i);
		if (!((i - '!' + 1) % 10))
			printf("\n");
	}
	return 0;
}
