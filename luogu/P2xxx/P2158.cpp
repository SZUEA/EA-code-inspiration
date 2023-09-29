#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
typedef long long ll;
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)

inline int euler_phi(int n)
{
    int m = int(sqrt(n + 0.5));
    int ans = n;
    rep(i, 2, m) if (n % i == 0)
    {
        ans = ans / i * (i - 1);
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    clock_t my_clock = clock();
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int q;
    ll sum = 0;
    cin >> q;
    rep(i, 1, q - 1)
        sum += euler_phi(i);
    cout << 2 * sum + (q == 1 ? 0 : 1) << " ";
#ifndef ONLINE_JUDGE
    cout << endl
         << "Time used " << clock() - my_clock << " ms." << endl;
#endif
    return 0;
}
