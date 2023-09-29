/**
 * 编程判断输入的一串字符是否为“回文”，
 * 所谓“回文”是指顺读和倒读都一样的字符串，如
level，ABCCBA 都是回文
*/

#include <stdio.h>
#include <string.h>

int isRound(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (*(str + i) != *(str + len - i-1))
            return 0;
    return 1;
}

int main()
{
    char str[1000000];
    printf("请输入一个字符串:\n");
    gets(str);
    printf("该字符串%s回文串", isRound(str) ? "是" : "不是");
    return 0;
}