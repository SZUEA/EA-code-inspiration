/**
 * 7. 定义函数 getData()用于接收键盘输入的一组整型数据，
 * 并放入一数组中；另外再定义一个
函数 sort()用于对输入的这一组数据按照降序排列。
主函数先后调用 getData()和 sort()
函数，输出最后的排序结果
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[100000], *ptr, *retptr;
int arr[1000], len = 0;
void getData()
{
    printf("输入一个数组(用单个空格隔开每一个数):\n");
    gets(str);
    //相当于split(String reg)方法,给arr赋值
    ptr = str;
    while ((retptr = strtok(ptr, " ")) != NULL)
    {
        arr[len] = atoi(retptr);
        ptr = NULL;
        len++;
    }
}
void sort()
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
}
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    getData();
    sort();
    printf("该数组的降序排列为:\n");
    for (int i = 0; i < len; i++)
        printf("%d ", *(arr + i));
    return 0;
}