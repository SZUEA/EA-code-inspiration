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
/**
 * 区间中修改某一个数字
 *
 */
const int MAXN = 1e5 + 10;
int t[MAXN],n;

void add(int k, int v) {
  while (k <= n) {
    t[k] += v;
    k += lowbit(k);
  }
}

int getsum( int k) {
  int ret = 0;
  while (k) {
    ret += t[k];
    k -= lowbit(k);
  }
  return ret;
}


int op, x, y,m,temp;
void solve()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> temp, add(i, temp);
    rep(i, 1, m)
    {
        cin >> op >> x >> y;
        if (op - 1)
            cout << getsum(y)-getsum(x-1) << endl;
        else
            add(x, y);
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