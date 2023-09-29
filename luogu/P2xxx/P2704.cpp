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

const int MAXN = 110;
const int MAXM = 1 << 10;

int f[MAXN][MAXM][MAXM], g[MAXN], s[MAXM], num[MAXM], n, m, cnt;

char c;
void solve()
{
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> c, g[i] = (g[i] << 1) + (c == 'P');
    rep(i, 0, (1 << m) - 1) if (!(i & i >> 1) && !(i & i >> 2))
    {
        s[cnt++] = i;
        rep(j, 0, m - 1) num[i] += (i >> j & 1);
    }
    rep(i, 1, n + 2) rep(a, 0, cnt - 1) rep(b, 0, cnt - 1) 
    rep(c, 0, cnt - 1) if (!(s[a] & s[b]) && !(s[a] & s[c]) && !(s[b] & s[c]) 
    && (g[i] & s[a]) == s[a] && (g[i - 1] & s[b]) == s[b])
        f[i][a][b] = max(f[i][a][b], f[i - 1][b][c] + num[s[a]]);
    cout << f[n + 2][0][0];
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