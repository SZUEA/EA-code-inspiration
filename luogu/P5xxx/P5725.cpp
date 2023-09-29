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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n * n; i++)
        cout << setw(2) << setfill('0') << i << (i % n ? "" : "\n");
    cout << "\n";
    for (int i = 1, k = 0; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << "  ";
        for (int j = 1; j <= i; j++)
            cout << setw(2) << setfill('0') << ++k;
        cout << endl;
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