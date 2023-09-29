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

int n, a, res;
int sum[2], rem[8];
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a;
        sum[i & 1] = (sum[!(i & 1)] + a) % 7;
        int *cur = &rem[sum[i & 1]];
        if (!*cur)
            *cur = i;
        else
            res = max(res, i - *cur);
        if (!sum[i & 1])
            res = i;
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