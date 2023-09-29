#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)

const int MAXN = 1e5 + 10;
db tree[MAXN << 2], lazy[MAXN << 2], tree_2[MAXN << 2];

void pushUp(int p)
{
    tree[p] = tree[ls(p)] + tree[rs(p)];
    tree_2[p] = tree_2[ls(p)] + tree_2[rs(p)];
}

void pushDown(int p, int m, int s, int t)
{
    if (lazy[p])
    {
        tree_2[ls(p)] += ((m - s + 1) * lazy[p] + (tree[ls(p)] * 2)) * lazy[p];
        tree_2[rs(p)] += ((t - m) * lazy[p] + (tree[rs(p)] * 2)) * lazy[p];
        tree[ls(p)] += lazy[p] * (m - s + 1);
        tree[rs(p)] += lazy[p] * (t - m);
        lazy[ls(p)] += lazy[p];
        lazy[rs(p)] += lazy[p];
        lazy[p] = 0;
    }
}

void build(int s, int t, int p)
{
    if (s == t)
    {
        cin >> tree[p];
        tree_2[p] = tree[p] * tree[p];
        return;
    }
    int m = (t + s) >> 1;
    build(s, m, ls(p));
    build(m + 1, t, rs(p));
    pushUp(p);
}

db query1(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return tree[p];
    int m = (t + s) >> 1;
    db sum = 0;
    pushDown(p, m, s, t);
    if (l <= m)
        sum += query1(l, r, s, m, ls(p));
    if (r > m)
        sum += query1(l, r, m + 1, t, rs(p));
    return sum;
}

db query2(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return tree_2[p];
    int m = (t + s) >> 1;
    db sum = 0;
    pushDown(p, m, s, t);
    if (l <= m)
        sum += query2(l, r, s, m, ls(p));
    if (r > m)
        sum += query2(l, r, m + 1, t, rs(p));
    return sum;
}

void update(int l, int r, db c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        tree_2[p] += ((t - s + 1) * c + (tree[p] * 2)) * c;
        tree[p] += (t - s + 1) * c;
        lazy[p] += c;
        return;
    }
    int m = (t + s) >> 1;
    pushDown(p, m, s, t);
    if (l <= m)
        update(l, r, c, s, m, ls(p));
    if (r > m)
        update(l, r, c, m + 1, t, rs(p));
    pushUp(p);
}

int n, T;
void solve()
{
    cin >> n >> T;
    build(1, n, 1);
    while (T--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int o, m;
            db f;
            cin >> o >> m >> f;
            update(o, m, f, 1, n, 1);
        }
        else if (k == 2)
        {
            int o, m;
            cin >> o >> m;
            cout << fixed << setprecision(4) << query1(o, m, 1, n, 1) / (m - o + 1) << endl;
        }
        else
        {
            int o, m;
            cin >> o >> m;
            double oven = query1(o, m, 1, n, 1) / (m - o + 1);
            double odd = query2(o, m, 1, n, 1) / (m - o + 1);
            cout << fixed << setprecision(4) << odd - oven * oven << endl;
        }
    }
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