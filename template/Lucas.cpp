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

ll qpow(ll a, ll k, ll p)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % p;
        a = a * a % p, k >>= 1;
    }
    return ans % p;
}

int f[MAXN], g[MAXN];
void init(int p)
{
    f[0] = g[0] = 1;
    rep(i, 1, MAXN)
    {
        f[i] = f[i - 1] * i % p;
        g[i] = g[i - 1] * qpow(i, p - 2, p) % p;
    }
}

ll getC(int n, int m, int p)
{
    return f[n] * g[m] * g[n - m] % p;
}

int lucas(ll n, ll m, int p)
{
    if (m == 0)
        return 1;
    return lucas(n / p, m / p, p) * getC(n % p, m % p, p) % p;
}
ll n_, m_;
int p;
void solve()
{
    // caseT
    // {
    //     cin >> n_ >> m_ >> p;
    //     init(p);
    //     cout << lucas(n_ + m_, n_, p) % p << endl;
    // }
    const int MOD=1e9+7;
    init(1e9+7);
    cout<<getC(22,1,MOD)%MOD;
}
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    clock_t my_clock = clock();
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    cout << endl
         << "Time used " << clock() - my_clock << " ms." << endl;
#endif
    return 0;
}