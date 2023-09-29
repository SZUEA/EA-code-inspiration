#include <stdio.h>
int main()
{
    //(1/2)*(1/4)*(1/6)*...(1/18)*(1/20)
    double eps = 1;
    for (int i = 2; i <= 20; i += 2)
        eps /= i;
    printf("The result is:%g\n", eps);
    return 0;
}