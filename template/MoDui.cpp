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

const int MAXN = 5e4 + 10;
struct Block
{
    // 块的左端与右端还有块的下标信息
    int l, r, k;
} bs[MAXN];

int pos[MAXN];
int arr[MAXN];
int ans[MAXN];

int n, siz, m;
ll res;
void solve()
{
    cin >> n >> m;
    siz = sqrt(n);
    // 分块
    rep(i, 1, n)
    {
        cin >> arr[i];
        pos[i] = i / siz;
    }
    rep(i, 0, m - 1)
    {
        cin >> bs[i].l >> bs[i].r;
        bs[i].k = i;
    }
    sort(bs, bs + m, [](Block a, Block b)
         { return pos[a.l] == pos[b.l] ? a.r < b.r : pos[a.l] < pos[b.l]; });
    int l = 1, r = 0;
    rep(i, 0, m - 1)
    {
        // while (bs[i].l<l) add(--l);
        // while (bs[i].r>r) add(++r);
        // while (bs[i].l>l) sub(l++);
        // while (bs[i].r<r) sub(r--);
        // 上面根据具体问题考虑贡献，编写add和sub函数
        // 记录答案
        ans[bs[i].k] = res;
        rep(i, 0, m - 1) cout << ans[i] << endl;
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