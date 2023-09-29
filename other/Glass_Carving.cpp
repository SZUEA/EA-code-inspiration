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

const int MAXN = 1e5 + 10;
multiset<int> hl, vl;
multiset<int>::iterator last;
set<int> hi, vi;
int W, H, n, a, L, R;
char c;
void solve()
{
    cin >> W >> H >> n;
    hi.insert(0), vi.insert(0);
    hi.insert(W), vi.insert(H);
    hl.insert(W), vl.insert(H);
    rep(i, 1, n)
    {
        cin >> c >> a;
        if (c == 'H')
        {
            vi.insert(a);
            last = vi.find(a);
            L = *(--last);                      // 找到切割左端点
            last++;                             // 回溯
            R = *(++last);                      // 找到切割右端点
            vl.erase(last = vl.find(R - 1));    // 删除原先的大长度
            vl.insert(R - a), vl.insert(a - L); // 加入切割后两边长度
        }
        else
        {
            hi.insert(a);
            last = hi.find(a);
            L = *(--last);                      // 找到切割左端点
            last++;                             // 回溯
            R = *(++last);                      // 找到切割右端点
            hl.erase(last = hl.find(R - 1));    // 删除原先的大长度
            hi.insert(R - a), hl.insert(a - L); // 加入切割后两边长度
        }
        last = vl.end();
        int Hmax = *(--last);//纵向最大
        last = hl.end();
        int Wmax = *(--last);//横向最大
        int Area=Hmax*Wmax;//面积最大
        cout<<Area<<endl;
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