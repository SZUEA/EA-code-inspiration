#include <stdio.h>
#include <string.h>
/*
3. 在主函数中由键盘任意输入一行字符串，
调用子函数 inv()实现将该字符串在原字符数组中逆
序存放。在主函数中重新输出修改后的字符串。
*/
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void inv(char *str)
{
    for (int i = 0; i < strlen(str) / 2; i++)
        swap(str + i, str + strlen(str) - i - 1);
}
int main()
{
    char str[100000];
    printf("请输入一个字符串:\n");
    gets(str);
    inv(str);
    printf("逆序字符串为:\n");
    puts(str);
    return 0;
}