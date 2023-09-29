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

const int MAXN = 1e6 + 10;

struct Road
{
    int x, y, t;
} roads[MAXN];
int fa[MAXN], n, m, x, y, t;
void init() { rep(i, 1, n) fa[i] = i; }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void solve()
{
    cin >> n >> m;
    init();
    rep(i, 1, m) cin >> roads[i].x >> roads[i].y >> roads[i].t;
    sort(roads+1,roads+m+1,[](Road a,Road b){return a.t<b.t;});
    rep(i,1,m){
        x=find(roads[i].x),y=find(roads[i].y);
        if(x^y)fa[x]=y,--n;if(n==1){cout<<roads[i].t;break;}
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