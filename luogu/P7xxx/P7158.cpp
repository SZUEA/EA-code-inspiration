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

const int MAXN = 100010;
const int MOD = 998244353;
ll fn[MAXN], gn[MAXN];

void solve()
{
    fn[1] = 8, gn[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        fn[i] = (fn[i - 1] * 9 + gn[i - 1]) % MOD;
        gn[i] = (gn[i - 1] * 9 + fn[i - 1]) % MOD;
    }
    caseT
    {
        int a, b;
        cin >> a >> b;
        cout << (a == 1 ? 9 : fn[a]) << endl;
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