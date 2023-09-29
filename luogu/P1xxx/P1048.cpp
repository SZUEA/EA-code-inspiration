#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int num, lim;
int t[N], v[N], f[N];
int main()
{
    cin >> lim >> num;
    for (int i = 1; i <= num; i++)
        cin >> t[i] >> v[i];
    for (int i = 1; i <= num; i++)
        for (int j = lim; j >= t[i]; j--)
            f[j] = max(f[j], f[j - t[i]] + v[i]);
    cout << f[lim];
    return 0;
}