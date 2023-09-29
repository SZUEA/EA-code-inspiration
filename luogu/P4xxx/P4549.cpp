#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
typedef long long ll;
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
using namespace std;

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

ll a, b, x, y, n;
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n;
    cin >> a;
    while (--n)
    {
        cin >> b;
        a = gcd(a, b > 0 ? b : -1 * b);
    }
    cout << a;
    return 0;
}