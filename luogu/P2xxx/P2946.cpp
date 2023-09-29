#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 2010;

int n, f;
int dp[MAXN][MAXN];
int itms[MAXN];
const int MOD = 100000000;

void solve()
{
    cin >> n >> f;
    rep(i, 1, n)
    {
        cin >> itms[i];
        itms[i] %= f;
        dp[i][itms[i]] = 1;
    }
    rep(i, 1, n) rep(j, 0, f - 1)
        dp[i][j] = ((dp[i][j] + dp[i - 1][j]) % MOD + dp[i - 1][(j - itms[i] + f) % f]) % MOD;
    cout<<dp[n][0];
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