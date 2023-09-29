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

int w, h, res;
int ori[MAXN][MAXN];
int sum[MAXN][MAXN];
void solve()
{
    cin >> w >> h;
    rep(i, 1, w)
        rep(j, 1, h)
    {
        cin >> ori[i][j];
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ori[i][j];
    }
    rep(i, 1, w)
        rep(j, 1, h)
    {
        int q = 1;

        while (ori[i][j] && i + q <= w && j + q <= h && sum[i + q][j + q] - sum[i - 1][j + q] - sum[i + q][j - 1] + sum[i - 1][j - 1] == (q + 1) * (q + 1))
            q++;
        res = max(res, q);
    }
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