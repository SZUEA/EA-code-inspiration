#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 4e5 + 10;
struct Edge
{
    int u, v, ind;
} edges[MAXN];
int n, m, k, j = 1, fa[MAXN], t[MAXN], s[MAXN], res[MAXN];
void init() { rep(i, 0, n - 1) fa[i] = i; }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void solve()
{
    cin >> n >> m;
    init();
    rep(i, 1, m) cin >> edges[i].u >> edges[i].v, edges[i].ind = 0;
    cin >> k;
    rep(i, 1, k) cin >> s[i], t[s[i]] = k - i + 1;
    rep(i, 1, m) edges[i].ind = max(t[edges[i].u], t[edges[i].v]);
    sort(edges + 1, edges + 1 + m, [](Edge a, Edge b)
         { return a.ind < b.ind; });
    int ats = n;
    rep(i, 0, k)
    {
        for (; i == edges[j].ind; j++)
        {
            int x = find(edges[j].u), y = find(edges[j].v);
            if (x ^ y)
                fa[x] = y, ats--;
        }
        res[i] = ats - k + i;
    }
    rep_r(i, k, 0) cout << res[i] << endl;
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    clock_t my_clock = clock();
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    cout << endl
         << "Time used " << clock() - my_clock << " ms." << endl;
#endif
    return 0;
}