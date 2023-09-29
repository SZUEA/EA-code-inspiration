#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 110;
int n, ans, dp[MAXN][MAXN];
string s;
void solve()
{
    cin >> s;
    n = s.size();
    rep(i,1,n)rep(j,1,n)if(i==j)dp[i][j]=1;else dp[i][j]=0x3f3f3f3f;
    rep(i, 2, n) rep(l, 1, n - i + 1)
    {
        int r = l + i - 1;
        if (s[l - 1] == s[r - 1])
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
        else
            rep(k, l, r) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
    }
    cout << dp[1][n];
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