
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define endl '\n'
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
const ll INFF = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 1e5 + 5;
int n; // 节点数
map<int, int> mp[MAXN];
set<pii> edges[MAXN];
ll dis[MAXN];
bool state[MAXN];

void addEdge(int u, int v, int w)
{
    if (!mp[u].count(v))
        mp[u][v] = w, edges[u].insert({v, w}); // 原本无边,直接建边
    else
    { // 有重边
        if (w < mp[u][v])
        {                                  // 新边的边权更小
            edges[u].erase({v, mp[u][v]}); // 删除旧边
            mp[u][v] = w;                  // 记录新边的边权
            edges[u].insert({v, w});       // 建边
        }
    }
}

void dijkstra(int s)
{
    memset(dis, INFF, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    dis[s] = 0;
    heap.push({0, s});
    while (heap.size())
    {
        auto [d, u] = heap.top();
        heap.pop();
        if (state[u])
            continue;
        state[u] = true;
        for (auto [v, w] : edges[u])
        {
            if (dis[v] > d + w)
            {
                dis[v] = d + w;
                heap.push({dis[v], v});
            }
        }
    }
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
    for (int i = 1; i <= n; i++)
        cout << (dis[i] == INFF ? (1 << 31) - 1 : dis[i]) << ' ';
    return 0;
}