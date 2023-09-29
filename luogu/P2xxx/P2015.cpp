#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)


const int MAXN = 100;
int n, m, u, v, w;
ll ans;
bool vis[MAXN];
int tree[MAXN][MAXN], dp[MAXN][MAXN];
vector<int> kid[MAXN];

void dfs(int node)
{
    vis[node] = 1;
    for (auto &&c : kid[node])
    {
        if (vis[c])
            continue;
        vis[c] = 1;
        dfs(c);
        rep_r(i, m, 1) rep_r(j, i - 1, 0)
            dp[node][i] = max(dp[node][i], dp[c][j] + dp[node][i - j - 1] + tree[node][c]);
    }
}
void solve()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> u >> v >> w;
        tree[u][v] = tree[v][u] = w;
        kid[u].pb(v), kid[v].pb(u);
    }
    dfs(1);
    cout<<dp[1][m];
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