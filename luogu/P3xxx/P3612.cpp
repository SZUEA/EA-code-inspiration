#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

string str;
ll n;

ll gtlen(ll n)
{
    ll bd = str.length();
    while (bd < n)
        bd <<= 1;
    return bd;
}

char func(ll n)
{
    if (n <= str.length())
        return str[n - 1];
    ll len = gtlen(n);
    ll flg = n - (len >> 1) - 1;
    if (!flg)
        return func(n - 1);
    else
        return func(flg);
}

void solve()
{
    cin >> str >> n;
    cout << func(n);
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