#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
using namespace std;
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 110;
char str[MAXN];
stack<int> s;
void solve()
{
    cin>>str;
    int len = strlen(str);
    int ans = 0;
    rep(i,0,len-1){
        int nm = 0;
        while(str[i]>='0'&&str[i]<='9'){
            nm = nm*10+str[i]-'0';
            i++;
        }
        if(str[i]=='.')s.push(nm);
        if(str[i]=='+'||str[i]=='-'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(str[i]=='+')s.push(a+b);
            else s.push(b-a);
        }else if(str[i]=='*'||str[i]=='/'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(str[i]=='*')s.push(a*b);
            else s.push(b/a);
        }else if(str[i]=='@'){
            ans = s.top();
            s.pop();
            cout<<ans<<endl;
        }
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