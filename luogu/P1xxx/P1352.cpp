#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
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

const int MAXN = 6e3 + 10;
vector<int> arr[MAXN];
int u, v, n, r, dp[MAXN][2], cnt[MAXN];
bitset<MAXN> findroot;
void dfs(int node)
{
    for (auto &&c : arr[node])
    {
        dfs(c);
        dp[node][0] += max(dp[c][0], dp[c][1]);
        dp[node][1] += dp[c][0];
    }
}

void solve()
{
    cin >> n, findroot.set();
    rep(i, 1, n) cin >> dp[i][1];
    rep(i, 1, n - 1) cin >> u >> v, cnt[v]++, arr[v].push_back(u), findroot[u - 1] = 0;
    dfs(r = (findroot._Find_first() + 1));
    cout << max(dp[r][0], dp[r][1]);
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