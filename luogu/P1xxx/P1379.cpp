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

string sIn;
unordered_map<string, int> mp;
queue<string> Q;
string fine = "123804765";
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs()
{
    mp[sIn] = 0;
    Q.push(sIn);
    while (!Q.empty())
    {
        string sTemp = Q.front();
        Q.pop();
        int k = sTemp.find('0');
        int x = k / 3, y = k % 3;
        if (sTemp == fine)
            return mp[fine];
        rep(i, 0, 3)
        {
            int a = x + dir[i][0], b = y + dir[i][1];
            if (a >= 3 || b >= 3 || a < 0 || b < 0)
                continue;
            int dis = mp[sTemp];
            swap(sTemp[k], sTemp[a * 3 + b]);
            if (!mp.count(sTemp))
                mp[sTemp] = dis + 1, Q.push(sTemp);
            swap(sTemp[k], sTemp[a * 3 + b]);
        }
    }
    return 0;
}

void solve()
{
    cin >> sIn;
    cout << bfs();
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