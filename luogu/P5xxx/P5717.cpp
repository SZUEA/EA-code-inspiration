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

int a, b, c;

void solve()
{
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "Not triangle" << endl;
        return;
    }
    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        cout << "Right triangle" << endl;
    else if (a * a + b * b < c * c || a * a + c * c < b * b || b * b + c * c < a * a)
        cout << "Obtuse triangle" << endl;
    else if (a * a + b * b > c * c || a * a + c * c > b * b || b * b + c * c > a * a)
        cout << "Acute triangle" << endl;
    if (a == b || b == c || a == c)
        cout << "Isosceles triangle" << endl;
    if (a == b && b == c)
        cout << "Equilateral triangle" << endl;
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