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

const int MAXN = 1e2 + 10;
/**
bool deg[MAXN];
unordered_set<int> tree[MAXN];

void dfs(int n, int node, int cnt = 1, vector<int> list = vector<int>())
{
    list.pb(node);
    if (n == cnt)
    {
        for (auto &&i : list)
            cout << i << " ";
        return;
    }
    if (tree[node].empty())
        return;
    for (auto &&i : tree[node])
        dfs(n, i, cnt + 1, list);
}
 *
*/

int a[MAXN][MAXN];
int cnt[MAXN];
void solve()
{ /**

     caseT
     {
         int n, fir, nxt;
         cin >> n;
         rep(i, 1, n) tree[i].clear(),deg[i]=0;
         rep(i, 1, n)
         {
             cin >> fir;
             rep(j, 2, n - 1)
             {
                 cin >> nxt;
                 tree[fir].insert(nxt);
                 deg[nxt] = 1;
                 fir = nxt;
             }
         }
         rep(i, 1, n) if (!deg[i])
         {
             dfs(n, i);
             cout<<endl;
             break;
         }
     }
 */
    caseT
    {
        int n;
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        memset(a,0,sizeof(a));
        rep(i,1,n){
            rep(j,1,n-1){
                cin>>a[i][j];
            }
            cnt[a[i][1]]++;
        }
        int x=max_element(cnt+1,cnt+1+n)-cnt;
        rep(i,1,n){
            if(a[i][1]^x){
                cout<<x;
                int q=0;
                while (a[i][++q])
                    cout<<" "<<a[i][q];
                cout<<endl;
                break;
            }
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