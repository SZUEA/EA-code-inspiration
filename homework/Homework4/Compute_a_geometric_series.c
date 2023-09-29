#include <stdio.h>
#include <math.h>
int main()
{
    double a1 = 3.14;  // The first element
    double rate = 2.0; // The ratio
    double sum = 0.0;  // The answer
    for (int i = 0; i < 10; i++)
        sum += a1 * pow(rate, i);
    printf("The sum of the series is:%lf", sum);
    return 0;
}