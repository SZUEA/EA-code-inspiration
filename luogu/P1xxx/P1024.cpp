#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define db double
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define eps 1e-5
#define MINN 1e-10
const int N = 1000005;
double a, b, c, d;

inline db f(db x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

db bin(db l, db r)
{
    while (l < r)
    {
        db mid = (l + r) / 2;
        if (f(l) * f(mid) > 0 )
            l = mid;
        else
            r = mid;
        if (abs(l - r) < eps)
        {
            return l;
        }
    }
    return l;
}

void solve()
{
    cin >> a >> b >> c >> d;
    rep(i, -100, 99)
    {
        const db ss = f(i);
        if (abs(ss) < MINN)
        {
            cout << fixed << setprecision(2) << (double)i << " ";
            continue;
        }
        if (f(i) * f(i + 1 - eps) < 0)
            cout << fixed << setprecision(2) << bin(i, i + 1) << " ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    clock_t start_time = clock();
#endif
    solve();
#ifndef ONLINE_JUDGE
    clock_t end_time = clock();
    cout << end_time - start_time << "ms";
#endif
    return 0;
}