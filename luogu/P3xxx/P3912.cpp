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

const int MAXN = 100000001;

bitset<MAXN> vis;
int cnt, tot;

void init(int n)
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (!vis[i]&&++tot)
            if ((long long)i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    vis[j] = 1;
}

int n, m;
void solve()
{
    cin >> n;
    init(n);
    cout << tot << endl;
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