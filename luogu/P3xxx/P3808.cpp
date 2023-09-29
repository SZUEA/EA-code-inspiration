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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int N = 1e6 + 10;

int tr[N][26], tot;
int e[N], fa[N];

void insert(char *s)
{
    int u = 0;
    for (int i = 1; s[i]; i++)
    {
        if (!tr[u][s[i] - 'a'])
            tr[u][s[i] - 'a'] = ++tot;
        u = tr[u][s[i] - 'a'];
    }
    e[u]++;
}

queue<int> q;

void build()
{
    rep(i, 0, 25) if (tr[0][i]) q.push(tr[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        rep(i, 0, 25) if (tr[u][i])
            fa[tr[u][i]] = tr[fa[u]][i],
            q.push(tr[u][i]);
        else tr[u][i] = tr[fa[u]][i];
    }
}

int query(char *t)
{
    int u = 0, res = 0;
    for (int i = 1; t[i]; i++)
    {
        u = tr[u][t[i] - 'a'];
        for (int j = u; j && e[j] != -1; j = fa[j])
            res += e[j], e[j] = -1;
    }
    return res;
}
int n;
char s[N];
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> s + 1, insert(s);
    build();
    cin >> s + 1;
    cout << query(s);
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
