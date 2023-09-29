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
namespace SegmentTree
{
    const int MAXN = 1e5 + 10;

#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
    ll tre[MAXN << 2];

    int n, m;

    void build(int p, int l, int r)
    {
        if (l == r)
        {
            tre[p] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        tre[p] = tre[ls(p)] + tre[(rs(p))];
    }

    ll query(int p, int l, int r, int start, int end)
    {
        if (l >= start && end >= r)
            return tre[p];
        int mid = (l + r) >> 1;
        ll ans = 0;
        if (start <= mid)
            ans += query(ls(p), l, mid, start, end);
        if (end > mid)
            ans += query(rs(p), mid + 1, r, start, end);
        return ans;
    }

    void update(int p, int l, int r, int start, int end, int v)
    {
        if (l == r)
        {
            tre[p] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if (start <= mid)
            update(ls(p), l, mid, start, end, v);
        else
            update(rs(p), mid + 1, r, start, end, v);
        tre[p] = tre[ls(p)] + tre[rs(p)];
    }

    void solve()
    {
        cin >> n >> m;
        // build(1, 1, n);
        rep(i, 1, m)
        {
            char op;
            int x, y;
            cin >> op >> x >> y;
            if (op == 'x')
                update(1, 1, n, x, x, y);
            else
                cout << query(1, 1, n, x, y) << endl;
        }
    }

} // namespace SegmentTree

namespace TreeLikeArray
{
    const int MAXN = 1e5 + 10;
    ll tre[MAXN];
    int n, m;

    void add(int k, int v)
    {
        while (k <= n)
        {
            tre[k] += v;
            k += lowbit(k);
        }
    }

    ll getSum(int k)
    {
        ll ret = 0;
        while (k)
        {
            ret += tre[k];
            k -= lowbit(k);
        }
        return ret;
    }
    void solve()
    {
        cin >> n >> m;
        rep(i, 1, m)
        {
            char op;
            int x, y;
            cin >> op >> x >> y;
            if (op == 'x')
                add(x, y);
            else
                cout << getSum(y) - getSum(x - 1) << endl;
        }
    }
} // namespace TreeLikeArray

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    clock_t my_clock = clock();
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    TreeLikeArray::solve();
#ifndef ONLINE_JUDGE
    cout << endl
         << "Time used " << clock() - my_clock << " ms." << endl;
#endif
    return 0;
}