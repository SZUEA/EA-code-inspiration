#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 1010;

struct Item
{
    int m, t;
} its[1010];

int dp[MAXN][MAXN];
int ls, lm, lt;

void solve()
{
    cin >> ls >> lm >> lt;
    rep(i, 1, ls) cin >> its[i].m >> its[i].t;
    rep(i, 1, ls) rep_r(j, lm, its[i].m) rep_r(k, lt, its[i].t)
        dp[j][k] = max(dp[j][k], dp[j - its[i].m][k - its[i].t] + 1);
    cout << dp[lm][lt];
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