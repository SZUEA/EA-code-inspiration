#include <bits/stdc++.h>
using namespace std;
#define N 100
int n, m;
set<int> tree[N];
int vis[N] = {0};
queue<int> Q;
void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        set<int> un;
        tree[x].insert(y);
    }
}

void dfs(int i = 1)
{
    if (vis[i])
        return;
    vis[i] = 1;
    cout << i << " ";
    for (auto p : tree[i])
        dfs(p);
}

void bfs()
{
    cout << endl;
    memset(vis, 0, sizeof(vis));
    Q.push(1);
    while (!Q.empty())
    {
        int th = Q.front();
        Q.pop();
        if (vis[th])
            continue;
        vis[th] = 1;
        printf("%d ", th);
        for (auto p : tree[th])
            Q.push(p);
    }
}

int main()
{
    init();
    dfs();
    bfs();
    return 0;
}