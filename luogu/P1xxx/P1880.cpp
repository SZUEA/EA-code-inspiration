#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define N 500
using namespace std;

int n, p[N], s[N], f[N][N], f_[N][N];
int main()
{
    memset(f, 0x3f, sizeof(f));
    memset(f_, -0x3f, sizeof(f));
    cin >> n;
    rep(i, 1, n)
    {
        cin >> p[i];
        p[i+n]=p[i];
    }
    rep(i,1,2*n){
        s[i] = s[i - 1] + p[i];
        f_[i][i] = f[i][i] = 0;
    }
    rep(ln,2,n)rep(l,1,-ln+2*n){
        int r=l+ln-1;
        rep(k,l,r-1){
            f_[l][r]=max(f_[l][r],f_[l][k]+f_[k+1][r]+s[r]-s[l-1]);
            f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
        }
    }
    int minx=0xffffff,maxx=-0xffffff;
    rep(i,1,2*n){
        minx=min(minx,f[i][i+n-1]);
        maxx=max(maxx,f_[i][i+n-1]);
    }
    cout << minx << endl << maxx;
}