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
#define pi 3.141593
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

int T;

void solve()
{
    cin >> T;
    switch (T)
    {
    case 1:
        cout << "I love Luogu!";
        break;
    case 2:
        cout << 2 + 4 << " " << 10 - 2 - 4;
        break;
    case 3:
        cout << 14 / 4 << endl
             << 14 / 4 * 4 << endl
             << 14 % 4;
        break;
    case 4:
        cout << "166.667";
        break;
    case 5:
        cout << 15;
        break;
    case 6:
        cout << sqrt(6 * 6 + 9 * 9);
        break;
    case 7:
        cout << 110 << endl
             << 90 << endl
             << 0;
        break;
    case 8:
        cout << pi * 10 << endl
             << pi * 25 << endl
             << pi * 500 / 3.0;
        break;
    case 9:
        cout << 22;
        break;
    case 10:
        cout << 9;
        break;
    case 11:
        cout << 100.0 / (8 - 5);
        break;
    case 12:
        cout << "13\nR";
        break;
    case 13:
        cout << 16;
        break;
    case 14:
        cout << 50;
        break;
    default:
        break;
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