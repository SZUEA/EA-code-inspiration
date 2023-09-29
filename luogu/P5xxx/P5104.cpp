
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

ll qpow(ll a, ll k, ll p)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return ans % p;
}
const ll MOD = 1e9 + 7;

ll n, m, k;
void solve()
{
    cin >> n >> m >> k;
    cout << qpow(qpow(2, MOD - 2, MOD), k, MOD) * n % MOD;
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