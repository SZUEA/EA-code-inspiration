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
// int T, a, b, x, y;

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

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    x = (x % b + b) % b;
    cout << x;
    return 0;
}