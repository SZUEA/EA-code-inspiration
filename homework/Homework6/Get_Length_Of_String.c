/**
 * 自己编写一个函数，可以求一个字符串的长度。
 * 在 main()函数中输入字符串，调用此自定义
    函数，并输出其长度
*/
#include <stdio.h>
inline int len(char *str)
{
    int cnt = 0;
    while (*(str + cnt) != '\0') cnt++;
    return cnt;
}
int main()
{
    char str[100000];
    printf("请输入一个字符串:\n");
    gets(str);
    printf("字符串长度为:%d",len(str));
    return 0;
}