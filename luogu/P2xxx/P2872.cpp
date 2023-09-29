#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;
typedef double db;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define endl '\n'
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
const ll INFF = 0x3f3f3f3f3f3f3f;
const int MN = 1010, MM = 1010*1010;
int n, m;

struct Edge
{
    int u, v;
    db w;
} es[MM];
int fa[MN];
pdd pt[MN];
int vis[MN][MN];
void init()
{
    rep(i, 1, n)
        fa[i] = i;
}

int fnd(int x) { return x == fa[x] ? x : fa[x] = fnd(fa[x]); }

db kruskal()
{
    init();
    int _n = n * (n - 1) / 2;
    sort(es + m + 1, es + _n + 1, [](Edge a, Edge b)
         { return a.w < b.w; });
    db res = 0.0;
    int cnt = 0;
    rep(i, 1, _n)
    {
        int u = es[i].u, v = es[i].v;
        db w = es[i].w;
        u = fnd(u), v = fnd(v);
        if (u != v)
        {
            fa[u] = v;
            if (i > m)
                res += sqrt(w);
            cnt++;
        }
    }
    return cnt < n - 1 ? INFF : res;
}

db dis_2(pdd a, pdd b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> m;
    rep(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        pt[i] = {x, y};
    }
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        es[i] = {u, v, dis_2(pt[u], pt[v])};
        vis[u][v] = 1;
    }
    int cnt = m;
    rep(i, 1, n) rep(j, i, n) if (!vis[i][j] && !vis[j][i] && i != j)
        es[++cnt] = {i, j, dis_2(pt[i], pt[j])};
    db ans = kruskal();
    cout << setiosflags(ios::fixed) << setprecision(2) << ans;
    return 0;
}