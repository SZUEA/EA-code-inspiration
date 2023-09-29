#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
#define pb push_back
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
string s[MAXN];
int n, m, i = 1;
int c;
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> c;
        string p;
        do
            p += c % 10 + '0';
        while (c /= 10);
        rep_r(j, p.size() - 1, 0) s[i] += p[j];
    }
    sort(s + 1, s + 1 + n, [](string a, string b)
         { return a + b > b + a; });
    rep(i, 1, n) cout << s[i];
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