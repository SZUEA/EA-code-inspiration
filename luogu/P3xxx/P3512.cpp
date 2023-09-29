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

const int MAXN = 3e6 + 10;
/**
 * STL 50pts
 *
struct Point
{
    ll v;
    int ind;
};
deque<Point> decS, incS;
ll MAXLIMIT, num, priority=1;
int n, ans;
void solve()
{
    cin >> MAXLIMIT >> n;
    if(n==1){cout<<1;return;}
    rep(i, 1, n)
    {
        cin >> num;
        while (!decS.empty() && decS.back().v < num)
            decS.pop_back();
        while (!incS.empty() && incS.back().v > num)
            incS.pop_back();
        decS.push_back({num, i}), incS.push_back({num, i});
        while (decS.front().v - incS.front().v > MAXLIMIT)
            if (decS.front().ind < incS.front().ind)
                decS.pop_front(), priority = decS.front().ind;
            else
                incS.pop_front(), priority = incS.front().ind;
        ans = max(ans, i - priority+ 1);
    }
    cout << ans;
}
*/

int head_inc, head_dec, end_inc, end_dec;
ll Q_inc[MAXN], Q_dec[MAXN], arr[MAXN];
ll ans, priority;
ll MAXLIMIT, k;
int n;
void solve()
{
    cin >> MAXLIMIT >> n;
    rep(i, 1, n) cin >> arr[i];
    Q_dec[1] = Q_inc[1] = priority = 1;
    head_inc = end_inc = head_dec = end_dec = 1;
    rep(i, 2, n)
    {
        while (head_dec <= end_dec && arr[Q_dec[end_dec]] < arr[i])
            end_dec--;
        while (head_inc <= end_inc && arr[Q_inc[end_inc]] > arr[i])
            end_inc--;
        Q_dec[++end_dec] = Q_inc[++end_inc] = i;
        while (arr[Q_dec[head_dec]] - arr[Q_inc[head_inc]] > MAXLIMIT)
            if (Q_dec[head_dec] < Q_inc[head_inc])
                priority = Q_dec[head_dec] + 1, ++head_dec;
            else
                priority = Q_inc[head_inc] + 1, ++head_inc;
        ans = max(ans, i - priority + 1);
    }
    cout<<ans;
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