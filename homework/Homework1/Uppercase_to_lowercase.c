#include <stdio.h>
int main()
{
    char t;
    printf("Please input a capital:");
    scanf("%c", &t);
    printf("Its lowercase form is:%c", t - 32);
    return 0;
}