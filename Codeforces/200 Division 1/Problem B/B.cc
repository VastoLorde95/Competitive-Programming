#include<bits/stdc++.h>
using namespace std;string s;int n;stack<char> q;int main(){cin>>s;n=s.length();for(int i=0;i<n;i++)if(!q.empty() and q.top()==s[i])q.pop();else q.push(s[i]); if(!q.empty())puts("No");else puts("Yes"); return 0;}
