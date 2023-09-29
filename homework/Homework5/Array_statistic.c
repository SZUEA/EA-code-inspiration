#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    int arr[10];
    float avg = 0.0;
    printf("请输入该整数数组:\n");
    for (int i = 0; i < 10; avg += *(arr + i) / 10.0, i++)
        scanf("%d", arr + i);
    int *max = arr, *min = arr;
    for (int i = 1; i < 10; i++)
    {
        max = *max < *(arr + i) ? arr + i : max;
        min = *min > *(arr + i) ? arr + i : min;
    }
    printf("平均值为:%f\n", avg);
    printf("最大值为:%d\t位置为:arr[%d]\n", *max, max - arr);
    printf("最小值为:%d\t位置为:arr[%d]\n", *min, min - arr);
    swap(min, max);
    printf("调整后数组为:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", *(arr + i));
    return 0;
}