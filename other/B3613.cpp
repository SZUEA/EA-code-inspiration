#include <bits/stdc++.h>
using namespace std;
int n, u, v, p, m;
vector<int> to[500010];
int main()
{
    cin >> n;
    while (n--)
    {
        scanf("%d %d", &p, &m);
        for (int o = 1; o <= p; o++)
            to[o].clear();
        for (; m--; to[u].push_back(v))
            scanf("%d%d", &u, &v);
        for (int i = 1; i <= p; i++)
            sort(to[i].begin(), to[i].begin() + to[i].size());
        for (int x = 1; x <= p; x++, printf("\n"))
            for (int y = 0; y < to[x].size(); y++)
                printf("%d ", to[x][y]);
    }
    return 0;
}