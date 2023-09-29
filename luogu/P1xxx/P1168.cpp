#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
#define pb push_back
#define ub upper_bound
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)
namespace solution1
{
    int n, q;
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    priority_queue<int, vector<int>, less<int>> bigHeap;
    void solution()
    {
        cin >> n;
        rep(i, 1, n)
        {
            cin >> q;
            if(i==1){smallHeap.push(q);cout<<q<<endl;continue;}
            if(!(i%2))
            {
                int current=smallHeap.top();
                if(q<=current)bigHeap.push(q);
                else smallHeap.pop(),smallHeap.push(q),bigHeap.push(current);
            }else
            {
                int current=bigHeap.top();
                if(q>=current)smallHeap.push(q);
                else bigHeap.pop(),bigHeap.push(q),smallHeap.push(current);
                cout<<smallHeap.top()<<endl;
            }
        }
    }
}

namespace solution2
{
    int n,q;
    vector<int> V;
    void solution(){
        cin>>n;
        rep(i,1,n){
            cin>>q;
            V.insert(ub(V.begin(),V.end(),q),q);
            if(i&1)cout<<V[(i-1)>>1]<<endl;
        }
    }
} 


void solve()
{
    solution2::solution();
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