#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 100010;

int vis[MAXN], pri[MAXN], cnt;

void init(int n = MAXN)
{
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
            pri[cnt++] = i;
        for (int j = 0; j < cnt; ++j)
        {
            if (1ll * i * pri[j] > n)
                break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}

int n, m, k;
void solve()
{
    init();
    cin >> n;
    rep(i, 0, n) if ((m += pri[k = i]) <= n) cout << pri[i] << endl;
    else break;
    cout << k << endl;
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