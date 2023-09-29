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

ll mul(ll a, ll b, ll mo)
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans += a;
            if (ans >= mo)
                ans -= mo;
        }
        a <<= 1;
        if (a >= mo)
        {
            a -= mo;
            if (a == 0)
                return ans;
        }
        b >>= 1;
    }
    return ans;
}

ll T, n, m, p;
void solve()
{
    cin >> T >> n >> m >> p;
    ll ans=1,q = n - m + 1;
    while (m--)
        ans = mul(ans, q--, p);
    cout<<ans;
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