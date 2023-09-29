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

const int MAXN = 1e5 + 10;
// const int MAXN = 1e2 + 10;
ll arr[MAXN], ind[MAXN], n, MOD, t, tot, pre,cnt;
char Q;
void solve()
{
    cin >> n >> MOD;
    rep(i, 1, n)
    {
        cin >> Q >> t;
        if (Q == 'A')
        {
            ll aft=(t + pre) % MOD;
            arr[++tot] = aft;
            while (cnt&&arr[ind[cnt-1]]<aft) cnt--;
             ind[cnt++] = tot;
        }else{
            pre=arr[*lower_bound(ind,ind+cnt,tot-t+1)];
            cout<<pre<<endl;
        }
    }
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