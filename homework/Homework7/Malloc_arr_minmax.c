/**
 * 由用户从键盘输入数据的个数 n，
 * 利用动态分配内存的方法建立数组，
 * 从键盘输入 n 个整数存
入数组。调用子函数 swap()将最大、
最小值位置互换。然在主函数中重新输出调整后的数组
*/

#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    int n, *p;
    printf("请输入数据个数:");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    int *max = p, *min = p;
    printf("请输入数据:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
        max = *max < *(p + i) ? p + i : max;
        min = *min > *(p + i) ? p + i : min;
    }
    swap(max, min);
    printf("处理后数据为:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(p + i));
    free(p);
    return 0;
}