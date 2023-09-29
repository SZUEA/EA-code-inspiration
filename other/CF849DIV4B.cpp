#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
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

void solve()
{
    caseT
    {
        int x = 0, y = 0, n, flag = 0;
        cin >> n;
        while (n--)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
            case 'R':
                x += 1;
                break;
            case 'L':
                x -= 1;
                break;
            default:
                break;
            }
            if(y==1&&x==1)flag=1;
        }
        cout<<(flag?"YES":"NO")<<endl;
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