#include <bits/stdc++.h>
using namespace std;
int arr[110], n, dp[110], dp_[110], ans = -1;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    for (int i = n; i >= 1; i--)
    {
        dp_[i] = 1;
        for (int j = n; j > i; j--)
            if (arr[j] < arr[i])
                dp_[i] = max(dp_[i], dp_[j] + 1);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i] + dp_[i] - 1);
    printf("%d", n - ans);
    return 0;
}