#include <stdio.h>
int main()
{
    int x;
    printf("Input m:");
    scanf("%d", &x);
    if (!x)
    {
        printf("0 is zero. It is an even number.");
        return 0;
    }
    printf("%d is a %s %s number.",
           x,
           x > 0 ? "positive" : "negative",
           x % 2 ? "odd" : "even");
    return 0;
}