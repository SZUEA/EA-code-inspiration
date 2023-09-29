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

const int MAXN = 100;

ll dp[MAXN][MAXN];

int ex, ey, bx, by;
int dir[9][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {0, 0}};
inline bool check(int x, int y)
{
    int cnt = 0;
    rep(i, 0, 8) if (bx + dir[i][0] == x && by + dir[i][1] == y) return 0;
    return 1;
}

void solve()
{
    cin >> ex >> ey >> bx >> by;
    dp[0][1] = 1, bx++, by++;
    rep(i, 1, ex + 1) rep(j, 1, ey + 1) if (check(i, j))
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    cout << dp[ex + 1][ey + 1];
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