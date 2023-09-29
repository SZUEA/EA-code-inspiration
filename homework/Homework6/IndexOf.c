/**
 * 9. 编写函数 strLoc()，功能是求得一字符串
 * str1 在另一个字符串 str2 中首次出现的位置，例
如 str1 为”do”，str2 为”how do you do?”时，
返回值为 4。str1 不在 str2 中，返回-1
*/
#include <stdio.h>
#include <string.h>

int strLoc(char *s, char *a)
{
    int ls, la, i;
    int flag = -1;
    ls = strlen(s);
    la = strlen(a);
    if (la > ls)
        return -1;
    for (i = 0; i <= ls - la; i++)
        if (strncmp(s + i, a, la) == 0)
            return i;
    return flag;
}

int main()
{
    char str2[1000000], str1[1000000];
    printf("请输入一个字符串:\n");
    gets(str2);
    printf("请输入查找字符串:\n");
    gets(str1);
    printf("%d", strLoc(str2, str1));
    return 0;
}