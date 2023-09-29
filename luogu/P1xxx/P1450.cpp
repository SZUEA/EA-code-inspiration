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

const int MAXN = 1e3 + 10;

int c[4], d[4];
int n, s;
ll f[MAXN];
void solve()
{
    rep(i, 0, 3) cin >> c[i];
    // 完全背包表示所有方案数
    f[0] = 1;
    // 所有超额的花费方案加到后面背包
    rep(i, 0, 3) rep(j, c[i], MAXN) f[j] += f[j - c[i]];
    caseT
    {
        ll res = 0; // 补集的并
        rep(i, 0, 3) cin >> d[i];
        cin >> s;
        // 容斥
        rep(i, 1, (1 << 4) - 1)
        {
            ll t = 0, flag = -1;
            // 过滤状态,选不选j
            rep(j, 0, 3) if (i & 1 << j)
            {
                t += c[j] * (d[j] + 1); // 超额使用
                flag = -flag;           // 转变符号，容斥核心
            }
            if (s >= t)
                res += f[s - t] * flag;
        }
        // 全集减去补集的并
        cout << f[s] - res << endl;
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