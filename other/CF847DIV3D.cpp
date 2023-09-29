#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define lowbit(a) (a & -a)
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

const int MAXN = 1e5 + 10;

int a[MAXN];
void solve()
{
    caseT
    {
        int n;
        cin >> n;
        map<int, int> mp;
        memset(a, 0, sizeof(a));
        rep(i, 1, n) cin >> a[i], mp[a[i]]++;
        int ans = 0, last = 0, cnt = 0;
        for (auto &&i : mp)
        {
            if (i.first ^ last + 1)
                ans += i.second;
            else if (cnt < i.second)
                ans += i.second - cnt;
            last = i.first, cnt = i.second;
        }
        cout << ans << endl;
    }
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