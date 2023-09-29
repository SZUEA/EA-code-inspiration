#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define lowbit(a) (a & -a)
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

const int MAXN = 1e5 + 10;
int n;
set<string> st;

void dfs(queue<int> Q, string sTemp, stack<int> stk = stack<int>())
{
    if (!Q.empty())
    {
        if (stk.empty())
        {
            stk.push(Q.front());
            Q.pop();
            dfs(Q, sTemp, stk);
        }
        else
        {
            queue<int> op1_q = Q;
            stack<int> op1_s = stk;
            op1_s.push(op1_q.front());
            op1_q.pop();
            dfs(op1_q, sTemp, op1_s);
            sTemp += stk.top() + '0';
            stk.pop();
            dfs(Q, sTemp, stk);
        }
    }
    else if (!stk.empty())
    {
        sTemp += stk.top() + '0';
        stk.pop();
        dfs(Q, sTemp, stk);
    }
    else
        st.insert(sTemp);
}

void origin()
{
    rep(i, 1, 8)
    {
        st.clear();
        n = i;
        queue<int> Q;
        rep(j, 1, i) Q.push(j);
        dfs(Q, "");
        cout << st.size() << endl;
    }
}

int catlans[19] = {1, 1, 2, 5, 14, 42,
                   132, 429, 1430, 4862, 16796, 58786,
                   208012, 742900, 2674440, 9694845,
                   35357670, 129644790, 477638700};

void solve()
{
    cin>>n;
    cout<<catlans[n];
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