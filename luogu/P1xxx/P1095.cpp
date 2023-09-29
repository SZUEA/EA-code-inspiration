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

const int MAXN = 3e5 + 10;
int m, s, t;
int dp[MAXN];

void solve()
{
    cin >> m >> s >> t;
    rep(i, 1, t) if (m >= 10) m -= 10, dp[i] = dp[i - 1] + 60;
    else m += 4, dp[i] = dp[i - 1];
    rep(i, 1, t)
    {
        dp[i] = max(dp[i], dp[i - 1] + 17);
        if (s <= dp[i])
        {
            cout << "Yes" << endl
                 << i;
            return;
        }
    }
    cout << "No" << endl
         << dp[t];
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