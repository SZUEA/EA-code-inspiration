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

const int MAXN = 1010;

int dp[MAXN];
bool tms[MAXN];
int cnt[MAXN];
int itms[MAXN][MAXN];
int w[MAXN], v[MAXN];
int lw, ln, t, ts;

void solve()
{
    cin >> lw >> ln;
    rep(i, 1, ln)
    {
        cin >> w[i] >> v[i] >> t;
        ts=max(ts,t);
        cnt[t]++;
        itms[t][cnt[t]] = i;
    }
    rep(i, 1, ts) rep_r(j, lw, 0) rep(k, 1, cnt[i]) if (j >= w[itms[i][k]])
        dp[j] = max(dp[j], dp[j - w[itms[i][k]]] + v[itms[i][k]]);
    cout<<dp[lw];
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