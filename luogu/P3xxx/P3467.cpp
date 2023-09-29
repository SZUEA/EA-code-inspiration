#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
using namespace std;
const int N = 3e5 + 10;

long long input, rub;
stack<long long> S;

int insert(long long ll)
{
    int status = 0;
    while (!S.empty() && S.top() >= ll)
    {
        status = S.top() == ll;
        S.pop();
    }
    S.push(ll);
    return status;
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, cou;
    cin >> n;
    cou = n;
    rep(i, 1, n)
    {
        cin >> rub >> input;
        cou -= insert(input);
    }
    cout<<cou;
    return 0;
}