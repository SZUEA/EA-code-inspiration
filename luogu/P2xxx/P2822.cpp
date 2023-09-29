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

const int MAXN = 2e3 + 10;

int tria[MAXN][MAXN];
int sum[MAXN][MAXN];

void init(int p)
{
    tria[1][1] = 1;
    rep(i, 0, 2000) tria[i][0] = 1;
    rep(i, 2, 2000)
    {
        rep(j, 1, i)
        {
            tria[i][j] = (tria[i - 1][j] + tria[i - 1][j - 1]) % p;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if (!tria[i][j])
                sum[i][j] += 1;
        }
        sum[i][i + 1] = sum[i][i];
    }
}
void solve()
{
    int n, p;
    cin >> n >> p;
    init(p);
    rep(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        if (u < v)
            cout << sum[u][u];
        else
            cout << sum[u][v];
        cout << endl;
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