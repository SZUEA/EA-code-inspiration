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

const int MAXN = 1e5 + 10;
int n, cnt;
char flag='0';
string s;
queue<int> D;
void solve()
{
    while(cin>>s)
    {
        rep(i, 0, s.length() - 1)
        {
            if (s[i] == flag)
            {
                cnt++;
            }
            else
            {
                D.push(cnt);
                cnt = 1;
                flag = s[i];
            }
        }
    }
    if(cnt>0)D.push(cnt);
    cout<<s.length()<<" ";
    while(!D.empty())cout<<D.front()<<" ",D.pop();
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