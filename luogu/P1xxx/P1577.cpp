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

const int MAXN = 10010;

int n, m;
int mx;
int arr[MAXN];

int bin(int st, int ed)
{
    if (st > ed)
        return ed;
    int mid = (st + ed) >> 1;
    if(mid==0)return ed;
    int cnt = 0;
    rep(i, 1, n) cnt += (int)(arr[i] / mid);
    if (cnt >= m)
        bin(mid + 1, ed);
    else if (cnt < m)
        bin(st, mid - 1);
}
void solve()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        double c;
        cin >> c;
        arr[i] = c * 100;
        mx = mx > arr[i] ? mx : arr[i];
    }
    int a=bin(0, 100000000);
    cout<<fixed<<setprecision(2)<<a/100.0;
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