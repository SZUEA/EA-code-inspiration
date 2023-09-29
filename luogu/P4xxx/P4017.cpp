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

const int MAXN = 5010;
const int MOD = 80112002;
vector<vector<int>> mp(MAXN);
int q[MAXN], p[MAXN], d[MAXN];
queue<int> Q;
int n, m, a, b, res;

void solve()
{
    cin >> n >> m;
    rep(i, 1, m)
    {
        cin >> a >> b;
        mp[a].pb(b), q[a]++, p[b]++;
    }
    rep(i, 1, n) if (!p[i]) d[i] = 1, Q.push(i);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto ub : mp[u])
        {
            (d[ub] += d[u]) %= MOD, p[ub]--;
            if (p[ub] == 0)
            {
                if (q[ub] == 0)
                {
                    (res += d[ub]) %= MOD;
                    continue;
                }
                Q.push(ub);
            }
        }
    }
    cout << res;
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