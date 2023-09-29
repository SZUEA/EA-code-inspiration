/**
 *
 * 9. 有 n 个人围成一圈，顺序排号。从第 1 个人开始报数
 * (从 1 到 3 报数)，凡报到 3 的人退出圈
子，问最后留下的是原来第几号的那位
*/

#include <stdio.h>
int mlc, cnt, n, lim;
int num[50];
int *p;
int main()
{
    printf("请输入n=");
    scanf("%d", &n);
    p = num;
    for (mlc = 0; mlc < n; mlc++)
        *(p + mlc) = mlc + 1;
    mlc = cnt = lim = 0;
    while (lim < n - 1)
    {
        if (*(p + mlc) != 0) cnt++;
        if (cnt == 3)
        {
            *(p + mlc) = 0;
            cnt = 0;
            lim++;
        }
        if (++mlc == n) mlc = 0;
    }
    while (*(p++) == 0);
    printf("最后一个人是原来第%d号\n", *(p - 1));
    return 0;
}