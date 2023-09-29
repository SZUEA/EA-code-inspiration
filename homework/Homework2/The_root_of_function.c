#include "stdio.h"
#include "math.h"
int main()
{
    double a, b, c;
    printf("Please input the three attribution:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    printf("THe root is:\n");
    printf("x1=%lf\n", (-1 * b + sqrt(b * b - 4 * a * c)) / 2 / a);
    printf("x2=%lf", (-1 * b - sqrt(b * b - 4 * a * c)) / 2 / a);
    return 0;
}
