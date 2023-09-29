#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
using namespace std;
const int N = 3e6 + 10;

int input[N], output[N];
stack<int> pls;

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    rep(i, 1, n) cin >> input[i];
    rep_r(i, n, 1)
    {
        while (!pls.empty() && input[pls.top()] <= input[i])
            pls.pop();
        output[i] = pls.empty() ? 0 : pls.top();
        pls.push(i);
    }
    rep(i, 1, n) cout << output[i] << " ";
    return 0;
}