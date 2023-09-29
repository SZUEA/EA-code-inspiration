#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

int n;
const string reg = "0010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000000010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100000001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010000000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001";
void solve()
{
    cin >> n;
    cout << reg[n - 1582] << endl;
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