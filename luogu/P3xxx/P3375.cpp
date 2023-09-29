#include <bits/stdc++.h>
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

vector<int> kmp(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
vector<int> search(string text, string pattern)
{
    string cur = pattern + '#' + text;
    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> v;
    vector<int> lps = kmp(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++)
        if (lps[i] == sz2)
            v.push_back(i - 2 * sz2);
    return v;
}
string s1, s2;
void solve()
{
    cin >> s1 >> s2;
    for (auto &&i : search(s1, s2))
        cout << i + 1 << '\n';
    for (auto &&i : kmp(s2))
        cout << i << ' ';
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