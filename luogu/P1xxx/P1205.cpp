#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define lowbit(a) (a & -a)
#define donel '\n'
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
using namespace std;

int num;
string str, done, proc, res;

string recTo90Deg(string cu, int cnt)
{
    res = cu = (cnt - 1) ? recTo90Deg(cu, cnt - 1) : cu;
    rep(i, 0, num - 1) rep(j, 0, num - 1)
        res[j * num + num - 1 - i] = cu[i * num + j];
    return res;
}

string recToMir(string cu)
{
    res = cu;
    rep(i, 0, num - 1) rep(j, 0, num - 1)
        res[i * num + j] = cu[i * num + (num - j - 1)];
    return res;
}

void solve()
{
    cin >> num;
    rep(i, 0, (num << 1) - 1) cin >> proc, str += (i / num ? "" : proc), done += (i / num ? proc : "");

    rep(i, 1, 3) if (recTo90Deg(str, i) == done)
    {
        cout << i;
        return;
    }
    if ((proc = recToMir(str)) == done)
        cout << 4;
    else if (recTo90Deg(proc, 1) == done || recTo90Deg(proc, 2) == done || recTo90Deg(proc, 3) == done)
        cout << 5;
    else if (str == done)
        cout << 6;
    else
        cout << 7;
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