#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 2e5 + 10;
ll d[MAXN * 4], a[MAXN * 4], b[MAXN * 4];

void build(ll s, ll t, ll p)
{
    if (s == t)
    {
        d[p] = a[s];
        return;
    }
    ll m = s + ((t - s) >> 1);
    build(s, m, p << 1), build(m + 1, t, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}

ll query(ll l, ll r, ll s, ll t, ll p)
{
    if (l <= s && t <= r)
        return d[p];
    ll m = s + ((t - s) >> 1), sum = 0;
    if (b[p])
        d[p << 1] += b[p] * (m - s + 1),
            d[(p << 1) | 1] += b[p] * (t - m),
            b[p << 1] += b[p],
            b[(p << 1) | 1] += b[p];
    b[p] = 0;
    if (l <= m)
        sum = query(l, r, s, m, p << 1);
    if (r > m)
        sum += query(l, r, m + 1, t, (p << 1) | 1);
    return sum;
}

void update(ll l, ll r, ll c, ll s, ll t, ll p)
{
    if (l <= s && t <= r)
    {
        d[p] += (t - s + 1) * c, b[p] += c;
        return;
    }
    ll m = s + ((t - s) >> 1);
    if (b[p])
    {
        d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
        b[p] = 0;
    }
    if (l <= m)
        update(l, r, c, s, m, p << 1);
    if (r > m)
        update(l, r, c, m + 1, t, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}
int n, p;
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> p;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while (p--)
    {
        int k;
        cin >> k;
        if (k - 1)
        {
            int o, m;
            cin >> o >> m;
            cout << query(o, m, 1, n, 1) << endl;
        }
        else
        {
            int o, m, f;
            cin >> o >> m >> f;
            update(o, m, f, 1, n, 1);
        }
    }
    return 0;
}