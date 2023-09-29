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
const int MAXN = 110;
int sum0 = 0, sum1 = 0;
int f[MAXN];
void solve()
{
    int flg = 0;
    int T;
    cin >> T;
    rep(i, 1, T) cin >> f[i];
    rep(i, 1, T)
        if (sum0 + f[i] > 0 && flg >= 1)
            sum1 += sum0 + f[i], flg = 0, f[i] = sum0 + f[i], i--, sum0 = 0;
        else
            sum0 += f[i], flg++;
    cout << sum1;
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