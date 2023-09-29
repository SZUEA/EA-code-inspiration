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
const int MAXN = 2e5 + 10;
struct Node
{
    // 线段树左右端点l,r
    // 完全覆盖长度cover
    // 线段长度len
    int l, r, cover;
    int len;
} sgt[MAXN << 3];
struct Rec
{
    // x是竖边X坐标，y是~Y坐标,y1<y2
    // state : 左处边还是右处边
    int x, y1, y2, state;
} recs[MAXN];

inline void pushup(int k)
{
    if (sgt[k].cover)
        sgt[k].len = sgt[k].r - sgt[k].l;
    else
        sgt[k].len = sgt[ls(k)].len + sgt[rs(k)].len;
}

int n, v[MAXN << 1], a, b, c, d;
ull ans;
void build(int p, int l, int r)
{
    sgt[p].l = v[l], sgt[p].r = v[r];
    if (r - l <= 1)
        return; // r,l相差小于1，无下传内容
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid, r);
}

void update(int a, int b, int c, int k)
{
    int l = sgt[k].l, r = sgt[k].r;
    if (a <= l && r <= b)
    {
        sgt[k].cover += c;
        pushup(k);
        return;
    }
    if (a < sgt[ls(k)].r)
        update(a, b, c, ls(k));
    if (b > sgt[rs(k)].l)
        update(a, b, c, rs(k));
    pushup(k);
}

void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a >> b >> c >> d;
        v[i] = b, v[n + i] = d;
        recs[i] = (Rec){a, b, d, 1};
        recs[n + i] = (Rec){c, b, d, -1};
    }
    sort(v + 1, v + 1 + (n << 1));
    sort(recs + 1, recs + 1 + (n << 1), [](Rec a, Rec b)
         { return a.x < b.x; });
    build(1, 1, n << 1);
    rep(i, 1, n << 1)
    {
        ans += (ull)sgt[1].len * (recs[i].x - recs[i - 1].x);
        update(recs[i].y1, recs[i].y2, recs[i].state, 1);
    }
    cout << ans;
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