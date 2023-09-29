/**
 * 在主函数中由键盘输入 3 阶的方阵。调用子函数
 *  arrSum()完成如下两个功能： ①求此方阵
主对角线(左上->右下)上各个元素之和，并将此和值作
为子函数的返回值返回；②并将此方
阵的全部元素重新赋值成这个和值。在主函数中
重新输出修改后的方阵
*/
#include <stdio.h>
#include <string.h>
int arrSum(int *arr)
{
    int sum = *(arr + 0) + *(arr + 4) + *(arr + 8);
    for (int i = 0; i < 9; i++)
        *(arr + i) = sum;
    return sum;
}
int main()
{
    int arr[3][3];
    printf("请输入一个3*3方阵:\n");
    for (int i = 0; i < 9; i++)
        scanf("%d", *arr + i);
    printf("对角线上数值和为:%d\n", arrSum(*arr));
    printf("调整后方阵为:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}