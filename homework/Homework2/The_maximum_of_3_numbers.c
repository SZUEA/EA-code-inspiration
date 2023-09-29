#include "stdio.h"
int main()
{
    double a, b, c;
    printf("PLease input 3 numbers:");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("The maximum is:%lf", a > b ? a > c ? a : c : b > c ? b : c);
    return 0;
}
