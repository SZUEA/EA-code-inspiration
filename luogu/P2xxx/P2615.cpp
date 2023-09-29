#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)
struct Kp
{
    int x, y;
} kp;
const int MAXN = 110;
int mp[MAXN][MAXN];
void table(int i)
{
        int u = 1;
        mp[1][(i >> 1) + 1] = 1, kp.x = 1, kp.y = (i >> 1) + 1;
        while (++u <= i * i)
            if (kp.x == 1 && kp.y != i)
            {
                kp.x = i, kp.y++;
                mp[kp.x][kp.y] = u;
            }
            else if (kp.x != 1 && kp.y == i)
            {
                kp.x--, kp.y = 1;
                mp[kp.x][kp.y] = u;
            }
            else if (kp.x == 1 && kp.y == i)
            {
                kp.x++, kp.y;
                mp[kp.x][kp.y] = u;
            }
            else if (kp.x != 1 && kp.y != i)
            {
                if (mp[kp.x - 1][kp.y + 1] == 0)
                {
                    kp.x--, kp.y++;
                    mp[kp.x][kp.y] = u;
                }
                else
                {
                    kp.x++;
                    mp[kp.x][kp.y] = u;
                }
            }
        rep(k,1,i)rep(j,1,i)cout<<mp[k][j]<<" \n"[j==i];
}
int n;
void solve()
{
    cin>>n;
    table(n);
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