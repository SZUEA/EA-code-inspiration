
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
const int MOD = 1e6 + 7;
const int MAXN = 110;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN << 1];
int n, m;

void solve()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> b[i];
    rep(i, a[1], b[1]) c[i] = 1;
    rep(i, 2, n)
    {
        rep(j, 0, m) rep(k, 0, b[i]) d[j + k] += c[j];
        rep(j, 0, m) c[j] = d[j] % MOD, d[j] = 0;
    }
    cout << c[m];
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