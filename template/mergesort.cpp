
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = 0;
int b[5000];
void mergeSort(vector<int> v, int r, int l = 0)
{
    int mid = (l + r) / 2;
    if (l == r)
    {
        return;
    }
    else
    {
        mergeSort(v, mid, l);
        mergeSort(v, r, mid + 1);
    }
    int i = l, j = mid + 1, t = l;
    while (i <= mid && j <= r)
    {
        if (v[i] > v[j])
        {
            ans += mid - i + 1;
            b[t++] = v[j];
            j++;
        }
        else
        {
            b[t++] = v[i];
            i++;
        }
    }
    while (i <= mid)
    {
        b[t++] = v[i];
        i++;
    }
    while (j <= r)
    {
        b[t++] = v[j];
        j++;
    }
    for (int i = l; i <= r; i++)
    {
        v[i] = b[i];
    }
    return;
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    mergeSort(v, n-1);
    cout << ans;
    return 0;
}