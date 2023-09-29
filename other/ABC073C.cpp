#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
using namespace std;

set<int> a;
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    rep(i, 1, n)
    {
        int j;
        cin >> j;
        if (a.count(j))
            a.erase(j);
        else
            a.insert(j);
    }
    cout << a.size();
    return 0;
}