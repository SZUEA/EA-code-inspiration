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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int tot[0xff] = {0}, tot_=0;
        rep(i, 0, n - 1)
        {
            if (tot[s[i]])
            {
                tot_ = i;
                break;
            }
            tot[s[i]] = 1;
        }
        unordered_set<char> S;
        int sum = tot_;
        while (tot_ < n)
            S.insert(s[tot_++]);
        cout<<S.size()+sum<<endl;
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