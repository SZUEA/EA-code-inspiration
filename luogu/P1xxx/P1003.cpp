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

const int MAXN = 1e4 + 10;
struct Carpet
{
    int x, y, w, h;
} c[MAXN];
int n, a, b;
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> c[i].x >> c[i].y >> c[i].w >> c[i].h;
    cin >> a >> b;
    rep_r(i, n, 1) if (a >= c[i].x && a <= c[i].x + c[i].w && b >= c[i].y && b <= c[i].y + c[i].h)
    {
        cout << i << endl;
        return;
    }
    cout << -1 << endl;
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