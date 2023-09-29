#include "stdio.h"
int main()
{
    int _in;
    printf("Please input an integer:");
    scanf("%d", &_in);
    printf("%d's octal form is:%o\n", &_in, &_in);
    printf("%d's hexadecimal form is:%x", &_in, &_in);
    return 0;
}
