#include<bits/stdc++.h>
using namespace std;int n,q,i,flag=1;main(){cin>>n;while(cin>>q&&((flag=!flag)||1))while(q--&&q>-1&&++i)cout<<flag<<(i%n?"":"\n");}