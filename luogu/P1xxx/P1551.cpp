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

const int MAXN = 5e3 + 10;
int n, m, q, x, y;
int f[MAXN];

int getRoot(int o)
{
    return f[o] == o ? o : f[o] = getRoot(f[o]);
}
void solve()
{
    cin >> n >> m >> q;
    rep(i, 1, n) f[i] = i;
    rep(i, 1, m) cin >> x >> y, f[getRoot(x)] = getRoot(y);
    rep(i, 1, q) cin >> x >> y, cout << (getRoot(x) == getRoot(y) ? "Yes" : "No") << endl;
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