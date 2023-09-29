//P2801 教主的魔法
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,blo;
int v[1000005],bl[1000005],atag[1000005];
vector<int>ve[10001];
void reset(int x)                       //排序操作 
{
    ve[x].clear();                      //先初始化 
    for(int i=(x-1)*blo+1;i<=min(x*blo,n);i++)
        ve[x].push_back(v[i]);          //将整个块的数值重新压进vector里 
    sort(ve[x].begin(),ve[x].end());    //块内排序 
}
ll read()                               //快读 
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void add(int a,int b,int c)             //修改操作 
{
    for(int i=a;i<=min(bl[a]*blo,b);i++) v[i]+=c;   //零散操作 
    reset(bl[a]);                       //重新块内排序 
    if(bl[a]!=bl[b])                    
    {
        for(int i=(bl[b]-1)*blo+1;i<=b;i++) v[i]+=c;//零散操作 
        reset(bl[b]);                   //重新块内排序 
    }
    for(int i=bl[a]+1;i<=bl[b]-1;i++)   
        atag[i]+=c;
}
int query(int a,int b,int c)            //查询操作 
{
    int ans=0;//排名 
    for(int i=a;i<=min(bl[a]*blo,b);i++)//零散暴力查询 
    {
        if(v[i]+atag[bl[a]]<c)
        ans++;
    }
    if(bl[a]!=bl[b])
    {
        for(int i=(bl[b]-1)*blo+1;i<=b;i++)         //零散暴力查询 
        {
            if(v[i]+atag[bl[b]]<c)
            ans++;
        }
    }
    for(int i=bl[a]+1;i<=bl[b]-1;i++)   //整块查询 
    {
        int x=c-atag[i];                //注意：这里要先剪去这个块的atag，因为这整个块的所以数值都应该加了atag，所以我们二分找的数也要先剪atag 
        ans+=lower_bound(ve[i].begin(),ve[i].end(),x)-ve[i].begin();    //注意：这里lower_bound操作返回的是地址，所以要想知道块内排名，要减块头的地址 
    }   //不会用lower_bound可以直接写二分 
    return ans;
}
int main()
{
    n=read();m=read();blo=sqrt(n);
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1;i<=n;i++)bl[i]=(i-1)/blo+1,ve[bl[i]].push_back(v[i]);   //初始化ve[i]数组 
    for(int i=1;i<=bl[n];i++)
    sort(ve[i].begin(),ve[i].end());    //排序
    for(int i=1;i<=m;i++)
    {
    	char f;cin>>f;
        int a=read(),b=read(),c=read();
        if(f=='M')add(a,b,c);
        if(f=='A')printf("%d\n",b-a+1-query(a,b,c));
    }
    return 0;
}