#include <stdio.h>
#include <math.h>
int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < i; j++)
			printf("       ");
		for (int j = i; j < 10; j++)
			printf("%c*%c=%-3d", i + '0', j + '0', i * j);
		printf("\n");
	}
	return 0;
}