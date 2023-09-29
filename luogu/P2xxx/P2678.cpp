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

const int MAXN = 50010;

int arr[MAXN];
int len, n, m, res;

int judge(int x)
{
    int remove = 0, proceed = 0, temp = 0;
    while (proceed < n + 1)
    {
        proceed++;
        if (arr[proceed] - arr[temp] < x)
            remove++;
        else
            temp = proceed;
    }
    return remove <= m;
}

void solve()
{
    cin >> len >> n >> m;
    rep(i, 1, n) cin >> arr[i];
    arr[n + 1] = len;
    int l = 1, r = len, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid))
            res = mid, l = mid + 1;
        else
            r = mid - 1;
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