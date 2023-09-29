#include <stdio.h>
#include <math.h>

int func1(int n)
{
	int i = 0;
	if (n == 0)
	{
		i = 1;
		return i;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return i;
}

void func2(int n)
{
	printf("这个数的逆序数字为：");
	if (n == 0)
	{
		printf("%d\n", n);
		return;
	}
	while (n != 0)
	{
		printf("%d", n % 10);
		if (n != 1)
		{
			printf(",");
		}

		n /= 10;
	}
	printf(" ");
}

int func3(int n)
{
	int i = 0;
	if (n == 0)
	{
		i = 0;
		return i;
	}
	while (n != 0)
	{
		i += n % 10;
		n /= 10;
	}
	return i;
}
int main()
{
	int n;
	printf("请输入一个正整数:");
	scanf("%d", &n);
	printf("n是%d位数, ", func1(n));
	func2(n);
	printf("数字之和为%d", func3(n));
	return 0;
}