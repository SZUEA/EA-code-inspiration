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
int n, res, s1, s2;
int arr[MAXN], mx[MAXN], mn[MAXN];
stack<int> S;
stack<int> s;
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        while (s1 && arr[mx[s1]] >= arr[i])
            s1--; // pop操作，维持单调递减
        while (s2 && arr[mn[s2]] < arr[i])
            s2--; // 同上，维持单调严格递增
        int m = upper_bound(mx + 1,mx  + 1 + s1, mn[s2]) - mx;
        if (m != (s1 + 1))
            res = max(res, i - mx[m] + 1);
        mn[++s2] = mx[++s1] = i;
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