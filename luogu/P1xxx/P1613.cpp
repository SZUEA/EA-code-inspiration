
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
const int N = 60;
int n,m,x,y;
int f[N][N][66],mn[N][N];//unit all into 0
int main(){
    read(n),read(m);
    rep(i,1,n)rep(j,1,n)mn[i][j]=65;
    rep(i,1,m){
        read(x),read(y);
        f[x][y][0]=1,mn[x][y]=1;//get line available
    }
    rep(p,1,64)//find range in maxlong int
    rep(i,1,n)//left index iterator
    rep(j,1,n)//middle index iterator
    rep(k,1,n)//right index iterator
    if (f[i][j][p-1]&&f[j][k][p-1])//two line of 2^p distance exists?
    f[i][k][p]=1,mn[i][k]=1;//if so, put 1 to make it available
    rep(j,1,n)
    rep(i,1,n)
    rep(k,1,n)
    mn[i][k]=std::min(mn[i][k],mn[i][j]+mn[j][k]);//dfs to make the ans
    printf("%d",mn[1][n]);
    return 0;
}
