/**
 * 5. 有一个已经排好序(升序)的整型数组，
 * 要求从键盘输入一个整数后，按原来排序的规律将它
 *插入到数组中，并输出结果。如原数组为:1,3,5,7，
 *需插入整数 4，则新数组为 1,3,4,5,7
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[100000], *ptr, *retptr;
int c = -1, arr[1000], len = 0, ins, tmp;
int main()
{
    printf("原数组为(用单个空格隔开每一个数):\n");
    gets(str);
    //相当于split(String reg)方法,给arr赋值
    ptr = str;
    while ((retptr = strtok(ptr, " ")) != NULL)
    {
        arr[len] = atoi(retptr);
        ptr = NULL;
        len++; 
    }
    printf("输入要插入的数字:");
    scanf("%d", &ins);
    while (c++ < len)
        if (*(arr + c) > ins)//寻找插入口
        {
            int k = c;//存储插入下标
            while (len - (c++ - k) >= k)
                //倒序，将第n+1个数赋予第n个数的值
                *(arr + len - (c - 1 - k)) = *(arr + len - (c - k));
            *(arr + k) = ins;
        }
        else if (c == len)
            *(arr + c) = ins;//插入数最大，插在尾部
    printf("新数组为:\n");
    for (int q = 0; q < len + 1; q++)
        printf("%d ", arr[q]);
    return 0;
}