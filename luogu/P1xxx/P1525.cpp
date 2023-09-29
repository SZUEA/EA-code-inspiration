#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
using namespace std;
const int N = 200010;
int ci()
{
    int x;
    scanf("%d", &x);
    return x;
}
struct T
{
    int u, v, t;
    void in(int a, int b, int c)
    {
        u = a, v = b, t = c;
        return;
    }
};
T e[N];
int fa[N * 2];
int fnd(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = fnd(fa[x]);
}
int main()
{
    int n = ci(), m = ci();
    iota(fa + 1, fa + 2 * (m + 1), 1);
    rep(i, 1, m)
    {
        int a = ci(), b = ci(), c = ci();
        e[i].in(a, b, c);
    }
    sort(e + 1, e + 1 + m, [](T a, T b)
         { return a.t > b.t; });
    int ans = 0;
    rep(i, 1, m)
    {
        int u = e[i].u, v = e[i].v;
        int t1 = fnd(u), t2 = fnd(v), t3 = fnd(u + n), t4 = fnd(v + n);
        if (t1 == t2 || t3 == t4)
        {
            ans = e[i].t;
            break;
        }
        else
        {
            fa[fa[u + n]] = fa[v];
            fa[fa[u]] = fa[v + n];
        }
    }
    printf("%d", ans);
    return 0;
}