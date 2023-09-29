#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define rep(i, s, t) for (register int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (register int i = (s); i >= (t); i--)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
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

const int MAXN = 1e6 + 10;
char c, op;
int n, m, arr[MAXN];
int lazy_add[MAXN], position[MAXN];
int end_i;
int L, R, v;
int x, y, ans;
vector<int> store[(int)1e4 + 10];
void solve()
{
    cin >> n >> m;
    end_i = sqrt(n); // 块的终止位置基数
    rep(i, 1, n) cin >> arr[i];
    rep(i, 1, n)
    {
        position[i] = (i - 1) / end_i + 1;
        store[position[i]].pb(arr[i]);
    }
    rep(i, 1, position[n]) // 区块排序
        sort(store[i].begin(), store[i].end());
    while (m--)
    {
        cin >> op >> L >> R >> v;
        x = position[L], y = position[R];
        if (op == 'M')
        {
            rep(i, L, min(R, x * end_i)) arr[i] += v; // 区块加和
            store[x].clear();
            rep(i, (x - 1) * end_i + 1, min(x * end_i, n)) store[x].pb(arr[i]);
            sort(store[x].begin(), store[x].end());
            if (x != y)
            {
                rep(i, (y - 1) * end_i + 1, R) arr[i] += v;
                store[y].clear();
                rep(i, (y - 1) * end_i + 1, min(y * end_i, n)) store[y].pb(arr[i]);
                sort(store[y].begin(), store[y].end());
            }
            rep(i, x + 1, y - 1) lazy_add[i] += v;
        }
        else
        {
            ans = 0;
            rep(i, L, min(R, x * end_i)) ans += (arr[i] + lazy_add[x] < v); // 统计并下落lazy             // 区块加和
            if (x != y)
                rep(i, (y - 1) * end_i + 1, R) ans += (arr[i] + lazy_add[y] < v);
            rep(i, x + 1, y - 1)
                // 二分查找有多少个比v小的数，这是由于sorted已是有序列
                ans += lower_bound(store[i].begin(), store[i].end(), v - lazy_add[i]) - store[i].begin();
            cout << R - L + 1 - ans << endl;
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


/*
错误代码: WA * 4

hack:
3 1
3 1 2 
A 3 3 2

正确:
1
本代码:
0


#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2, M = 1e3 + 2;
char c, op;
int n, Q, a[N], b[N], st[M], en[M], add[N], pos[N];
int x, s, t, l, r, W, p, q, w, ans, f;
inline int readin()
{
	x = 0;
	c = getchar();
	while (!(c >= '0' && c <= '9'))
		c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + c - '0', c = getchar();
	return x;
}
inline char readch()
{
	c = getchar();
	while (!(c >= 'A' && c <= 'Z'))
		c = getchar();
	return c;
}
int main()
{
	n = readin();
	Q = readin();
	t = sqrt(n);
	s == ceil(1.0*n/t);
	for (int i = 1; i <= n; i++)
		a[i] = readin(), b[i] = a[i];
	for (int i = 1; i <= s; i++)
		st[i] = t * (i - 1) + 1, en[i] = min(n, t * i);
	for (int i = 1; i <= n; i++)
		pos[i] = (i - 1) / t + 1;
	for (int i = 1; i <= s; i++)
		sort(b + st[i], b + en[i] + 1);
	while (Q--)
	{
		op = readch(), l = readin(), r = readin(), W = readin();
		if (op == 'M')
		{
			p = pos[l], q = pos[r];
			for (int i = l; i <= min(r, en[p]); i++)
				a[i] += W;
			for (int i = st[p]; i <= en[p]; i++)
				b[i] = a[i];
			sort(b + st[p], b + en[p] + 1);
			if (p == q)
				continue;
			for (int i = st[q]; i <= r; i++)
				a[i] += W;
			for (int i = st[q]; i <= en[q]; i++)
				b[i] = a[i];
			sort(b + st[q], b + en[q] + 1);
			p++, q--;
			for (int i = p; i <= q; i++)
				add[i] += W;
		}
		else
		{
			p = pos[l], q = pos[r], ans = 0;
			for (int i = l; i <= min(r, en[p]); i++)
				ans += (a[i] + add[p] >= W);
			if (p == q)
			{
				printf("%d\n", ans);
				continue;
			}
			for (int i = st[q]; i <= r; i++)
				ans += (a[i] + add[q] >= W);
			p++, q--;
			for (int i = p; i <= q; i++)
				f = lower_bound(b + st[i], b + en[i] + 1, W - add[i]) - b,
				ans += ((f != en[i] + 1) ? (en[i] - f + 1) : 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}
*/