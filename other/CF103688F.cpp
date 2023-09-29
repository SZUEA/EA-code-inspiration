#include <stdio.h>
#include <string.h>
const int N = 20;
const int INFF = 0x3f3f3f3f;
inline int min(int a, int b)
{
    return a < b ? a : b;
}
int dis[N][N];
int main()
{
    int n = 7;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = i == j ? 0 : INFF;
        }
    }

    dis[1][2] = dis[2][1] = 1;
    dis[1][3] = dis[3][1] = 1;
    dis[2][4] = dis[4][2] = 1;
    dis[3][4] = dis[4][3] = 1;
    dis[5][4] = dis[4][5] = 1;
    dis[6][4] = dis[4][6] = 1;
    dis[5][7] = dis[7][5] = 1;
    dis[6][7] = dis[7][6] = 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    int s;
    scanf("%d", &s);
    for (int i = 0; i < s; i++)
    {
        int a1, b1, a2, b2;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        int ans = dis[a1][b1] + dis[a2][b2];
        ans = min(ans, dis[a1][b2] + dis[a2][b1]);
        printf("%d\n", ans);
    }

    return 0;
}
