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
const db EPS = 1e-10;
db mat[MAXN][MAXN];
int n;

bool gauss()
{
    rep(i, 1, n)
    {
        int r = i;
        rep(j, i, n) if (abs(mat[j][i]) > EPS)
        {
            r = j;
            break;
        }
        if (r ^ i)
            swap(mat[r], mat[i]);
        if (abs(mat[i][i]) < EPS)
            return 0;
        rep_r(j, n + 1, i) mat[i][j] /= mat[i][i];
        rep(j, i + 1, n) rep_r(k, n + 1, i) mat[j][k] -= mat[j][i] * mat[i][k];
    }
    rep_r(i, n - 1, 1) rep(j, i + 1, n) mat[i][n + 1] -= mat[i][j] * mat[j][n + 1];
    return 1;
}

void solve()
{
    cin >> n;
    rep(i, 1, n) rep(j, 1, n + 1) cin >> mat[i][j];
    if (gauss())
        rep(i, 1, n) cout << fixed << setprecision(2) << mat[i][n + 1] << endl;
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