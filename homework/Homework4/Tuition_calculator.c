#include <stdio.h>
#include <math.h>
int main()
{
	printf("Year    Current Tuition($)        Total Tuition($)\n");
	double a1 = 10000.00;
	double ratio = 1.05;
	for (int i = 0; i < 10; i++, a1 *= ratio)
	{
		double sum = 0;
		for (int k = 0; k < 4; k++)
			sum += a1 * pow(ratio, k);
		printf("%4d    %18.2lf        %16.2lf\n", i + 1, a1, sum);
	}
	return 0;
}