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

const int MAXN = 5e6 + 10;
inline void exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int qpow(int a, int b, int p)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ll)ans * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return ans;
}

int n, p, k, ans;
int s[MAXN], sv[MAXN], inv[MAXN], a[MAXN];
void solve()
{
    cin >> n >> p >> k;
    s[0] = 1;
    rep(i, 1, n) cin >> a[i],
        s[i] = (ll)s[i - 1] * a[i] % p;
    sv[n] = qpow(s[n], p - 2, p);
    rep_r(i, n, 2)
        sv[i - 1] = (ll)sv[i] * a[i] % p;
    rep_r(i, n, 1) ans = ((ll)sv[i] * s[i - 1] % p + ans) * k % p;
    cout << ans << endl;
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