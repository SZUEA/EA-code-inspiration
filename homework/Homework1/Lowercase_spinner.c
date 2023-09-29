#include <stdio.h>
int main()
{
    char x;
    printf("Please input a lowercase letter:");
    scanf("%c", &x);
    printf("%c's front index letter is:%c\n", x, x == 'a' ? x + 25 : x - 1);
    printf("%c's back index letter is:%c\n", x, x == 'z' ? x + 25 : x + 1);
    return 0;
}