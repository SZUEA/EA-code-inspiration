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

int tem[10][20] = {
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0}};
int n;
char c;
string res[5];
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> c, c -= '0';
        rep(k, 0, 19) res[k >> 2] += (tem[c][k] ? 'X' : '.');
    }
    rep(i, 0, 4) cout << res[i].substr(0, (n << 2) - 1) << endl;
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