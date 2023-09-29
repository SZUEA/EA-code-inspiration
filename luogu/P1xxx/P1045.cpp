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

const int MAXN = 500;

vector<int> a(MAXN), res(MAXN);
int p;

vector<int> mul(vector<int> &a, vector<int> &b)
{
    vector<int> t(MAXN << 1);
    rep(i, 0, MAXN - 1) rep(j, 0, MAXN - 1)
    {
        t[i + j] += a[i] * b[j];
        t[i + j + 1] += t[i + j] / 10;
        t[i + j] %= 10;
    }
    return t;
}

void qpow(int p)
{
    res[0] = 1, a[0] = 2;
    while (p)
    {
        if (p & 1)
            res = mul(res, a);
        a = mul(a, a);
        p >>= 1;
    }
    res[0]--;
}

void solve()
{
    int n;
    cin >> n;
    cout << (int)(log10(2) * n + 1) << endl;
    qpow(n);
    rep_r(i, 499, 0) cout << res[i] << (i % 50 ? "" : "\n");
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