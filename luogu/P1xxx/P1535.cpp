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

const int MAXN = 105;

int mp[MAXN][MAXN];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k, sx, sy, ex, ey, res;
char c;

inline void f(int x, int y, int last)
{
    if (x == ex && y == ey && last == 0)
        res++;
    if (last == 0 || abs(x - ex) + abs(y - ey) > last)
        return;
    rep(i, 0, 3) if (x >= 1 && y >= 1 && x <= n && y <= m && mp[x][y])
        f(x + dir[i][0], y + dir[i][1], last - 1);
}

void solve()
{
    cin >> n >> m >> k;
    rep(i, 1, n) rep(j, 1, m) if (cin >> c && c == '.')
        mp[i][j] = 1;
    else mp[i][j] = 0;
    cin >> sx >> sy >> ex >> ey;
    f(sx, sy, k);
    cout << res;
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