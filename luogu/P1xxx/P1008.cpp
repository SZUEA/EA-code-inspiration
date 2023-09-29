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
int j,k;
void solve()
{
    // int arr[4];
    // rep(i,100,333){
    //     j=i<<1,k=i*3;
    //     arr[1]=i,arr[2]=j,arr[3]=k;
    //     set <int> a;
    //     rep(u,1,3)rep(v,1,3){if(arr[u]%10)a.insert(arr[u]%10);arr[u]/=10;}
    //     if(a.size()==9)cout<<i<<" "<<j<<" "<<k<<endl;
    // }
    cout<<"192 384 576\n219 438 657\n273 546 819\n327 654 981";
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