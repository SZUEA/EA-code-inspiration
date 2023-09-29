#include <stdio.h>
int main()
{
    printf("Please input a character:");
    char c = getchar();
    if (c <= 'Z' && c >= 'A')
        printf("You've input an uppercase letter:%c", c);
    else if (c <= 'z' && c >= 'a')
        printf("You've input a lowercase letter:%c", c);
    else if (c <= '9' && c >= '0')
        printf("You've input a digit:%c", c);
    else
        printf("You've input some other character:%c", c);
    return 0;
}