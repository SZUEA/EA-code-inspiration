#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define N 500

int mp[N][N];
int m, p, x, y;
int dir[8][2] = {{1, 2}, {2, 1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, -1}, {-1, 2}};

struct node
{
    int x, y, step;
};

void bfs()
{
    memset(mp, 0x3f, sizeof(mp));
    mp[x][y] = 0;
    queue<node> q;
    q.push((node){x, y, 0});
    while (q.size())
    {
        int x_ = q.front().x, y_ = q.front().y, stp = q.front().step;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nxt_x = x_ + dir[i][0], nxt_y = y_ + dir[i][1];
            if (nxt_x <= p && nxt_x >= 1 && nxt_y >= 1 && nxt_y <= m && 1 + stp < mp[nxt_x][nxt_y])
            {
                mp[nxt_x][nxt_y] = 1 + stp;
                q.push((node){nxt_x, nxt_y, 1 + stp});
            }
        }
    }
    for (int i = 1; i <= p; i++, cout << endl)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] < 1e9)
                cout << mp[i][j] << "\t";
            else
                cout << -1 << "\t";
}
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    cin >> p >> m >> x >> y;
    bfs();
    return 0;
}