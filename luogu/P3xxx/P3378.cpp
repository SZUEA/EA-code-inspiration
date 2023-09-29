#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
int ci()
{
    int x;
    scanf("%d", &x);
    return x;
}
//std::set<int> heap;
std::priority_queue<int,std::vector<int>,std::greater<int>> pr;
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int n = ci();
    rep(i, 1, n)
    {
        switch (ci())
        {
        case 1:
            pr.push(ci());
            continue;
        case 2:
            printf("%d\n", pr.top());
            continue;
        default:
            pr.pop();
        }
    }
    return 0;
}