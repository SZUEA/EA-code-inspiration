/**
 * 由键盘输入两个字符串 s1 和 s2 并做比较：若 s1 和 s2 完全一致，
 * 输出 0；否则输出这两个字符串第一个不相同字符的差值。
    如”Ad”和”Chs”比较输出-2，”AB”和”ABC”比较输出
    -67，”Ans”和”Aid”比较输出 5
*/
#include <stdio.h>
#include <string.h>
inline int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    char s1[100000], s2[100000];
    printf("请输入两个字符串:\ns1:\n");
    gets(s1);
    printf("s2:\n");
    gets(s2);
    for (int i = 0; i < min(strlen(s1), strlen(s2)); i++)
    {
        if (s1[i] != s2[i])
        {
            printf("差值为:%d", s1[i] - s2[i]);
            return 0;
        }
    }
    if (strlen(s1) > strlen(s2))
        printf("差值为:%d", s1[strlen(s1) - 1]);
    else if (strlen(s1) < strlen(s2))
        printf("差值为:%d", -1 * s2[strlen(s2) - 1]);
    else
        printf("差值为:%d", 0);
    return 0;
}