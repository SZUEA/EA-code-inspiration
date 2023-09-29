#include <stdio.h>
#include <string.h>
#define N 1000
int arr[N] = {0};
int main()
{
	for (int i = 1, t = 0; i <= 1000; i++)
	{
		t = 0;
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sum += j;
				arr[t++] = j;
			}
		}
		if (i == sum)
		{
			printf("%d its factors are ", sum);
			t = 0;
			while (arr[t] != 0)
			{
				printf("%d", arr[t++]);
				if (arr[t])
					printf(", ");
			}
			printf("\n");
		}
		memset(arr, 0, N);
	}
	return 0;
}