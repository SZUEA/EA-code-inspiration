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

const int MAXN =   3e6 + 10;
int n, maxY, q, res;
struct Node
{
    int x, y, v;
} node[MAXN];
int d[MAXN];
void solve()
{
    cin >> n;
    rep(i, 0, n - 1)
    {
        cin >> node[i].x >> node[i].y;
        node[i].v = node[i].y - node[i].x + 1;
        maxY = max(maxY, node[i].y);
    }
    sort(node, node + n, [](Node a, Node b)
         { return (a.x - b.x) ? a.x < b.x : a.y < b.y; });
    rep(i, 0, maxY)
    {
        d[i] = max(d[i], d[i - 1]);
        while (node[q].x == i && q < n)
            d[node[q].y] = max(d[node[q].y], d[node[q].x - 1] + node[q].v), q++;
        res = max(res, d[i]);
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