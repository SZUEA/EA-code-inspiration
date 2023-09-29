/*
 *To solve $\sum_{i=1}^{n}{\lfloor \frac{n}{i} \rfloor}$
 */

#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    std::cin.tie(0), std::cout.tie(0);
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

const int MAXN = 110;
ll n, ans, i = 1, k, j;
void solve()
{
    cin >> n >> k;
    ans = n * k;
    while (i <= n && k / i)
    {
        j = min(k / (k / i), n);
        ans -= (k / i * (j - i + 1) * (j + i)) >> 1;
        i = j + 1;
    }
    std::cout << ans << endl;
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