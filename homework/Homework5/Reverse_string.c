#include <stdio.h>
#include <string.h>
/*
8. 由键盘任意输入一行字符串，将该字符串在原字符数
组里逆序存放(不使用另外的字符数组)，
并输出
*/
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    char str[100];
    printf("请输入一个字符串:\n");
    gets(str);
    for (int i = 0; i < strlen(str) / 2; i++)
        swap(str + i, str + strlen(str) - i - 1);
    printf("逆序字符串为:\n");
    printf("%s", str);
    return 0;
}