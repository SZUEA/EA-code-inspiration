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

const int MAXN = 1e5 + 10;

struct pt
{
    int t, v;
} p[MAXN << 2];

int rec[MAXN];
int t, sum, it, k;
int n, m;
void solve()
{
    caseT
    {
        cin >> n >> m;
        rep(i, 1, m)
        {
            cin >> k;
            p[++t].t = n;
            p[t].v = k;
            if (!rec[k])
                sum++;
            rec[k]++;
        }
        while (n >= 86400 + p[it].t)
        {
            k = p[it].v;
            rec[k]--;
            if (!rec[k])
                sum--;
            it++;
        }
        cout << sum << endl;
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