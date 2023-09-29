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

const int MAXN = 3e4 + !0;
struct Item
{
    int c, i;
} its[50];
int dp[MAXN];
int all, itn;

void solve()
{
    cin >> all >> itn;
    rep(i, 1, itn) cin >> its[i].c >> its[i].i;
    rep(i, 1, itn) rep_r(j, all, its[i].c)
        dp[j] = max(dp[j], dp[j - its[i].c] + its[i].c * its[i].i);
    cout<<dp[all];
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