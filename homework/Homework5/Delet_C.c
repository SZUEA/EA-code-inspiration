#include <stdio.h>
#include <string.h>
//编写程序实现将用户输入的字符串中所有的'c'或'C'字符删除，并输出结果。
int main()
{
    char input[10000];
    int cnt = -1;
    printf("请输入字符串:\n");
    gets(input);
    printf("删除c和C后字符串为:\n");
    while (input[++cnt] != '\0')
        if (input[cnt] != 'c' && input[cnt] != 'C')
            printf("%c", input[cnt]);
    return 0;
}