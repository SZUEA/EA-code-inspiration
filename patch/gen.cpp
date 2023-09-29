#include <bits/stdc++.h>
using namespace std;
#define rdi(a, b) rand() % (b - a + 1) + a
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define rep_r(i, s, t) for (int i = (s); i >= (t); i--)
#define endl '\n'

int main()
{

    srand((unsigned long long)(new char)+time(NULL));
    // int T = rdi(1, 20);
    // cout << T << endl;
    // while (T--)
    // {
    //     int n = rdi(1, 1000), h = rdi(1, 1000000000), r = rdi(1, 1000000000);
    //     cout << n << " " << h << " " << r << endl;
    //     while (n--)
    //         cout << rdi(0, 10) << " " << rdi(0, 10) << " " << rdi(0, h) << endl;
    //     cout << endl;
    // }
    // int x,n=rdi(1,1000000),c=rdi(1,1000);
    // cout<<n<<" "<<c<<endl;
    // for (int i = 1; i <= n; i++)
    //     cout<<rdi(1,n)<<" ";
    // cout<<endl;
    // for (int i = 1; i <= c; i++)
    // cout<<(rdi(0,1)?'A':'M')<<" "<<(x=rdi(1,n))<<" "<<rdi(x,n)<<" "<<rdi(1,10)<<endl;

    rep(i,1,5){
        cout<<(((int)(rdi(1,24)))|1)<<endl;
    }
    return 0;
}

void buildMap()
{
    set<pair<int, int>> S;
    int n = rand() % 1000 + 3, m = rand() % n + 1;
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++)
    {
        int x = (rand() * 10 + rand()) % 1000000;
        int y = (rand() * 10 + rand()) % 1000000;
        cout << x << " " << y << "\n";
    }
    for (int i = 0; i < m;)
    {
        int x = rand() % n + 1;
        int y = rand() % n + 1;
        if (!(S.count({x, y}) || S.count({y, x})) && x != y)
            cout << x << " " << y << "\n", i++, S.insert({x, y});
    }
}

void c()
{
    int n = rdi(1, 100);
    cout << n << "\n";
    while (n--)
    {
        int a = rdi(1, 10000);
        int n = rdi(1, 100);
        cout << a << " " << n << " ";
        vector<int> c;
        while (n--)
        {
            c.push_back(rdi(0, 1));
        }
        sort(c.begin(), c.end());
        for (auto &&i : c)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}