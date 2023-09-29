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

int sec;
string num;
const string HEX = "0123456789ABCDEF";

int isReString(string n)
{
    int len = n.length();
    rep(i, 0, len >> 1) if (n[i] ^ n[len - i - 1]) return 0;
    return 1;
}

string reverse(string n)
{
    int len = n.length();
    rep(i, 0, (len-1) >> 1) swap(n[i], n[len - i-1]);
    return n;
}

string add(string n1, string n2, int sect)
{
    string s;
    int len = n1.length();
    int c = 0;
    rep_r(i, len - 1, 0)
    {
        int p = HEX.find(n1[i]) + HEX.find(n2[i]) + c;
        s = HEX[p % sect] + s;
        c = p /= sect;
    }
    if (c)
        s = '1' + s;
    return s;
}

void solve()
{
    cin >> sec >> num;
    int t = 0;
    while (++t <= 300000)
    {
        num = add(num, reverse(num), sec);
        if (isReString(num))
        {
            cout << "STEP=" << t;
            return;
        }
    }
    cout<<"Impossible!";
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