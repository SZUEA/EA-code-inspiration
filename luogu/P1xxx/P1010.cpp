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

int num;

string div(int num)
{
    string res;
    int i = 0;
    while (num)
    {
        if (num & 1)
            if (i == 0)
                res = "+2(0)" + res;
            else if (i == 1)
                res = "+2" + res;
            else
                res = "+2(" + div(i) + ")" + res;
        num >>= 1;
        i++;
    }
    return res.substr(1);
}

void solve()
{
    cin >> num;
    cout << div(num);
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