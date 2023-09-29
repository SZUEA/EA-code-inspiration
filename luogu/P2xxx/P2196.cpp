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

const int MAXN = 21;

int bomb[MAXN], n, tot;
bool mp[MAXN][MAXN];
vector<int> ans;

void dfs(int st, vector<int> v = vector<int>(), int sum = 0)
{
    v.push_back(st);
    sum += bomb[st];
    if (sum > tot) ans = v, tot = sum;
    rep(i, st, n) if (mp[st][i]) dfs(i, v, sum);
}

void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> bomb[i];
    rep(i, 1, n - 1) rep(j, i + 1, n) cin >> mp[i][j];
    rep(i, 1, n) dfs(i);
    for (auto i : ans)
        cout << i << ' ';
    cout << endl
         << tot;
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