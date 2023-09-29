#include <stdio.h>
int main()
{
    long long n, a;
    printf("Please input n and a:");
    scanf("%lld%lld", &n, &a);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long unit = a;
        for (int j = 0; j < i; j++)
        {
            unit *= 10;
            unit += a;
        }
        sum += unit;
    }
    printf("The result is:%lld", sum);
    return 0;
}