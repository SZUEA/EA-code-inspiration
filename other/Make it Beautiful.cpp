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

const int MAXN = 110;
int n,arr[MAXN];

void solve()
{
    caseT{
        cin>>n;
        rep(i,1,n)cin>>arr[i];
        sort(arr+1,arr+n+1,[&](int a,int b){return a>b;});
        if(arr[1]==arr[2]){if(arr[1]==arr[n])
        {cout<<"NO"<<endl;continue;}
        swap(arr[n],arr[1]);}
        cout<<"Yes"<<endl;
        rep(i,1,n){cout<<arr[i]<<" ";
        }cout<<endl;
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