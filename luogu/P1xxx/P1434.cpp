#include <bits/stdc++.h>
#define min(a, b) a < b ? a : b
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rev_rep(i, s, t) for (int i = (s); i >= (t); i--)
#define N 100
using ll = long long;
using namespace std;
int ci()
{
    int x;
    scanf("%d", &x);
    return x;
}

int r, c, ans = 0;
int arr[N][N], vis[N][N], f[N][N];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

/*
int r, c, ans = 0;
int arr[N][N], maxx[N][N];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct node
{
    int x, y, stp;
};
void bfs()
{
    r = ci(), c = ci();
    rep(i, 1, r) rep(j, 1, c) arr[i][j] = ci();
    queue<node> Q;
    rep(i, 1, r) rep(j, 1, c)
    {
        memset(maxx, -1, sizeof(maxx));
        Q.push((node){i, j, 0});
        maxx[i][j] = 0;
        while (!Q.empty())
        {
            int x = Q.front().x;
            int y = Q.front().y;
            int _stp = Q.front().stp + 1;
            Q.pop();
            for (auto &&k : dir)
            {
                int _x = x + k[0];
                int _y = y + k[1];
                if (_stp < maxx[_x][_y] || arr[x][y] < arr[_x][_y] || _x < 1 || _y < 1 || _x > r || _y > c)
                    continue;
                Q.push((node){_x, _y, _stp});
                ans = max(ans, _stp);
            }
        }
    }
    cout << ans + 1;
}
*/
int dfs(int x,int y){
    if(vis[x][y]) return f[x][y];
    vis[x][y]=1;
    for (auto &&i : dir)
    {
        int _x=x+i[0],_y=y+i[1];
        if(_x>0&&_y>0&&_x<=r&&_y<=c&&arr[x][y]>arr[_x][_y]){
            f[x][y]=max(f[x][y],dfs(_x,_y)+1);
        }
    }
    return f[x][y];
}
int main()
{
    r = ci(), c = ci();
    rep(i, 1, r) rep(j, 1, c) arr[i][j] = ci();
    rep(i, 1, r) rep(j, 1, c) f[i][j]=1;
    rep(i, 1, r) rep(j, 1, c) ans=max(ans,dfs(i,j));
    cout<<ans;
    return 0;
}