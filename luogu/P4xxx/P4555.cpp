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

int ans, ans2;

const int N = 1e5 + 10;
char s1[N * 2];
int hw[N * 2], lw[N * 2], rw[N * 2];

void manacher(int n0, char *s0)
{
    static char s[N * 2];
    int n = 0;
    s[++n] = '$', s[++n] = '#';
    rep(i, 1, n0)
        s[++n] = s0[i],
        s[++n] = '#';
    s[++n] = '@';
    int mid = 0, mxr = 0;
    rep(i, 2, n - 1)
    {
        hw[i] = i <= mxr ? min(mxr - i + 1, hw[(mid << 1) - i]) : 1;
        lw[i - hw[i] + 1] = max(hw[i], lw[i - hw[i] + 1]), rw[i + hw[i] - 1] = max(hw[i], rw[i + hw[i] - 1]);
        while (s[i - hw[i]] == s[i + hw[i]])
            hw[i]++, lw[i - hw[i] + 1] = max(hw[i], lw[i - hw[i] + 1]), rw[i + hw[i] - 1] = max(hw[i], rw[i + hw[i] - 1]);
        if (mxr < i + hw[i])
            mxr = i + hw[i] - 1, mid = i;
        ans2 = max(ans2, hw[i]);
    }
    rep(i, 1, n)
        ans = max(ans, lw[i] + rw[i] - 2);
}

void solve()
{
    cin >> s1 + 1;
    manacher(strlen(s1 + 1), s1);
    if (ans2 == ans + 1)
        ans--;
    cout << ans;
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
