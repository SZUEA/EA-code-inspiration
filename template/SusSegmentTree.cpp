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

#define ls(x) sgt[x].l
#define rs(x) sgt[x].r
const int MAXN = 2e5 + 10;

int n, m, a[MAXN];
vector<int> v;
struct node
{
    int l,r;
    int s;
} sgt[MAXN * 22];
int root[MAXN], idx;

void build(int &p, int l, int r)
{
    p = ++idx;
    if (l == r)
        return;
    int m = l + r >> 1;
    build(ls(p), l, m);
    build(rs(p), m + 1, r);
}

void insert(int x, int &y, int l, int r, int v)
{
    y = ++idx;
    sgt[y] = sgt[x];
    sgt[y].s++;
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (v <= mid)
        insert(ls(x), ls(y), l, mid, v);
    else
        insert(rs(x), rs(y), mid + 1, r, v);
}

int query(int x, int y, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = l + r >> 1;
    int s = sgt[ls(y)].s - sgt[ls(x)].s;
    if (k <= s)
        return query(ls(x), ls(y), l, mid, k);
    else
        return query(rs(x), rs(y), mid + 1, r, k - s);
}

int l, r, k, lo;

int getid(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void solve()
{
    cin >> n >> lo;
    rep(i, 1, n) cin >> a[i], v.pb(a[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int vn = v.size();
    rep(i, 1, n) insert(root[i - 1], root[i], 1, vn, getid(a[i]));
    rep(i, 1, lo)
    {
        cin >> l >> r >> k;
        int id = query(root[l - 1], root[r], 1, vn, k) - 1;
        cout << v[id] << endl;
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