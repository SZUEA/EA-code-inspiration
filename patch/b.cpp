#define ONLINE_JUDGE 1
#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
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

const int MAXN = 1e6 + 10, MAXM = 1e3 + 10;
char c, op;
int n, m, arr[MAXN], sorted[MAXN];
int block_start[MAXM], block_end[MAXM];
int lazy_add[MAXN], position[MAXN];
int start_i, end_i;
int L, R, v;
int x, y, z, ans;
vector<int> store[(int)1e4 + 10];
void solve()
{
    cin >> n >> m;
    end_i = sqrt(n); // 块的终止位置基数
    rep(i, 1, n) cin >> arr[i];
    rep(i, 1, n)
    {
        position[i] = (i - 1) / end_i + 1;
        store[position[i]].pb(arr[i]);
    }
    rep(i, 1, position[n]) // 区块排序
        sort(store[i].begin(), store[i].end());
    while (m--)
    {
        cin >> op >> L >> R >> v;
            x = position[L], y = position[R];
        if (op == 'M')
        {
            rep(i, L, min(R, x * end_i)) arr[i] += v; // 区块加和
            store[x].clear();
            rep(i, (x - 1) * end_i + 1, min(x * end_i, n)) store[x].pb(arr[i]);
            sort(store[x].begin(), store[x].end());
            if (x != y)
            {
                rep(i, (y - 1) * end_i + 1, R) arr[i] += v;
                store[y].clear();
                rep(i, (y - 1) * end_i + 1, min(y * end_i, n)) store[y].pb(arr[i]);
                sort(store[y].begin(), store[y].end());
            } 
            rep(i, x + 1, y - 1) lazy_add[i] += v;
        }
        else
        {
            ans = 0;
            rep(i, L, min(R, x * end_i)) ans += (arr[i] + lazy_add[x] < v); // 统计并下落lazy             // 区块加和
            if (x != y)
                rep(i, (y - 1) * end_i + 1, R) ans += (arr[i] + lazy_add[y] < v);
            rep(i, x + 1, y - 1)
                // 二分查找有多少个比v小的数，这是由于sorted已是有序列
                ans += lower_bound(store[i].begin(), store[i].end(), v - lazy_add[i]) - store[i].begin();
            cout << R - L + 1 - ans << endl;
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