#include "stdio.h"
#include "math.h"
int main()
{
    int a, b;
    printf("Please input an integer a:");
    scanf("%d", &a);
    printf("Please input an integer b:");
    scanf("%d", &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After changing:a = %d , b = %d", a, b);
    return 0;
}
