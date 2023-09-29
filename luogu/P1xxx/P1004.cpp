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

const int MAXN = 10;

int f[MAXN][MAXN][MAXN][MAXN];
int mp[MAXN][MAXN];
int n, x, y, v;
void solve()
{
    cin >> n;
    while (1)
    {
        cin >> x >> y >> v;
        if(x) mp[x][y] = v; else break;
    }
    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) rep(l, 1, n)
    {
        f[i][j][k][l] = max(f[i - 1][j][k - 1][l], max(f[i - 1][j][k][l - 1], max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])));
        if (i == k && j == l) f[i][j][k][l] += mp[i][j];
        else f[i][j][k][l] += mp[i][j] + mp[k][l];
    }
    cout << f[n][n][n][n] << endl;
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