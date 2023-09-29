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

#define ls(p) (p << 1)
#define rs(p) (p << 1) | 1

const int MAXN = 2e5 + 10;
int MOD;
ll d[MAXN * 4], a[MAXN * 4], b[MAXN * 4], f[MAXN * 4];

void build(ll s, ll t, ll p)
{
    f[p] = 1;
    if (s == t)
    {
        d[p] = a[s];
        return;
    }
    ll m = s + ((t - s) >> 1);
    build(s, m, ls(p)), build(m + 1, t, rs(p));
    d[p] = (d[ls(p)] + d[rs(p)]) % MOD;
}

void stp(ll p, ll s, ll t)
{
    ll l = ls(p), r = rs(p);
    ll m = s + ((t - s) >> 1);
    if (f[p] != 1)
        (f[l] *= f[p]) %= MOD,
            (f[r] *= f[p]) %= MOD,
            (b[l] *= f[p]) %= MOD,
            (b[r] *= f[p]) %= MOD,
            (d[l] *= f[p]) %= MOD,
            (d[r] *= f[p]) %= MOD,
            f[p] = 1;
    if (b[p])
        (d[l] += b[p] * (m - s + 1)) %= MOD,
            (d[r] += b[p] * (t - m)) %= MOD,
            (b[l] += b[p]) %= MOD,
            (b[r] += b[p]) %= MOD,
            b[p] = 0;
}

ll query(ll l, ll r, ll s, ll t, ll p)
{
    if (l <= s && t <= r)
        return d[p];
    ll m = s + ((t - s) >> 1), sum = 0;
    stp(p, s, t);
    if (l <= m)
        (sum += query(l, r, s, m, ls(p))) %= MOD;
    if (r > m)
        (sum += query(l, r, m + 1, t, rs(p))) %= MOD;
    return sum;
}

void update(ll l, ll r, ll c, ll s, ll t, ll p, int mode)
{
    if (l <= s && t <= r)
    {
        if (!mode)
            (f[p] *= c) %= MOD,
                (b[p] *= c) %= MOD,
                (d[p] *= c) %= MOD;
        else
            (d[p] += c * (t - s + 1)) %= MOD,
                (b[p] += c) %= MOD;
        return;
    }
    ll m = s + ((t - s) >> 1);
    stp(p, s, t);
    if (l <= m)
        update(l, r, c, s, m, ls(p), mode);
    if (r > m)
        update(l, r, c, m + 1, t, rs(p), mode);
    d[p] = (d[ls(p)] + d[rs(p)]) % MOD;
}
int n, p;
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> MOD;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    cin >> p;
    while (p--)
    {
        int k;
        cin >> k;
        if (k == 3)
        {
            int o, m;
            cin >> o >> m;
            cout << query(o, m, 1, n, 1) << endl;
        }
        else
        {
            int o, m, f;
            cin >> o >> m >> f;
            update(o, m, f, 1, n, 1, k - 1);
        }
    }
    return 0;
}