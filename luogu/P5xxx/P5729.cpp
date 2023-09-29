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

const int MAXN = 21;
int l, w, h, q, x, y, z, x_, y_, z_, ans;
int a[MAXN][MAXN][MAXN];
void solve()
{
    cin >> l >> w >> h >> q;
    rep(i, 1, q)
    {
        cin >> x >> y >> z >> x_ >> y_ >> z_;
        rep(i, x, x_) rep(j, y, y_) rep(k, z, z_) a[i][j][k] = 1;
    }
    rep(i, 1, l) rep(j, 1, w) rep(k, 1, h) if (!a[i][j][k]) ans++;
    cout << ans;
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