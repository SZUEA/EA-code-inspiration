#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
using namespace std;
const int N = 1e6 + 10;
int n, k, sv[N];
queue<int> Qo;
deque<int> Q;
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> k;
    rep(i, 1, n)
            cin >>
        sv[i];
    rep(i, 1, n)
    {
        while ( Q.size() >= 1&&Q.back() > sv[i] )
            Q.pop_back();
        Q.push_back(sv[i]);
        if (i >= k + 1 && Q.front() == sv[i - k])
            Q.pop_front();
        if (i > k-1)
            cout << Q.front() << " ";
    }
    cout << "\n";
    Q.clear();
    rep(i, 1, n)
    {
        while ( Q.size() >= 1&&Q.back() < sv[i] )
            Q.pop_back();
        Q.push_back(sv[i]);
        if (i >= k + 1 && Q.front() == sv[i - k])
            Q.pop_front();
        if (i > k-1)
            cout << Q.front() << " ";
    }
    cout << "\n";
}