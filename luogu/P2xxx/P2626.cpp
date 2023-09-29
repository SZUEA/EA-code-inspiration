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

const int MAXN = 110;
ll a[MAXN];
string arr[]={"1=1","1=1","2=2","3=3","5=5","8=2*2*2","13=13","21=3*7","34=2*17","55=5*11","89=89","144=2*2*2*2*3*3","233=233","377=13*29","610=2*5*61","987=3*7*47","1597=1597","2584=2*2*2*17*19","4181=37*113","6765=3*5*11*41","10946=2*13*421","17711=89*199","28657=28657","46368=2*2*2*2*2*3*3*7*23","75025=5*5*3001","121393=233*521","196418=2*17*53*109","317811=3*13*29*281","514229=514229","832040=2*2*2*5*11*31*61","1346269=557*2417","2178309=3*7*47*2207","3524578=2*89*19801","5702887=1597*3571","9227465=5*13*141961","14930352=2*2*2*2*3*3*3*17*19*107","24157817=73*149*2221","39088169=37*113*9349","63245986=2*233*135721","102334155=3*5*7*11*41*2161","165580141=2789*59369","267914296=2*2*2*13*29*211*421","433494437=433494437","701408733=3*43*89*199*307","1134903170=2*5*17*61*109441","1836311903=139*461*28657","823731425=5*5*11*83*151*239","512559680=2*2*2*2*2*2*5*1601749","1336291105=5*101*113*23417","1848850785=3*3*3*5*13695191"};
int k;

void divide(int num)
{
    int flag = 1, rt = sqrt(num);
    cout<<"\""<<num<<"=";
    for (int i = 2; i <= rt; i++)
        while (!(num % i))
        {
            if (num / i == 1)
            {
                cout<<i<<"\",";
                return;
            }
            cout<<i<<"*";
            num /= i;
        }
    cout<<num<<"\",";
}

void solve()
{
    //a[1]=1,a[2]=1;
    //rep(i,3,50)a[i]=a[i-1]+a[i-2];
    // rep(i,1,50)cout<<a[i]%(1<<31)<<"\n";
    //rep(i,1,50)divide(a[i]%(1<<31));
    cin>>k;
    cout<<arr[k-1]<<endl;
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