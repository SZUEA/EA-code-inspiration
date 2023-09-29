/*
Trie

#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 1010;

struct trie
{
    int nex[5001][26], cnt;
    bool exist[5001]; 

    void insert(char *s, int l)
    { 
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; 
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    bool find(char *s, int l)
    { // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                return 0;
            p = nex[p][c];
        }
        return exist[p];
    }
};

int n, m, k;
void solve()
{
    cin >> n;
    trie *t = (trie *)malloc(sizeof(trie) * n);
    rep(i, 0, n - 1)
    {
        cin >> k;
        t[i].cnt = 0;
        rep(j, 0, k - 1)
        {
            char s[MAXN];
            cin >> s;
            t[i].insert(s, strlen(s));
        }
    }
    cin >> m;
    rep(i, 0, m - 1)
    {
        char s[MAXN];
        cin >> s;
        rep(j, 0, n - 1) if (t[j].find(s, strlen(s)))
                cout
            << j + 1 << " ";
        cout << endl;
    }
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    clock_t my_clock = clock();
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    cout << endl
         << "Time used " << clock() - my_clock << " ms." << endl;
#endif
    return 0;
}
*/
//STL

#include<iostream>
#include<map>
using namespace std;

int n,m;
map<string,bool> a[1009];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        for(int j=1;j<=num;j++)
        {
            string s;
            cin>>s;
            a[i][s]=1;
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
        {
            if(a[j][s]==1)
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}