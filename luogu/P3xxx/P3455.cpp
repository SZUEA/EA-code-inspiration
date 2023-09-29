#define ONLINE_JUDGE 1
#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_t(i, s, t, p) for (register int i = (s); i <= (t); i = (p))
#define rep_r(i, s, t) for (register ll i = (s); i >= (t); i--)
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

inline void read(ll &x)
{
    x = 0;
    static ll p;
    p = 1;
    static char c;
    c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            p = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + (c - 48);
        c = getchar();
    }
    x *= p;
}

const int MAXN = 5e4 + 10;
// 1素数 2记忆函数 3莫比乌斯函数值 4前缀和
bool vis[MAXN];
int prime[MAXN], miu[MAXN], sum[MAXN], tot;
// miu函数为积性函数，满足f[1]=1;f[a*b]=f[a]*f[b],[a,b]互质
void func_miu(ll num)
{
    miu[1] = 1;
    rep(i, 2, num)
    {
        if (!vis[i])
            prime[++tot] = i, miu[i] = -1;
        rep(j, 1, tot)
        {
            if (i * prime[j] > num)
                break;
            vis[i * prime[j]] = 1;
            if (!(i % prime[j]))
            {
                miu[i * prime[j]] = 0;
                break;
            }
            miu[i * prime[j]] = -miu[i];
        }
    }
    rep(i, 1, num) sum[i] = 1ll * sum[i - 1] + miu[i];
}
ll n;
static ll a, b, d, r, minfromAB, res;
void solve()
{
    func_miu(5e4);
    read(n);
    while (n--)
    {
        read(a), read(b), read(d);
        minfromAB = min(a, b), res = 0;
        // 整除分块求解
        rep_t(l, 1, minfromAB, r + 1)
        {
            r = min(a / (a / l), b / (b / l));
            res += 1ll * (a / (l * d)) * (b / (l * d)) * (sum[r] - sum[l - 1]);
        }
        cout << res << endl;
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