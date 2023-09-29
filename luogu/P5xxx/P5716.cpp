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

int n1, n2;
const string reg1 = "0010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000000010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100000001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010000000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001";
const int reg2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve()
{
    cin >> n1 >> n2;
    cout << reg2[n2 - 1] + ((!~(n2 - 3)) & (reg1[n1 - 1582] - '0')) << endl;
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