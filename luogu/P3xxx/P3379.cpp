/*

Solution 1:倍增打表

#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
inline void read(int &x)
{
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
}
const int N = 500010;
struct T
{
    int nxt, to;
} t[N << 1];
int head[N];
int n, m, tot = 0, r;
int dep[N], fa[N][22], lg[N];
void addEdgeDbl(int a, int b)
{
    t[++tot].to = b;
    t[tot].nxt = head[a];
    head[a] = tot;
    t[++tot].to = a;
    t[tot].nxt = head[b];
    head[b] = tot;
}

// preprocess
void dfs(int c, int f)
{
    fa[c][0] = f, dep[c] = dep[f] + 1;
    // c ancestor of 2^i -> c ancestor of 2^(i-1) 's ancestor of 2^(i-1)
    rep(i, 1, lg[dep[c]]) fa[c][i] = fa[fa[c][i - 1]][i - 1];
    // chain of star forward
    for (int i = head[c]; i; i = t[i].nxt)
        if (t[i].to != f)
            dfs(t[i].to, c); // update child and father to next gen
}

// main Lca
int getLca(int a, int b)
{
    // make a's dep the max
    if (dep[a] < dep[b])
    {
        int t = a;
        a = b, b = t;
    }
    // synchronize a's dep and b's dep
    // jump for 2's pow,down and down
    while (dep[a] > dep[b])
        a = fa[a][lg[dep[a] - dep[b]] - 1];
    // if a=b then either a or b is a root of each other
    // time to return either from a,b
    if (a == b)
        return a;
    // now that dep[a]=dep[b], start jump together
    for (int k = lg[dep[a]] - 1; k >= 0; k--)
    //if value unequal, jump again.
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int main()
{
    read(n), read(m), read(r);
    rep(i, 1, n-1)
    {
        int a, b;
        read(a), read(b);
        addEdgeDbl(a, b);
    }
    rep(i, 1, n)
        lg[i] = lg[i - 1] + (1 << lg[i - 1]  == i);
    dfs(r, 0);
    rep(i,1,m){
        int a,b;
        read(a),read(b);
        printf("%d\n",getLca(a,b));
    }
    return 0;
}

*/
/*
Solution2:树链剖分
*/
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

/**
 * 模板：树链剖分
 */
const int MAXN = 5e5 + 10;
// e是存树的边的
vector<int> e[MAXN];
// fa存父节点，dep存树的深度，son存忠儿子，son存包括本身的总儿子数
int fa[MAXN], dep[MAXN], son[MAXN], sz[MAXN];
// top相当于并查集的fa数组,用于区分重链
int top[MAXN];
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
//u向上爬
int lca(int u, int v)
{//链头不相等就进入循环
    while (top[u] != top[v])
    {
        //深度小就交换，保证深度最深
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u] ];
    }
        //判断深度，浅的点就是最近公共祖先
    return dep[u] < dep[v] ? u : v;
}

int n,m,x, u,v;
void solve()
{
    cin>>n>>m>>x;
    rep(i,1,n-1){
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs1(x,0);
    dfs2(x,x);
    while (m--)
    {
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
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