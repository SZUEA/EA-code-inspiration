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

const int N = 21;

int d[N];
ll pow101[N], tmp[N];
int build(ll x0)
{
    int n = 1;
    ll x = x0;
    d[1] = x % 10;
    x /= 10;
    for (; x; x /= 10)
        d[++n] = x % 10;
    pow101[0] = 1, tmp[0] = 0;
    rep(i, 1, n) pow101[i] = pow101[i - 1] * 10, tmp[i] = x0 % pow101[i] + 1;
    return n;
}
ll cnt(int cur, bool lim)
{
    return lim ? tmp[cur] : pow101[cur];
}
int f[N];
bool vis[N];
int num;
ll dfs(int cur, bool lim, bool zero)
{
    if (cur == 1)
        return lim ? d[1] >= num : 1;
    if (lim == 0 && zero == 0)
    {
        if (vis[cur])
            return f[cur];
        vis[cur] = 1;
    }
    ll ans = 0;
    int ed = lim ? d[cur] : 9;
    rep(i, 0, ed)
    {
        ans += dfs(cur - 1, lim && i == ed, zero && i == 0) + (!(zero && i == 0) && i == num ? cnt(cur - 1, lim && i == ed) : 0);
    }
    if (lim == 0 && zero == 0)
        f[cur] = ans;
    return ans;
}

ll ans[N];
void solve()
{
    ll l, r;
    cin>>l>>r;
    int n = build(l - 1);
    rep(i, 0, 9)
    {
        num = i;
        ans[i] = dfs(n, 1, 1);
    }
    memset(vis, 0, sizeof(vis));
    n = build(r);
    rep(i, 0, 9)
    {
        num = i;
        ans[i] = dfs(n, 1, 1) - ans[i];
    }
    rep(i, 0, 9)cout<<ans[i]<<' ';
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