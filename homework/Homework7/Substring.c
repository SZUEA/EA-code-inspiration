/**
 * 3. 有一字符串，包含 n 个字符。写一子函数 copystr()，
 * 将此字符串中从第 m(m<=n)个字符开
始的全部字符复制成为另一个字符串。
*/
#include <stdio.h>

void copystr(char *origin, int startIndex, char *copy)
{
    char *p1 = origin - 1 + startIndex, *p2 = copy;
    while (*(++p1) != '\0')
        *(p2++) = *p1;
    *p2 = '\0';
}

int main()
{
    char str[1000000], strcpy[1000000];
    int m;
    printf("请输入一个字符串:\n");
    gets(str);
    printf("请输入开始截取位置:");
    scanf("%d", &m);
    copystr(str, m - 1, strcpy);
    printf("截取的字符串为:\n");
    puts(strcpy);
    return 0;
}