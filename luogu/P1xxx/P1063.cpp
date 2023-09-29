#include <bits/stdc++.h>
#define N 500
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
int ci()
{
    int x;
    scanf("%d", &x);
    return x;
}
using namespace std;
int n, p[N], s[N], f[N][N];

int main(){
    n=ci();
    rep(i,1,n){
        p[i]=ci();
        p[i+n]=p[i];
    }
    rep(ln,3,1+n)rep(l,1,-ln+2*n+1){
        int r=l+ln-1;
        rep(k,1+l,r-1)
            f[l][r]=max(f[l][r],f[l][k]+f[k][r]+p[l]*p[k]*p[r]);
    }
    int maxx=0;
    rep(i,1,n){
        maxx=max(maxx,f[i][i+n]);
    }
    printf("%d",maxx);
    return 0;
}