/**
 * 2. 自己编制子函数实现字符串连接函数 strcat()的功能，
 * 将字符串 srcStr 连接到字符串
dstStr 的尾部。在 main()中调用并验证。
*/
#include <stdio.h>
#define N 100
inline void strcat(char *s1, char *s2)
{
    char *p1 = s1 - 1, *p2 = s2 - 1;
    while (*(++p1) != '\0');
    while (*(++p2) != '\0')
        *(p1++) = *p2;
    *p1 = '\0';
}
int main()
{
    char dstStr[N];
    char srcStr[N];
    printf("请输入一个字符串dstStr:\n");
    gets(dstStr);
    printf("请输入一个字符串srcStr:\n");
    gets(srcStr);
    strcat(dstStr, srcStr);
    puts(dstStr);
    return 0;
}
