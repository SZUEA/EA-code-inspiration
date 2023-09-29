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
unordered_map<int, int> tot[MAXN / 100];
int sts[MAXN / 100], ens[MAXN / 100];
int arr[MAXN], pos[MAXN / 100];
int n, m, x, y, r, tp, tq, bls, ans;
char o;
void solve()
{
    cin >> n >> m;
    bls = sqrt(n);
    rep(i, 1, n)
    {
        cin >> arr[i];
        pos[i] = (i - 1) / bls + 1;
        tot[pos[i]][arr[i]]++; // 区块内数值统计个数
        // 记录始终点
        if (!sts[pos[i]])
            sts[pos[i]] = i;
        ens[pos[i]] = i;
    }
    rep(z, 1, m)
    {
        cin >> o;
        if (o == 'C')
        {
            cin >> x >> y;
            tp = pos[x];
            tot[tp][arr[x]]--; // 书被取走力QAQ
            if (!tot[tp][arr[x]])
                tot[tp].erase(arr[x]); // 书本数无了，书也无了
            tot[tp][y]++;              // 新书到货!!!!WWWW
            arr[x] = y;
        }
        else
        {
            cin >> x >> y >> r;
            tp = pos[x];
            tq = pos[y];
            ans = 0;
            if (!(tp ^ tq))
                rep(i, x, y) ans += (arr[i] == r);
            else
            {
                //区间合并
                rep(i, x, ens[tp]) ans += (arr[i] == r);
                rep(i, sts[tq], y) ans += (arr[i] == r);
                rep(i, tp + 1, tq - 1) ans += tot[i][r];
            }
            cout << ans << endl;
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