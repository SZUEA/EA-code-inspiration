/**
 *
 * Nim模板
 */

#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
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
const int MAXN = 5e5 + 10;
ll n, T, k = 1, c;
ll t[MAXN];
void solve()
{

    cin >> T;
    rep(i, 1, T) cin >> t[i], n ^= t[i];
    if (n)
    {
        rep(i, 1, T) if ((t[i] ^ n) < t[i]) 
        { k = t[i] - (t[i] ^ n), t[i] = t[i] ^ n, c = i; break; }
        cout << k << " " << c << endl;
        rep(i, 1, T) cout << t[i] << " ";
    }
    else
        cout << "lose";
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