#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define db double
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define eps 1e-14
#define MINN 1e-14
const int N = 1000005;
double a, b, c;

inline db f(db x)
{
    return a * x * x * x * x * x + b * x + c;
}

db bin(db l, db r)
{
    while (l < r)
    {
        db mid = (l + r) / 2;
        if (f(l) * f(mid) > 0)
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
    cin >> a >> b >> c;
    cout << fixed << setprecision(14) << bin(1, 2);
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
    cout << endl
         << "Time used " << clock() - start_time << " ms." << endl;
#endif
    return 0;
}