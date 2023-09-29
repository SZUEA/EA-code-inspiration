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
int qpow(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a;
        k >>= 1;
        a *= a;
    }
    return res;
}

const int MAXN = 110;

set<int> st;

void solve()
{
    int m, n;
    cin >> m >> n;
    rep(i, 1, m)
    {
        int a;
        cin >> a;
        st.insert(a);
    }
    rep(i, 1, n)
    {
        int c, d;
        cin >> c >> d;
        for (auto &&p : st)
        {
            if (!((p - d) % qpow(10,c)))
            {
                cout<<p;
                goto loop;
            }
        }
            cout << -1;
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