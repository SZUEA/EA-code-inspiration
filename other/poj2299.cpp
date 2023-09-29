#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#include <functional>
#include <numeric>
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
ll ans = 0;
int b[MAXN];

vector<int> v;

void mergeSort(int r, int l = 0)
{
    int mid = (l + r) / 2;
    if (l == r)
    {
        return;
    }
    else
    {
        mergeSort(mid, l);
        mergeSort(r, mid + 1);
    }
    int i = l, j = mid + 1, t = l;
    while (i <= mid && j <= r)
    {
        if (v[i] > v[j])
        {
            ans += mid - i + 1;
            b[t++] = v[j];
            j++;
        }
        else
        {
            b[t++] = v[i];
            i++;
        }
    }
    while (i <= mid)
    {
        b[t++] = v[i];
        i++;
    }
    while (j <= r)
    {
        b[t++] = v[j];
        j++;
    }
    for (int i = l; i <= r; i++)
    {
        v[i] = b[i];
    }
    return;
}

int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    clock_t my_clock = clock();
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n && n)
    {
        ans = 0, v.clear();
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        mergeSort(n - 1);
        cout << ans << endl;
    }
#ifndef ONLINE_JUDGE
    cout << "Time used: " << (double)(clock() - my_clock) / CLOCKS_PER_SEC << "s" << endl;
#endif
    return 0;
}