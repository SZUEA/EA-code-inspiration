#include <stdio.h>
#include <string.h>
/**
 * 
 * 4. 编写一程序，其功能是给一维数组 a 输入任意的 6 个整数，
 * 假设为：5 7 4 8 9 1，然后建
    立一个具有以下内容的方阵，并打印出来。
    5 7 4 8 9 1
    1 5 7 4 8 9
    9 1 5 7 4 8
    8 9 1 5 7 4
    4 8 9 1 5 7
    7 4 8 9 1 5
 * */
int main()
{
    printf("Please input 6 integers:\n");
    int arr[6];
    for (int i = 0; i < 6; i++)
        scanf("%d", arr + i);
    int arr_[6][6];
    /**
     * 代码解释:两层循环代表二维数组遍历
     * *(*(arr_) + i + j):第i行第j列元素
     *  *(arr + (i - i / 6) % 6):arr数组整体右移的操作
     */
    for (int i = 0; i < 36; i++)
        *(*arr_ + i) = *(arr + (i - i / 6) % 6);
    for (int i = 0; i < 36; i++)
    {
        printf("%d ", *(*arr_ + i));        //遍历二维数组并输出
        printf(!((i + 1) % 6) ? "\n" : ""); //每隔6高换行一次
    }

    return 0;
}