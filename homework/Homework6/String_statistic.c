/**
 * 4. 在主函数中由键盘任意输入一行字符串，
 * 调用自定义函数统计该字符串中字母、空格、数字和
    其他字符的个数，在主函数中输出上述的结果
*/
#include <stdio.h>
#include <string.h>

int letter = 0, number = 0, space = 0, other = 0;
void statistic(char *cs)
{
    printf("Please input a string:\n");
    for (int i = 0; i < strlen(cs); i++)
    {
        int c = cs[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            letter++;
        else if (c >= '0' && c <= '9')
            number++;
        else if (c == ' ')
            space++;
        else
            other++;
    }
}

int main()
{
    char str[1000000];
    gets(str);
    statistic(str);
    printf("Letters:%d, Digits:%d, White Spaces:%d, Others:%d", letter, number, space, other);
    return 0;
}