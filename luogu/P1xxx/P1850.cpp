#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
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
const int INF = 0x3f3f3f3f;
db g[MAXN], f[MAXN][MAXN][3], res;
int dis[MAXN][MAXN], a[MAXN], b[MAXN];
int n, m, v, e, tot, x, y, z;
db Qa, Qa_, _Qa, Q1, Q2, Q3, Q4, Q5, Q6;
void solve()
{
    /* Declaration: power can be changed into distance */
    /* Input and Preprocess */
    cin >> n >> m >> v >> e;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) cin >> g[i];
    rep(i, 1, v) rep(j, 1, i - 1) dis[i][j] = dis[j][i] = INF;                    // Prepare for floyd
    rep(i, 1, e) cin >> x >> y >> z, dis[y][x] = (dis[x][y] = min(dis[x][y], z)); // AddEdge Pro
    rep(i, 1, n) rep(j, 0, m) f[i][j][0] = f[i][j][1] = INF;                      // Prepare for dp
    f[1][0][0] = f[1][1][1] = 0, res = INF;                                       // initial value for dp
    /* Floyd to prepare the shortest path. From start is mid,left,right. Right can be half down as the edges are double-directable*/
    rep(k, 1, v) rep(i, 1, v) rep(j, 1, i - 1) dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    /* DP starts from this */
    rep(i, 2, n) rep(j, 0, m) // Iterate the dp array to transfer, similar to the initialization
    {
        // The first part : No i th course -> Dividing into 2 parts : Use point or not

        // *1 If I don't use point, I directly get value from i-1 and add distance to it
        Qa = f[i - 1][j][0] + 1.0 * dis[a[i - 1]][a[i]];
        // *2 If I use point, then process two cases.
        // -1 If the application passed
        Qa_ = f[i - 1][j][1] + g[i - 1] * 1.0 * dis[b[i - 1]][a[i]];
        // -2 If the application failed
        _Qa = (1.0 - g[i - 1]) * 1.0 * dis[a[i - 1]][a[i]];
        // Then the status can be updated
        f[i][j][0] = min(Qa, Qa_ + _Qa);
        // The second part : Select i th course -> Dividing into 2 parts : Use point or not
        // For the first, judge j. If j = 0 ,then j - 1 can be an invalid index
        if (j)
        {
            // *1 not use point -> success at i
            Q1 = f[i - 1][j - 1][0] + g[i] * 1.0 * dis[a[i - 1]][b[i]];
            // *1 not use point -> fail at i
            Q2 = (1.0 - g[i]) * 1.0 * dis[a[i - 1]][a[i]];
            // *2 use point -> fail at i success at i-1
            Q3 = g[i - 1] * (1.0 - g[i]) * 1.0 * dis[b[i - 1]][a[i]];
            // *2 use point -> fail at i fail at i-1
            Q4 = (1.0 - g[i - 1]) * (1.0 - g[i]) * 1.0 * dis[a[i - 1]][a[i]];
            // *2 use point -> success at i fail at i-1
            Q5 = (1.0 - g[i - 1]) * g[i] * 1.0 * dis[a[i - 1]][b[i]];
            // *2 use point -> success at i success at i-1
            Q6 = f[i - 1][j - 1][1] + g[i - 1] * g[i] * 1.0 * dis[b[i - 1]][b[i]];
            // Then the status can be updated
            f[i][j][1] = min(Q1 + Q2, Q3 + Q4 + Q5 + Q6);
        }
    }

    // Final step : Find answer
    rep(i, 0, m) res = min(res, min(f[n][i][0], f[n][i][1]));
    cout << fixed << setprecision(2) << res;
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