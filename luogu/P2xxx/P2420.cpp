#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
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
const int N = 500010;
struct T
{
    int nxt, to, w;
} t[N << 1];
int head[N];
int n, m, tot = 0, r;
int dep[N], fa[N][22], lg[N], x[N][22],col[N];
void addEdgeDbl(int a, int b, int c)
{
    t[++tot].to = b;
    t[tot].nxt = head[a];
    head[a] = tot;
    t[tot].w = c;
    t[++tot].to = a;
    t[tot].nxt = head[b];
    head[b] = tot;
    t[tot].w = c;
}

// preprocess
void dfs(int c, int f, int w)
{
    fa[c][0] = f, dep[c] = dep[f] + 1 ,col[c]=w;
    
    // c ancestor of 2^i -> c ancestor of 2^(i-1) 's ancestor of 2^(i-1)
    rep(i, 1, lg[dep[c]]) fa[c][i] = fa[fa[c][i - 1]][i - 1],
                          x[c][i] = x[c][i - 1] ^ x[fa[c][i - 1]][i - 1];
    // chain of star forward
    for (int i = head[c]; i; i = t[i].nxt)
        if (t[i].to != f)
            dfs(t[i].to, c, w^t[i].w); // update child and father to next gen
}

int get(int a,int b){
    return col[a]^col[b];
}


int main()
{
    read(n);
    rep(i, 1, n - 1)
    {
        int a, b, c;
        read(a), read(b), read(c);
        addEdgeDbl(a, b, c);
    }
    rep(i, 1, n)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    dfs(1, 0, 0);
    read(m);
    rep(i, 1, m)
    {
        int a, b;
        read(a), read(b);
        printf("%d\n",get(a,b));
    }
    return 0;
}