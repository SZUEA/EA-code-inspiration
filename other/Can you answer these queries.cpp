#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define lowbit(a) (a & -a)
#define endl '\n'
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)
#define ri register int
#define lson k << 1
#define rson k << 1 | 1
using namespace std;
int sum[200001], lmax[200001], rmax[200001], n;
int dat[200001], a[50001], m, x, y, z, ans, pre;
inline void wh(ri k)
{
    sum[k] = sum[lson] + sum[rson];
    lmax[k] = max(lmax[lson], sum[lson] + lmax[rson]);
    rmax[k] = max(rmax[rson], sum[rson] + rmax[lson]);
    dat[k] = max(max(dat[lson], dat[rson]), rmax[lson] + lmax[rson]);
    return;
}
inline void build(ri k, ri l, ri r) // 建树
{
    if (l == r)
    {
        sum[k] = a[l];
        lmax[k] = a[l];
        rmax[k] = a[l];
        dat[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    wh(k);
    return;
}
inline void change(ri k, ri l, ri r, ri x, ri d) // 我这里没有多开两个数组而是多开了两个参数，因为听说这样比较快。。。
{
    if (l == r)
    {
        if (l == x)
        {
            sum[k] = d;
            lmax[k] = d;
            rmax[k] = d;
            dat[k] = d;
        } // 达到要修改的点则修改
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        change(lson, l, mid, x, d);
    else
        change(rson, mid + 1, r, x, d); // 修改
    wh(k);                              // 维护
    return;
}
inline void query(ri k, ri l, ri r, ri ql, ri qr) // 询问
{
    if (ql <= l && qr >= r)
    {
        ans = max(ans, dat[k]); // 计算
        ans = max(ans, pre + lmax[k]);
        pre = max(rmax[k], pre + sum[k]); // 维护pre
        return;
    }
    int mid = (l + r) >> 1;
    int ans = 0;
    if (ql <= mid)
        query(lson, l, mid, ql, qr);
    if (qr > mid)
        query(rson, mid + 1, r, ql, qr); // 继续向下
}

void solve()
{
    cin >> n;
    rep(i, 1, n)
            cin >>
        a[i];
    build(1, n, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (!op)
        {
            change(1, n, 1, x, y);
        }
        else
        {
            ans = -1147481645, pre = -1147481645;
            query(1, n, 1, x, y);
            cout << ans << endl;
        }
    }
}

int main()
{
    IOS;
    solve();
    return 0;
}