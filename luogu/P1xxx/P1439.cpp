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

const int MAXN = 1e5 + 5;

map<int, int> mp;
int len, f[MAXN];
int arr[MAXN], ans;
void solve()
{
    cin >> len;
    memset(f, 0x3f, sizeof(f));
    rep(i, 1, len) cin >> arr[i], mp[arr[i]] = i;
    rep(i, 1, len) cin >> arr[i], arr[i] = mp[arr[i]];
    rep(i, 1, len)
    {
        *lower_bound(f + 1, f + ans + 1, arr[i]) = arr[i];
        if (f[ans + 1] < 0x3f3f3f3f) ans++;
    }
    cout << ans;
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