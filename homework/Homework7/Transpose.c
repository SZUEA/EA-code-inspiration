/**
 * 8. 写一子函数 transpose()，可以将一个 3*3 的整型矩阵转置
 */
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void transpose(int *mt)
{
    swap(mt + 1, mt + 3);
    swap(mt + 2, mt + 6);
    swap(mt + 5, mt + 7);
}
int main()
{
    int mat[3][3];
    for (int i = 0; i < 9; i++)
        scanf("%d", *mat + i);
    transpose(*mat);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", *(*mat + i));
        printf((i + 1) % 3 == 0 ? "\n" : "");
    }
    return 0;
}