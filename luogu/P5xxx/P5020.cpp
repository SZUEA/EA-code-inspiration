#include <bits/stdc++.h>
#define N 500
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
inline void print(int x)
{
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
using namespace std;

int n, xs[N], f[N];//, ac[N];
int main()
{
    //memset(ac, 1, sizeof(ac));
    read(n);
    while (n--)
    {
        int x, ans = 0,mx=ans;
        read(x);
        memset(f, 0, sizeof(f));
        rep(i, 1, x) {read(xs[i]);mx=max(xs[i],mx);}
        sort(xs + 1, xs + x + 1);
        rep(i,1,x){
             /*20分  似乎没问题？
             memset(f, 0, sizeof(f));
             for (int j = 1; j < i; j++)
             {
                 if(!ac[j])continue;
                 for (int l = xs[j]; l <= xs[i]; l++)
                     if (f[l - xs[j]] + xs[j] > f[l])
                         f[l] = f[l - xs[j]] + xs[j];
             }
             if (f[xs[i]] == xs[i]){
                 ac[i] = 0;
                 ans++;
             }
         */
        if(f[xs[i]])continue;
        f[xs[i]]++;
        ans++;
        rep(j,xs[i],mx)
            if(f[j-xs[i]])f[j]=1;
        
        }
        
        cout << ans << endl;
    }
    return 0;
}