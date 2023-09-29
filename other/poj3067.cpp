

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
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

const int MAXN = 500010;
int b[MAXN];
ll ans = 0;

struct ref
{
    int a, b;
} rt[MAXN];

vector<int> v;

void mergeSort(int r, int l = 0)
{
    int mid = (l + r) / 2;
    if (l == r)
        return;
    else
        mergeSort(mid, l), mergeSort(r, mid + 1);
    int i = l, j = mid + 1, t = l;
    while (i <= mid && j <= r)
    {
        if (rt[i].b > rt[j].b)
        {
            ans += mid - i + 1;
            b[t++] = rt[j].b;
            j++;
        }
        else
            b[t++] = rt[i].b, i++;
    }
    while (i <= mid)
        b[t++] = rt[i].b, i++;
    while (j <= r)
        b[t++] = rt[j].b, j++;
    for (int i = l; i <= r; i++)
        rt[i].b = b[i];
    return;
}

int n, m, k;

int cmp(ref a, ref b)
             {
            if (a.a!=b.a)
                return a.a<b.a;
            return a.b<b.b; }

void solve()
{
    caseT
    {
        cin >> n >> m >> k;
        rep(i, 1, k)
        {
            int a, b;
            cin >> a >> b;
            rt[i].a=a;
            rt[i].b=b;
        }
        sort(rt + 1, rt + k + 1, cmp);
        mergeSort(k);
        cout << "Test case " << T + 1 << ": " << ans << endl;
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
    cout << "Time used: " << (double)(clock() - my_clock) << "ms" << endl;
#endif
    return 0;
}

