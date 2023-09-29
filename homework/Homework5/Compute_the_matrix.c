#include <stdio.h>
#include <string.h>

int main()
{
    printf("Please input 4*4 matrix below(row major):\n");
    int arr[4][4];
    for (int i = 0; i < 16; i++)
    {
        // the pointer iteration of dimension 2 array
        int *p = *arr + i;
        scanf("%d", p);
    }
    int _sum = 0, sum_ = 0, sum[4];
    memset(sum, 0, sizeof(sum));
    printf("The sums of each row are:");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            _sum += (i == j ? arr[j][i] : 0);
            sum_ += (3 - i == j ? arr[i][j] : 0);
            *(sum + i) += arr[j][i];
        }
        printf("%d ", *(sum + i));
    }
    printf("\nThe sum of the diagonal nums is:%d", _sum);
    printf("\nThe sum of the subdiagonal nums is:%d", sum_);
    return 0;
}