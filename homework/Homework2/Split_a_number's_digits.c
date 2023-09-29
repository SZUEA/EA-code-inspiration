#include "stdio.h"
int main()
{
    int x;
    printf("Please input an integer no less than 100, no higher than 1000:");
    scanf("%d", &x);
    if (x < 100 || x > 999)
    {
        printf("InputError!");
        return 0;
    }
    printf("Its ones place is:%d\n", x % 10);
    printf("Its tens place is:%d\n", x / 10 % 10);
    printf("Its hundreds place is%d", x / 100 % 10);
    return 0;
}
