#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define lowbit(a) (a & -a)
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 5e5 + 10;

/**
 * 模板错误
ll t1[MAXN], t2[MAXN], n;
void add(int k, int v)
{
    int v1 = k * v;
    while (k <= n)
    {
        t1[k] += v, t2[k] += v1;
        k += lowbit(k);
    }
}

ll getS(ll *t, int k)
{
    ll ret = 0;
    while (k)
    {
        ret += t[k];
        k -= lowbit(k);
    }
    return ret;
}

void addOnRange(int l, int r, int v)
{
    add(l, v), add(r + 1, -v); // 将区间加差分为两个前缀加
}

ll getS_R(int l, int r)
{
    return (r + 1ll) * getS(t1, r) - 1ll * l * getS(t1, l - 1) -
           (getS(t2, r) - getS(t2, l - 1));
}
int temp, m, x, y, v;
void solve()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> temp, addOnRange(i, i, temp);
    rep(i, 1, m)
    {
        cin >> temp;
        if (temp - 1)
        {
            cin >> x;
            cout << getS_R(x, x) << endl;
        }
        else
        {
            cin >> x >> y >> v;
            addOnRange(x, y, v);
        }
    }
}
*/
int n, m;
int tr[MAXN];
void _add_(ll x, ll v)
{
    while (x <= n)
    {
        tr[x] += v;
        x += lowbit(x);
    }
}

ll getPoint(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += tr[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(ll l, ll r, ll v)
{
    _add_(l, v), _add_(r + 1, -v);
}
ll temp, x, y, v, k;
void solve()
{
    cin >> n >> m;
    // 树状数组维护差分数组
    rep(i, 1, n) cin >> temp, _add_(i, temp - k), k = temp;
    rep(i, 1, m)
    {
        cin >> temp;
        if (temp - 1)
        {
            cin >> x;
            cout << getPoint(x) << endl;
        }
        else
        {
            cin >> x >> y >> v;
            add(x, y, v);
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