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

const int MAXN = 1e7+10;
int vis[MAXN], prime[MAXN], phi[MAXN], tot = 0;

void gtPri(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      prime[++tot] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= tot; j++) {
      if (i * prime[j] > n) break;
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
}

int n;
ll sum[MAXN],  ans;
void solve()
{
    cin>>n;
    gtPri(n);
    rep(i,1,n) sum[i]=sum[i-1]+phi[i];
    rep(i,1,tot) if(prime[i]<=n) ans+=(sum[n/prime[i]]<<1)-1;
    cout<<ans<<endl;
}

int main()
{
    IOS;
    solve();
    return 0;
}