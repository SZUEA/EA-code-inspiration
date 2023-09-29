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

const int MAXN = 110;

int n, m, p, a, b, c;
priority_queue<int, vector<int>, greater<int>> heap;
void solve()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a >> b >> c;
        rep(j, 1, 120) heap.push(j * j * a + j * b + c);
    }
    rep(i, 1, m) cout << heap.top() << ' ', heap.pop();
}

void CorrectSolution()
{
    priority_queue<int> q;
    int ans[MAXN];
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a >> b >> c;
        rep(j, 1, m)
        {
            int k;
            k = a * j * j + b * j + c;
            if (i == 1)
                q.push(k);
            else
            {
                if (k < q.top())
                {
                    q.push(k);
                    q.pop();
                }
                else
                    break;
                // 如果k已经大于第m小的数了，接下来k仍旧单调递增
                // 所以可以直接break掉，一个重要的优化
            }
        }
    }
    rep(i,1,m)
    {
        ans[i] = q.top();
        q.pop();
    } 
    rep_r(i,m,1) printf("%d ", ans[i]);
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