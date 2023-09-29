/**
8. 编制函数 jsSort()，函数的功能是：对字符串变量
下标为奇数的字符按其 ASCII 值从大到小
的顺序进行排序，排序后的结果仍存入该字符串数组中。例如
0 1 2 3 4 5 6 7
a b c d e f g h
a h c f e d g b
*/
#include <stdio.h>
#include <string.h>
char str[1000000];
void sort()
{
    for (int i = 1; i < strlen(str); i += 2)
        for (int j = 1; j < i; j += 2)
            if (str[i] > str[j])
            {
                int temp = str[j];
                str[j] = str[i];
                str[i] = temp;
            }
}
int main()
{
    printf("请输入一个字符串:\n");
    gets(str);
    sort();
    printf("该字符串变换为:\n");
    puts(str);
    return 0;
}