#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN=100;
const int INF=0x3f3f3f3f;
struct Node{int x,y,stp;};
int mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int it=1,jt,ans;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
queue<Node> Q;

void bfs(){
    Q.push({1,1,0}),mp[1][1]=0,vis[1][1]=1;
    while (!Q.empty()) {
    Node node=Q.front();Q.pop();
    int x=node.x,y=node.y;for (auto &&d : dir)
    if(mp[x+d[0]][y+d[1]]&&!vis[x+d[0]][y+d[1]]
    &&x+d[0]<=it&&x+d[0]>=1&&y+d[1]<=jt&&y+d[1]>=1)
    {Q.push({x+d[0],y+d[1],node.stp+1});vis[x+d[0]][y+d[1]]=1;
    mp[x+d[0]][y+d[1]]=min(node.stp+1,mp[x+d[0]][y+d[1]]);}}
}

int path_finder(string s)
{
    for (auto &&i : s)
        if(i=='.')mp[it][++jt]=INF;
        else if(i=='W')mp[it][++jt]=0;
        else if(i=='\n')it++,jt=0;
    bfs();
    rep(i,1,it){rep(j,1,jt)cout<<mp[i][j]<<" ";cout<<endl;}
    return mp[it][jt]==INF?-1:mp[it][jt];
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    clock_t my_clock = clock();
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    //cout<<path_finder("....W..W.\nWW...W...\n..W.WWW..\nWW....W..\n....W....\n..W...WW.\n.....WWW.\n..W......\n....W....\n....W..W.\nWW...W...\n..W.WWW..\nWW....W..\n....W....\n..W...WW.\n.....WWW.\n..W......\n....W....");
    cout<<path_finder("......\n......\n......\n......\n......\n......");
#ifndef ONLINE_JUDGE
    cout << endl
         << "Time used " << clock() - my_clock << " ms." << endl;
#endif
    return 0;
}