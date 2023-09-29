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

const int MAXN = 1000010;

int n, w, ans;
int a[MAXN];
int flag[MAXN];
/*
    Wrong Answer
inline void dfs(int i, int cnt = 0, int sum = 0)
{
    if (cnt == 3 || i > n)
    {
        if (cnt != 0 && sum < w && flag[sum] == 0)
            ans++, flag[sum] = 1;
        return;
    }
    dfs(i + 1, cnt, sum);
    dfs(i + 1, cnt + 1, sum + a[i]);
}

void solve()
{
    cin >> n >> w;
    rep(i, 1, n) cin >> a[i];
    dfs(1);
    cout << ans;
}
*/

void solve()
{
    cin >> n >> w;
    rep(i, 1, n) cin >> a[i];
    int cnt = 0;
    rep(i, 1, n)
    {
        int tmp = a[i];
        if(tmp<=w&&flag[tmp]==0)
            ans++, flag[tmp] = 1;
    }
    rep(i, 1, n)
    {
        rep(j, i + 1, n)
        {
            int tmp = a[i] + a[j];
            if (tmp <= w && flag[tmp] == 0)
                ans++, flag[tmp] = 1;
        }
    }
    rep(i, 1, n)
    {
        rep(j, i + 1, n)
        {
            rep(k, j + 1, n)
            {
                int tmp = a[i] + a[j] + a[k];
                if (tmp <= w && flag[tmp] == 0)
                    ans++, flag[tmp] = 1;
            }
        }
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
    return 0;
}