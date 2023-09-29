#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)

const int MN = 1010;
const ll INFF = 0x3f3f3f3f;

db gt(db x1, db y1, db x2, db y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int n;      // 节点数
db dis[MN]; // 每个节点到起点的距离
db xs[MN], ys[MN];
db sx, sy, px, py;
db v1, v2;
db dis_[MN][MN];
int st[MN];

db dijkstra()
{
    rep(i, 1, n)
        dis[i] = 1e18;
    dis[1] = 0;
    rep(i, 0, n - 1)
    {
        int t = -1;
        rep(j, 1, n)
        {
            if (!st[j] && (t == -1 || dis[t] > dis[j]))
                t = j;
        }
        st[t] = 1;
        rep(j, 1, n)
        {
            if (dis[t] + dis_[t][j] < dis[j])
                dis[j] = dis[t] + dis_[t][j];
        }
    }
    return dis[n];
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n;
    n+=2;
    rep(i, 2, n-1) cin >> xs[i] >> ys[i];
    cin >> sx >> sy >> px >> py;
    cin >> v1 >> v2;
    dis_[1][n] = gt(sx, sy, px, py) / v1;
    rep(i, 2, n-1)
        dis_[1][i] = gt(sx, sy, xs[i], ys[i]) / v1;
    rep(i, 2, n - 1)
    {
        db k = gt(xs[i], ys[i], px, py);
        dis_[i][n] = k / (v2 * 1.0) <= 3
                         ? k / (v2 * 1.0)
                         : 3.0 + (k - v2 * 3.0) / (v1 * 1.0);
    }
    rep(i, 2, n - 1)
        rep(j, 2, n - 1)
    {
        if (i == j)
            continue;
        db k = gt(xs[i], ys[i], xs[j], ys[j]);
        dis_[i][j] = k / (v2 * 1.0) <= 3
                         ? k / (v2 * 1.0)
                         : 3.0 + (k - v2 * 3.0) / (v1 * 1.0);
    }
    cout << setiosflags(ios::fixed) << setprecision(12) << dijkstra();
    return 0;
}