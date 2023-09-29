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

int ans;

const int N = 22000005;
char s1[N * 2];
int hw[N * 2];

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
        while (s[i - hw[i]] == s[i + hw[i]])
            hw[i]++;
        if (mxr < i + hw[i])
            mxr = i + hw[i] - 1, mid = i;
        ans = max(ans, hw[i]);
    }
}

void solve()
{
    cin >> s1 + 1;
    manacher(strlen(s1 + 1), s1);
    cout << ans - 1;
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