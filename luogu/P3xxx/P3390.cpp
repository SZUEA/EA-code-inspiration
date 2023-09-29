#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define lowbit(a) (a & -a)
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

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
ll u;
struct Mat
{
    ll c[110][110];
    Mat() { memset(c, 0, sizeof(c)); }
    Mat operator*(const Mat m)
    {
        Mat t;
        rep(i, 1, n) rep(j, 1, n) rep(k, 1, n)
            t.c[i][j] = (t.c[i][j] + c[i][k] * m.c[k][j]) % MOD;
        return t;
    }
} A, res;

void qpow(ll k)
{
    rep(i, 1, n) res.c[i][i] = 1;
    while (k)
    {
        if (k & 1)
            res = res * A;
        A = A * A, k >>= 1;
    }
}

void solve()
{
    cin >> n >> u;
    rep(i, 1, n) rep(j, 1, n) cin >> A.c[i][j];
    qpow(u);
    rep(i, 1, n)
    {
        rep(j, 1, n) cout << res.c[i][j] << " ";
        cout << endl;
    }
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