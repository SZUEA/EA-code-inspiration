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

const int MAXN = 1e5 + 10;

// e是存树的边的
vector<int> e[MAXN];
// fa存父节点，dep存树的深度，son存忠儿子，son存包括本身的总儿子数
int fa[MAXN], dep[MAXN], son[MAXN], sz[MAXN];
// top相当于并查集的fa数组,用于区分重链
int top[MAXN], id[MAXN], nw[MAXN], w[MAXN], cnt;
// 弄清fa,dep,son
void dfs1(int u, int father)
{
    fa[u] = father;
    dep[u] = dep[father] + 1;
    sz[u] = 1;
    // 枚举邻边
    for (auto &&v : e[u])
    {
        // 判重，防止dfs向上
        if (v == father)
            continue;
        // 向下dfs，v是u的儿子，
        dfs1(v, u);
        // 递归后，递推记录儿子个数
        sz[u] += sz[v];
        // 向下递归重儿子可能非最终重儿子
        // 而递推回来时一定记录的是正确重儿子
        // 即完成重儿子的更换
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}
// 弄清top数组
void dfs2(int u, int t)
{
    // 记录链表的头
    top[u] = t;
    // 记录新编号
    id[u] = ++cnt;
    // 新编号在树中对应的权值
    nw[cnt] = w[u];
    // 无重儿子返回
    if (!son[u])
        return;
    // 搜索重儿子
    dfs2(son[u], t);
    // 搜索轻儿子
    for (auto &&v : e[u])
    {
        // 判重，去掉父节点，重儿子点
        if (v == fa[u] || v == son[u])
            continue;
        // 轻儿子
        dfs2(v, v);
    }
}
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
// 线段树板子
struct SegmentTree
{
    int l, r;
    ll add, sum;
} sgt[MAXN << 2];
// 求和上传
void pushup(int u)
{
    sgt[u].sum = sgt[ls(u)].sum + sgt[rs(u)].sum;
}
// lazy标签下落
void pushdown(int u)
{
    if (sgt[u].add)
    {
        sgt[ls(u)].sum += sgt[u].add * (sgt[ls(u)].r - sgt[ls(u)].l + 1);
        sgt[rs(u)].sum += sgt[u].add * (sgt[rs(u)].r - sgt[rs(u)].l + 1);
        sgt[ls(u)].add += sgt[u].add;
        sgt[rs(u)].add += sgt[u].add;
        sgt[u].add = 0;
    }
}
void build(int u, int l, int r)
{
    sgt[u] = {l, r, 0, nw[r]};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
    pushup(u);
}
// 普通线段树询问
ll _query_(int u, int l, int r)
{
    if (l <= sgt[u].l && r >= sgt[u].r)
        return sgt[u].sum;
    pushdown(u);
    int mid = sgt[u].l + sgt[u].r >> 1;
    ll ans = 0;
    if (l <= mid)
        ans += _query_(ls(u), l, r);
    if (r > mid)
        ans += _query_(rs(u), l, r);
    return ans;
}
// 询问树上距离
ll query(int x, int y)
{
    ll ans = 0;
    while (top[x] != top[y])
    {
        // 与lca类似
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        // 在剖分的树上找答案加和
        ans += _query_(1, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    ans += _query_(1, id[y], id[x]);
    return ans;
}

ll queryAll(int x)
{
    return _query_(1, id[x], id[x] + sz[x] - 1);
}

// 普通线段树加法
// k:所加值，u:节点，l,r:询问端点
void _update_(int u, int l, int r, int k)
{
    if (l <= sgt[u].l && r >= sgt[u].r)
    {
        sgt[u].add += k;
        sgt[u].sum += k * (sgt[u].r - sgt[u].l + 1);
        return;
    }
    pushdown(u);
    int mid = sgt[u].l + sgt[u].r >> 1;
    ll ans = 0;
    if (l <= mid)
        _update_(ls(u), l, r, k);
    if (r > mid)
        _update_(rs(u), l, r, k);
    pushup(u);
}

void update(int x, int y, int k)
{
    while (top[x] != top[y])
    {
        // 与lca类似
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        // 在剖分的树上更新答案加和
        _update_(1, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    _update_(1, id[y], id[x], k);
}

void updateAll(int x, int k)
{
    _update_(1, id[x], id[x] + sz[x] - 1, k);
}

int n, m, r, p;
int a, b;
int op, x, y, k;
void solve()
{
    cin >> n >> m >> r >> p;
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n - 1)
    {
        cin >> a >> b;
        e[a].pb(b);
        e[b].pb(a);
    }
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    while (m--)
    {
        cin >> op >> x;
        switch (op)
        {
        case 1:
            cin >> y >> k;
            update(x, y, k);
            break;
        case 2:
            cin >> y;
            cout << query(x, y) % p << endl;
            break;
        case 3:
            cin >> k;
            updateAll(x, k);
            break;
        default:
            cout << queryAll(x) % p << endl;
            break;
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
