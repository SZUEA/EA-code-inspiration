#include <bits/stdc++.h>
#define min(a, b) a < b ? a : b
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rev_rep(i, s, t) for (int i = (s); i >= (t); i--)
#define N 10010
using ll = long long;
using namespace std;
int ci()
{
    int x;
    scanf("%d", &x);
    return x;
}
int n, m;
int f[N];

int getRoot(int o)
{
    return f[o] == o ? o : f[o] = getRoot(f[o]);
}
int main()
{
    n = ci(), m = ci();
    rep(i, 1, n) f[i] = i;
    rep(i, 1, m)
    {
        int op = ci(), num1 = ci(), num2 = ci();
        if (op & 1)
            f[getRoot(num1)] = getRoot(num2);
        else
            printf("%c\n", getRoot(num1) == getRoot(num2) ? 'Y' : 'N');
    }
    return 0;
}