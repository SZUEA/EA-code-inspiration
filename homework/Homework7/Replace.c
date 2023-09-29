/**
 * 4. 字符替换。要求用子函数 replace()将用户输入
 * 的字符串中的所有字符 b/B 都替换为 c/C，
并返回总共替换字符的个数。
*/
#include <stdio.h>

int replace(char *str)
{
    int cnt = 0;
    char *p1 = str - 1;
    while (*(++p1) != '\0')
        switch (*p1)
        {
        case 'b':
            *p1 = 'c';
            cnt++;
            break;
        case 'B':
            *p1 = 'C';
            cnt++;
        default:
            break;
        }
    return cnt;
}

int main()
{
    char str[1000000];
    printf("请输入一个字符串:\n");
    gets(str);
    int c = replace(str);
    printf("替换b/B的字符串为:\n");
    puts(str);
    printf("替换b/B的字符个数:%d", c);
    return 0;
}