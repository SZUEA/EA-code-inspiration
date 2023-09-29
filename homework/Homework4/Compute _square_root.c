#include <stdio.h>
#include <math.h>
int main()
{
	double a=0;
	double x0,x1;
	printf("Please input an integer:");
	scanf("%lf",&a);  
	x0 = 0;
	x1 = 1;
	while(fabs(x0-x1)>=1e-6)
	{
		x0 = x1;
		x1 =  0.5*(x0 + a/x0);
	}
	printf("%.0lf's square root is:%lf",a,x1);
}
