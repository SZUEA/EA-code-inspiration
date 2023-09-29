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

#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
const int MAXN = 1e2 + 10;
ll d[MAXN << 2], MOD;

void _build_(ll s, ll t, ll p)
{
    // 对 [s,t] 区间建立线段树,当前根的编号为 p
    if (s == t)
    {
        d[p] = 1;
        return;
    }
    ll m = (s + t) >> 1;
    _build_(s, m, ls(p));
    _build_(m + 1, t, rs(p));
    // 递归对左右区间建树
    d[p] = (d[ls(p)] * d[rs(p)]) % MOD;
}
void build(ll s, ll t, ll p)
{
    _build_(s, t, p);
}

void update(ll l, ll r, ll p, ll s, ll t, ll c)
{
    // [l, r] 为修改区间, c 为被修改的元素的变化量, [s, t] 为当前节点包含的区间, p
    // 为当前节点的编号

    if (l >= s && t >= r)
    {
        d[p] = c;
        return;
    }
    ll m = (l+r)>>1;
    if (s <= m)
        update(l, m, ls(p), s, t, c);
    if (t > m)
        update(m+1, r, rs(p), s, t, c);
    d[p] = (d[ls(p)] * d[rs(p)]) % MOD;
}

void solve()
{
    caseT
    {
        ll n, x, y;
        cin >> n >> MOD;
        build(1, n, 1);
        rep(i, 1, n)
        {
            cin >> x >> y;
            if (x == 1)
                update(1, n, 1, i, i, y), d[1] %= MOD;
            else
                update(1, n, 1, y, y, 1);
            cout << d[1] << endl;
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