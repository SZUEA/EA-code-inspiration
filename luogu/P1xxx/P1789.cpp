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
bool mp[MAXN][MAXN];
int n, m, k, x, y, ans;
void solve()
{
    cin >> n >> m >> k;
    rep(i, 1, m)
    {
        cin >> x >> y;
        rep(k, x, x + 2) rep(l, y, y + 2) mp[k][l] = 1;
        mp[x - 1][y + 1] = mp[x + 1][y + 3] = mp[x + 1][y - 1] = mp[x + 3][y + 1] = 1;
    }
    if (k) rep(i, 1, k){cin>>x>>y; rep(p, x - 1, x + 3) rep(l, y - 1, y + 3) mp[p][l] = 1;}
    // rep(i, 2, n + 1) {rep(j, 2, n + 1)  cout<<mp[i][j]<<" "; cout<<endl;}
    rep(i, 2, n + 1) rep(j, 2, n + 1) ans += mp[i][j];
    cout << n * n - ans;
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