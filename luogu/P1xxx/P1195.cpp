#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define endl '\n'
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
const ll INFF = 0x3f3f3f3f3f3f3f3f;

const int MN = 5005, MM = 2e5 + 5;
int n, m, k;

struct Edge
{
    int x, y, l;
} es[MM];
int fa[MN];

void init()
{
    rep(i, 1, n)
        fa[i] = i;
}

int fnd(int x) { return x == fa[x] ? x : fa[x] = fnd(fa[x]); }

ll kruskal()
{
    init();
    sort(es, es + m, [](Edge a, Edge b)
         { return a.l < b.l; });
    ll res = 0;
    int cnt = 0;
    rep(i, 0, m)
    {
        int u = es[i].x, v = es[i].y, w = es[i].l;
        u = fnd(u), v = fnd(v);
        if (u != v)
        {
            fa[u] = v;
            res += w;
            cnt++;
        }
        if(cnt==n-k){
            return res;
        }
    }
    return INFF;
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> m>>k;
    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[i] = {u, v, w};
    }
    ll ans = kruskal();
    cout << (ans == INFF ? "orz" : to_string(ans));
    return 0;
}