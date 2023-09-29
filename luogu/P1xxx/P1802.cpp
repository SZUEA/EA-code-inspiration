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

const int MAXN = 1010;
ll f[MAXN][MAXN];
int n, m, w[MAXN], a[MAXN], b[MAXN];
void solve()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> b[i] >> a[i] >> w[i];
    rep(i, 1, n) rep(j, 0, m) if (j >= w[i])
        f[i][j] = max(f[i - 1][j - w[i]] + a[i], f[i - 1][j] + b[i]);
    else f[i][j] = f[i - 1][j] + b[i];
    cout << f[n][m] * 5;
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