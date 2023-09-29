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

const int MAXN = 5e6+10;
int arr[MAXN];
int n, m;
void qst(int l, int r)
{
    if (l == r && l == m)
    {
        cout << arr[m];
        return;
    }
    if (l < r)
    {
        int start = l, end = r,ins = arr[l];
        while (start < end)
        {
            while (start < end && arr[end] >= ins)
                --end;
            if (start < end)
                swap(arr[start], arr[end]);
            while (start < end && arr[start] <= ins)
                ++start;
            if (start < end)
                swap(arr[start], arr[end]);
        }
        arr[start] = ins;
        if (start == m)
        {
            cout << arr[m];
            return;
        }
        if (start > m)
            return qst(l, start - 1);
        else
            return qst(start + 1, r);
    }
}
void solve()
{
    cin >> n >> m;
    m++;
    rep(i, 1, n) cin >> arr[i];
    qst(1, n);
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