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

const int MAXN = 1e5 + 10;
// const int MAXN = 1e2 + 10;

#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
ll tre[MAXN << 2], arr[MAXN << 2], lazy[MAXN << 2];

void build(ll s, ll t, ll p)
{
    if (s == t)
    {
        tre[p] = arr[s];
        return;
    }
    ll m = s + ((t - s) >> 1);
    build(s, m, ls(p)), build(m + 1, t, rs(p));
    tre[p] = tre[ls(p)] + tre[rs(p)];
}

ll query(ll l, ll r, ll s, ll t, ll p)
{
    if (l <= s && t <= r)
        return tre[p];
    ll m = s + ((t - s) >> 1), sum = 0;
    if (lazy[p])
    {
        tre[ls(p)] = (m - s + 1) - tre[ls(p)];
        tre[rs(p)] = (t - m) - tre[rs(p)];
        lazy[ls(p)] = !lazy[ls(p)];
        lazy[rs(p)] = !lazy[rs(p)];
        lazy[p] = 0;
    }
    if (l <= m)
        sum = query(l, r, s, m, ls(p));
    if (r > m)
        sum += query(l, r, m + 1, t, rs(p));
    return sum;
}

void update(ll l, ll r, ll s, ll t, ll p)
{
    if (l <= s && t <= r)
    {
        tre[p] = (t - s + 1) - tre[p];
        lazy[p] = !lazy[p];
        return;
    }
    ll m = s + ((t - s) >> 1);
    if (lazy[p])
    {
        tre[ls(p)] = (m - s + 1) - tre[ls(p)];
        tre[rs(p)] = (t - m) - tre[rs(p)];
        lazy[ls(p)] = !lazy[ls(p)];
        lazy[rs(p)] = !lazy[rs(p)];
        lazy[p] = 0;
    }
    if (l <= m)
        update(l, r, s, m, ls(p));
    if (r > m)
        update(l, r, m + 1, t, rs(p));
    tre[p] = tre[ls(p)] + tre[rs(p)];
}
int n, p;
char c;
void solve()
{
    cin >> n >> p;
    rep(i, 1, n) cin >> c, arr[i] = c - '0';
    build(1, n, 1);
    while (p--)
    {
        int k, x, y, z;
        cin >> k;
        if (k == 1)
        {
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << endl;
        }
        else
        {
            cin >> x >> y;
            update(x, y, 1, n, 1);
        }
    }
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