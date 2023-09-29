#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
/**
 * @author Kiramei
 * |    St Tabel      |
 * 
*/
inline void read(int &x)
{
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
}
inline void print(int x)
{
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
using namespace std;

const int N = 1e5+10;
int lg[N], a[N], mx[N][30];
int n, m;

inline void ini()
{
    rep(i, 1, n)
        mx[i][0] = a[i];
    lg[1] = 0;
    rep(i, 2, n)
        lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
    for (int i = 1; (1 << i) <= n; i++)
        rep(j, 1, 1 + n - (1 << i))
            mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
}

int fnd(int l, int r)
{
    int k = lg[r - l + 1];
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
int main()
{
    read(n), read(m);
    rep(i, 1, n)
        read(a[i]);
    ini();
    rep(i, 1, m)
    {
        int l, r;
        read(l), read(r);
        printf("%d\n", fnd(l, r));
    }
    return 0;
}