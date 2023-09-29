#include <stdio.h>
int main()
{
    int x;
    printf("Please input an integer:");
    scanf("%d", &x);
    if (!(x % 3 || x % 5))
        printf("It can be divided completely by 3 or 5 .");
    else if (!(x % 3))
        printf("It can be divided completely by 3 .");
    else if (!(x % 5))
        printf("It can be divided completely by 5 .");
    else
        printf("It can't be divided completely by 3 or 5 .");
    return 0;
}