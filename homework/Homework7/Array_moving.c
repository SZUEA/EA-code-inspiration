/**
 * 1. 输入 10 个整数，将其中最小的数与第一个数对换，
 * 把最大的数与最后一个数对换。写 3 个子
函数分别实现这三个功能：①输入 ②进行处理；③输出 10 个数
*/
#include <stdio.h>
#include <string.h>

int arr[10];
void read()
{
    printf("请输入一个整数数组:\n");
    for (int *i = arr; i < arr+10; i++)
        scanf("%d", i);
}
void process()
{
    int *max = arr, *min = arr;
    for (int i = 1; i < 10; i++)
    {
        max = *max < *(arr + i) ? arr + i : max;
        min = *min > *(arr + i) ? arr + i : min;
    }
    int t = *min;
    *min = *arr;
    *arr = t;
    if (arr == max)
    {
        t = *min;
        *min = *(arr + 9);
        *(arr + 9) = t;
    }
    else
    {
        t = *max;
        *max = *(arr + 9);
        *(arr + 9) = t;
    }
}
void write()
{
    printf("操作后整数数组为:\n");
    for (int *i = arr; i < arr+10; i++)
        printf("%d ", *i);
}

int main()
{
    read();
    process();
    write();
    return 0;
}