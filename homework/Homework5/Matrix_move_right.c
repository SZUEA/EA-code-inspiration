#include <stdio.h>

int main()
{
    printf("Please input 2*3 matrix below(row major):\n");
    int arr[2][3];
    for (int i = 0; i < 6; i++)
    {
        //the pointer iteration of dimension 2 array
        int *p = *arr + i;
        scanf("%d", p);
    }
    printf("Your 2*3 matrix are:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%6d", arr[i][j]);
        printf("\n");
    }
    printf("The right shifted matrix are:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%6d", arr[i][(j + 2) % 3]);
        printf("\n");
    }
    return 0;
}