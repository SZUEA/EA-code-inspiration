#include <bits/stdc++.h>

using namespace std;

int a, p, k, T;

class Math
{
public:
    Math();
    static long long qpow(int a, int k, int p);
};

long long Math::qpow(int a, int k, int p)
{
    long long ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return ans % p;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> k >> p;
        cout << Math::qpow(10, 10, 100) << "\n";
    }
}