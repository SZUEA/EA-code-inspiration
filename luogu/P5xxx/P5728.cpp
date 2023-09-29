#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#define caseT \
    int T;    \
    cin >> T; \
    while (T--)

const int MAXN = 1010;
struct Student
{
    int c, m, e, a;
} stu[MAXN];
int n, tot;
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> stu[i].c >> stu[i].m >> stu[i].e, stu[i].a = stu[i].c + stu[i].m + stu[i].e;
    rep(i, 1, n) rep(j, i + 1, n) if (abs(stu[i].a - stu[j].a) <= 10 && abs(stu[i].c - stu[j].c) <= 5 && abs(stu[i].m - stu[j].m) <= 5 && abs(stu[i].e - stu[j].e) <= 5) tot++;
    cout << tot;
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