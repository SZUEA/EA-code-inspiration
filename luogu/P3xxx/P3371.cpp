#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define endl '\n'
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
const ll INF = 0x3f3f3f3f;

const int MN = 1e5 + 5;
int n;
map<int, int> mp[MN];
set<pair<int, int>> edges[MN];
ll dis[MN];
bool state[MN];

void addEdge(int u, int v, int w)
{
    if (!mp[u].count(v))
        mp[u][v] = w, edges[u].insert({v, w});
    else
    {
        if (w < mp[u][v])
        {
            edges[u].erase({v, mp[u][v]});
            mp[u][v] = w;
            edges[u].insert({v, w});
        }
    }
}

void dijkstra(int s)
{
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    rep(i, 0, n - 1)
    {
        int t = -1, j;
        rep(j, 1, n) if (!state[j] && (t == -1 || dis[t] > dis[j]))
            t = j;
        if (j == n)
            break;
        state[t] = true;
        for (auto [v, w] : edges[t])
            dis[v] = min(dis[v], dis[t] + w);
    }
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int m, s;
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijkstra(s);
    rep(i, 1, n)
        cout << (dis[i] == INF ? (1 << 31) - 1 : dis[i]) << ' ';
    return 0;
}