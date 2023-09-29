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

const int MAXN = 1e2 + 10;
const int MOD = 1e9 + 7;
ll mat[MAXN][MAXN << 1];
int n;

ll qpow(ll a, ll k, ll p)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % p;
        a = a * a % p, k >>= 1;
    }
    return ans % p;
}

bool gauss()
{
    rep(i, 1, n)
    {
        int r = i;
        rep(j, i, n) if (mat[j][i])
        {
            r = j;
            break;
        }
        if (r ^ i)
            swap(mat[i], mat[r]);
        if (!mat[i][i])
            return 0;
        int x = qpow(mat[i][i], MOD - 2, MOD);
        rep(j, 1, n)
        {
            if (j == i)
                continue;
            int t = mat[j][i] * x % MOD;
            rep(k, i, n << 1) mat[j][k] = ((mat[j][k] - t * mat[i][k]) % MOD + MOD) % MOD;
        }
        rep(j, 1, n << 1) mat[i][j] = mat[i][j] * x % MOD;
    }
    return 1;
}

void solve()
{
    cin >> n;
    rep(i, 1, n) rep(j, 1, n) cin >> mat[i][j];
    rep(i, 1, n) mat[i][i + n] = 1;
    if (gauss())
        rep(i, 1, n)
        {
            rep(j, n + 1, n << 1) cout << mat[i][j] << " ";
            cout << endl;
        }
    else
        cout << "No Solution";
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