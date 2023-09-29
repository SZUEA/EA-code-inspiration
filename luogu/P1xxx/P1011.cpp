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
struct Stop
{
    int x, y;
} stps[MAXN], pre[MAXN];
int a, n, m, x, y;
void solve()
{
    cin >> a >> n >> m >> x;
    stps[2] = stps[1] = pre[1] = {0, a}, pre[2] = {1, 0};
    rep(i, 3, n - 1)
    {
        pre[i].x = pre[i - 1].x + pre[i - 2].x;
        pre[i].y = pre[i - 1].y + pre[i - 2].y;
        stps[i].x = stps[i - 1].x + pre[i - 2].x;
        stps[i].y = stps[i - 1].y + pre[i - 2].y;
    }
    y = (m - stps[n - 1].y) / stps[n - 1].x;
    cout << y * stps[x].x + stps[x].y;
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