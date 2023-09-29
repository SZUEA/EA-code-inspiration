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

int n, p, x, y;
bool bs[10005];
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> p;
    rep(i, 1, p)
    {
        cin >> x >> y;
        memset(bs + x + 1, 1, (y - x + 1) * sizeof(bool));
    }
    cout << n - accumulate(bs + 1, bs + n + 1, 0) + 1;
    return 0;
}