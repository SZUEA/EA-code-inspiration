/**
 * 10.计算字符串中子串出现的次数。
 * 要求：用一个子函数 subString()实现,参数为指向该字符串
和要查找的子串的指针,返回次数
*/
#include <stdio.h>
#include <string.h>
int subString(char *str, char *query)
{
    int ls, la, i, cnt = 0;
    ls = strlen(str);
    la = strlen(query);
    for (i = 0; i <= ls - la; i++)
        if (strncmp(str + i, query, la) == 0)
            cnt++;
    return cnt;
}

int main()
{
    char str2[1000000], str1[1000000];
    printf("请输入一个字符串:\n");
    gets(str2);
    printf("请输入查找字符串:\n");
    gets(str1);
    printf("str1在str2中出现了%d次", subString(str2, str1));
    return 0;
}