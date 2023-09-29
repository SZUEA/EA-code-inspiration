//
//过不了题QAQ
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 0x27100;
// #define rep(i, s, t) for (int i = (s); i <= (t); i++)
// #define IOS                  \
//     ios::sync_with_stdio(0); \
//     cin.tie(0), cout.tie(0);

// const int sL = 'a', sR = 'z';
// struct node
// {
//     struct nxt
//     {
//         node *ch[sR - sL + 1];
//         node *&operator[](int x)
//         {
//             return ch[x - sL];
//         }
//     } children;
//     int cou = -1;
// } nodes[N];
// int tot = 0;
// node *insert(int n, char *str)
// {
//     node *e = nodes;
//     rep(i, 0, n - 1)
//     {
//         if (e->children[str[i]] == 0)
//             e->children[str[i]] = &nodes[++tot];
//         e = e->children[str[i]];
//     }
//     e->cou = 0;
//     return e;
// }

// int query(int n, char *str)
// {
//     node *e = nodes;
//     rep(i, 0, n - 1)
//     {
//         if (e->children[str[i]] == 0)
//             return -1;
//         e = e->children[str[i]];
//     }
//     if (e->cou == -1)
//         return -1;
//     else if (e->cou)
//         return 1;
//     else
//         return (e->cou)++;
// }

// int main()
// {
//     IOS;
// #ifndef ONLINE_JUDGE
//     clock_t my_clock = clock();
//     freopen("1.in", "r", stdin);
//     freopen("1.out", "w", stdout);
// #endif
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         char *a;
//         cin >> a;
//         insert(strlen(a), a);
//     }
//     int m;
//     cin >> m;
//     while (m--)
//     {
//         char *q;
//         cin >> q;
//         switch (query(strlen(q), q))
//         {
//         case 1:
//             cout << "REPEAT\n";
//             break;
//         case 0:
//             cout << "OK\n";
//             break;
//         default:
//             cout << "WRONG\n";
//         }
//     }

// #ifndef ONLINE_JUDGE
//     cout << endl
//          << "Time used " << clock() - my_clock << " ms." << endl;
// #endif
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
map<string, int> mp;
int n, m;
string s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n;
    while (n--)
    {
        cin >> s;
        mp[s] = 1;
    }
    cin >> m;
    while (m--)
    {
        cin >> s;
        switch (mp[s])
        {
        case 0:
            cout << "ERROR\n";
            break;
        case 1:
            cout << "OK\n";
            mp[s] = 2;
            break;
        default:
            cout << "REPEAT\n";
            break;
        }
    }

    return 0;
}
