// 生成函数的应用
#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_i(i, s, t, p) for (register int i = (s); i <= (t); i += (p))
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

namespace Problem1
{
    /**
     * 普通生成函数应用1
     * 给定n个物品，第i物品选购个数范围是[ai,bi]
     * 求买m个物品的方案数
     * 输入顺序:n,m,a1,b1...an,bn
     * 输入 3 6 2 3 0 2 1 2
     * 输出 3
     */
    const int MAXN = 110;
    int a[MAXN], b[MAXN], c[MAXN], d[MAXN << 1];
    int n, m;
    void solution()
    {
        cin >> n >> m;
        rep(i, 1, n) cin >> a[i] >> b[i];
        rep(i, a[1], b[1]) c[i] = 1;
        rep(i, 2, n)
        {
            rep(j, 0, m) rep(k, a[i], b[i]) d[j + k] += c[j];
            rep(j, 0, m) c[j] = d[j], d[j] = 0;
        }
        cout << c[m];
    }
}

namespace Problem2
{
    /**
     * 普通生成函数应用2
     * 有n种硬币
     * 面值为a1,a2,...an的硬币有b1,b2,...bn枚
     * 求不能由这些硬币构成的最小面值
     * 输入顺序n,a1,b1,a2,b2,...an,bn
     * 输入:3 1 1 2 1 5 1
     * 输出:4
     */
    const int MAXN = 4e3 + 5;
    int a[MAXN], b[MAXN], c[MAXN], d[MAXN << 1];
    int n, m, ans, rec;
    void solution()
    {
        cin >> n;
        rep(i, 1, n) cin >> a[i] >> b[i];
        rep_i(i, 0, a[1] * b[1], a[1]) c[i] = 1;
        rep(i, 2, n)
        {
            rec += a[i - 1];
            rep_i(k, 0, a[i] * b[i], a[i]) rep(j, 0, rec) d[j + k] += c[j];
            rep(j, 0, a[i] * b[i] + a[i - 1] * b[i - 1]) c[j] = d[j], d[j] = 0;
        }
        while (c[++ans])
            ;
        cout << ans;
    }
}

namespace Problem3
{
    /**
     * 指数生成函数的应用
     * 有n种物品，每种有ai个，问取m个物品的排列数
     * 输入顺序:n,m,a1,a2,...,an
     * 输入:2 4 3 2
     * 输出:10
     */
    const int MAXN = 11;
    int n, m;
    int arr[MAXN];
    double fac[MAXN], c[MAXN], d[MAXN];
    void solution()
    {
        // 先预处理  n!
        fac[0] = fac[1] = 1;
        rep(i, 2, 100) fac[i] = fac[i - 1] * i;
        cin >> n >> m;
        rep(i, 1, n) cin >> arr[i];
        rep(i,1,m)c[i]=d[i]=0;
        rep(i, 0, arr[1]) c[i] = 1.0 / fac[i];
        rep(i, 2, n)
        {
            rep(j, 0, m) rep(k, 0, arr[i]) d[j + k] += c[j] / fac[k];
            rep(j, 0, m) c[j] = d[j], d[j] = 0;
        }
        cout << c[m] * fac[m];
    }
}

void solve()
{
    // Problem1::solution();
    // Problem2::solution();
    Problem3::solution();
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