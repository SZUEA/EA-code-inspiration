#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
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

const int MAXN = 110;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, i;
int arr[MAXN][MAXN];
void dfs(int num, int x = 1, int y = 1, int z = 0, int m = 1)
{
    if (m > num * num)
        return;
    arr[x][y] = m;
    if (!arr[x + dir[z][0]][y + dir[z][1]])
        if (!(x + dir[z][0] > num) && !(x + dir[z][0] < 1) &&
            !(y + dir[z][1] > num) && !(y + dir[z][1] < 1))
            dfs(num, x + dir[z][0], y + dir[z][1] ,z,m+1);
        else
            dfs(num, x + dir[(1 + z) % 4][0], y + dir[(1 + z) % 4][1], (1 + z) % 4,m+1);
    else
        dfs(num, x + dir[(1 + z) % 4][0], y + dir[(1 + z) % 4][1], (1 + z) % 4,m+1);
}

void solve()
{
    cin >> n;
    dfs(n);
    rep(i, 1, n)
    {
        rep(j, 1, n)cout<<setw(3)<<setfill(' ')<<arr[i][j];
        cout<<endl;
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