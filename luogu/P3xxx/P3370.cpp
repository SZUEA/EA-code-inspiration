#include <bits/stdc++.h>
#define ll long long
#define N 10010
using ull = unsigned ll;
const ull base = 1e9 + 7;
ull powb[N];
int powb_n;
inline int max(int a, int b)
{
    return a > b ? a : b;
}
void init_powb(int n)
{
    powb[0] = 1;
    for (int i = powb_n + 1; i <= n; i++)
        powb[i] = powb[i - 1] * base;
    powb_n = max(powb_n, n);
}
class HASH
{
public:
    ull a[N];
    void init(int n, char *s)
    {
        init_powb(n);
        for (int i = 0; i < n; i++)
            a[i] = a[i - 1] * base + s[i];
    }
    ull query(int l, int r)
    {
        return a[r] - (a[l - 1] * powb[r - l + 1]);
    }
};


int has[N];
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        HASH a;
        char s[N];
        scanf("%s", s);
        int len = strlen(s);
        a.init(len, s);
        has[i] = a.a[len - 1];
    }
    int ans = 0;
    std::sort(has + 1, has + 1 + n);
    for (int i = 2; i <= n; i++)
        if (has[i - 1] != has[i])
            ans++;
    printf("%d", ans + 1);
    return 0;
}
