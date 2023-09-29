#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 1e5 + 10;

ll mul(ll a, ll b, ll mod)
{
    ll ans = 0;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans + a) % mod;
        a = (a << 1) % mod, b >>= 1;
    }
    return ans;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll excrt(ll *x, ll *y, int n)
{
    ll a = x[1], b = y[1], c, d, k, e, f, g, h;
    rep(i, 2, n)
    {
        e = a, f = x[i], h = (y[i] - b % f + f) % f;
        g = exgcd(e, f, c, d);
        if (h % g != 0)
            return -1;
        c = mul(c, h / g, f / g);
        b += c * a, a *= f / g, b = (b % a + a) % a;
    }
    return (b % a + a) % a;
}

int n;
ll a[MAXN], b[MAXN];

void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i] >> b[i];
    cout << excrt(a, b, n) << endl;
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