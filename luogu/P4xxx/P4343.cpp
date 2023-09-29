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

const int MAXN = 1e5+10;

ll l_, k, ans1=-1, ans2=-1;
ll a[MAXN];

ll judge(ll x)
{
    ll tot = 0, i = 1, cnt = 0;
    while (i <= l_)
    {
        tot += a[i];
        if (tot < 0)
            tot = 0;
        if (tot >= x)
            cnt++, tot = 0;
        i++;
    }
    return cnt;
}

inline void input()
{
    cin >> l_ >> k;
    rep(i, 1, l_) cin >> a[i];
}

inline void output()
{
    cout << ans1 << " " << ans2;
}

inline void subtask1()
{

    ll l = 1, r = 1e18, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid) <= k)
        {
            r = mid - 1;
            if (judge(mid) == k)
                ans1 = mid;
        }
        else
            l = mid + 1;
    }
}

inline void subtask2()
{

    ll l = 1, r = 1e18, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid) >= k)
        {
            l = mid + 1;
            if (judge(mid) == k)
                ans2 = mid;
        }
        else
            r = mid - 1;
    }
}

inline void spj(ll num){
    if(num==-1){
        cout<<-1<<endl;
        exit(0);
    }
}

void solve()
{
    input();
    subtask1();
    spj(ans1);
    subtask2();
    spj(ans2);
    output();
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