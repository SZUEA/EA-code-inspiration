/**
 * 7. 字符串的左旋转操作是把字符串前面的若干个
 * 字符转移到字符串的尾部。请定义一个函数实现
字符串左旋转操作的功能。比如，输入字符串"abcdefg"
和数字 2，该函数将返回左旋转两位
得到的结果"cdefgab"。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *spinLeft(char *str, int m)
{
    int len = strlen(str);
    char *p = (char *)malloc(len * sizeof(char));
    char *p_ = p;
    char tmp;
    for (int i = 0; i < len; i++, p_++)
        *p_ = *(str + (i + m) % len);
    *(p + len) = '\0';
    return p;
}

int main()
{
    char str[1000000];
    int m;
    printf("请输入一个字符串:\n");
    gets(str);
    printf("请输入左旋位数:\n");
    scanf("%d", &m);
    printf("结果为:\n");
    puts(spinLeft(str, m));
    return 0;
}