#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 110;

struct Backpack
{
    int v, t;
    db rat;
} bp[MAXN];

int n,T;
db ans;

void solve()
{
    cin >> n>>T;
    rep(i, 1, n) cin >> bp[i].t >> bp[i].v, bp[i].rat = bp[i].v * 1.0 / bp[i].t;
    sort(bp + 1, bp + n + 1, [](Backpack a, Backpack b)
         { return a.rat > b.rat; });
    rep(i,1,n)if(bp[i].t>=T){ans+=(1.0*T/bp[i].t)*bp[i].v;break;}
    else ans+=bp[i].v,T-=bp[i].t;
    cout<<fixed<<setprecision(2)<<ans;
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