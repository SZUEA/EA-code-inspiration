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

const int MAXN = 1010;
int n, h, r;
int fa[MAXN];
struct Hole
{
    ll x, y, z;//不开long long日神仙
} holes[MAXN];
void init() { rep(i, 1, n) fa[i] = i; }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
db dist(Hole h1, Hole h2) { return sqrt((h1.x - h2.x) * (h1.x - h2.x) + (h1.y - h2.y) * (h1.y - h2.y) + (h1.z - h2.z) * (h1.z - h2.z)); }
vector<int> node_ground, node_top;
void solve()
{
    caseT
    {
        cin >> n >> h >> r;
        init();
        node_ground.clear();
        node_top.clear();
        rep(i, 1, n)
        {
            cin >> holes[i].x >> holes[i].y >> holes[i].z;
            if (holes[i].z + r >= h)
                node_top.pb(i);
            if (holes[i].z - r <= 0)
                node_ground.pb(i);
        }
        if (node_ground.empty() || node_top.empty())
        {
            cout << "No" << endl;
            continue;
        }
        rep(i, 1, n-1) rep(j, i + 1, n)
        {
            int a = find(i), b = find(j);
            if ((r << 1) >= dist(holes[i], holes[j]) && a != b)
                fa[a] = b;
        }
        for (auto &&i : node_ground)
            for (auto &&j : node_top)
                if (find(i) == find(j))
                {
                    cout << "Yes";
                    goto loop;
                }
        cout << "No";
    loop:
        cout << endl;
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