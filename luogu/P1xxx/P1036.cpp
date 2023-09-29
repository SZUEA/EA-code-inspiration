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

const int MAXN = 50;

int prime(int n)
{
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime[n];
}
int n, m, ans;
int arr[MAXN];
void dfs(int i = 1, int cnt = 0,int sum=0)
{
    if (cnt == m)
    {
        ans+=prime(sum);
        return;
    }
    if(cnt>m||i>n) return;
    dfs(i+1,cnt+1,sum+arr[i]);
    dfs(i+1,cnt,sum);
}

void solve()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> arr[i];
    dfs();
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