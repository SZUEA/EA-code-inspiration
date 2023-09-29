#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int deg[N] = {0};
vector<set<int>> tree;
int main()
{
    tree.push_back(set<int>());
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        set<int> unit;
        while (cin >> t)
            if (t)
            {
                unit.insert(t);
                deg[t]++;
            }
            else
                break;

        tree.push_back(unit);
    }
    for (int j = 1; j <= n; j++)
    {
        queue<int> Q;
        for (int i = 1; i <= n; i++)
            if (!deg[i])
                Q.push(i);
        if (!Q.size())
            break;
        while (Q.size())
        {
            int c = Q.front();
            printf("%d ", c);
            Q.pop();
            deg[c] = -1;
            for (auto &p : tree[c])
                deg[p]--;
        }
    }
    return 0;
}