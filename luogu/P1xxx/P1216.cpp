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
int mp[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;

void solve()
{
    cin >> n;
    rep(i, 1, n) rep(j, 1, i) cin >> mp[i][j];
    rep_r(i, n, 1) rep(j, 1, i) dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + mp[i][j];
    cout << dp[1][1];
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