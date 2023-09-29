#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 1010;

struct D{
    int v,i;
}arr[MAXN];
int n;
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> arr[i].v, arr[i].i = i;
    sort(arr + 1, arr + 1 + n, [](D a, D b) { return a.v < b.v; });
    rep(i, 1, n) cout << arr[i].i << " ";
    double ans = 0;
    rep(i, 1, n) ans += (n - i) * arr[i].v;
    cout << endl
         << fixed << setprecision(2) << ans / n;
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