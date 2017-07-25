#include <bits/stdc++.h>
#define s(x) scanf("%d",&x)
int n,p,a[1<<20],u=1,d=1;long long dp[1<<20];int main(){s(n);for(int i=0;i<n;i++)s(a[i]);for(int i=1;i<n;i++){if(a[i]==a[i-1])u=1,d=1,p=i-1;if(u&&a[i-1]>a[i])d=1,u=0,p=i-1;if(d&&a[i-1]<a[i])d=0,u=1,p=i-1;dp[i+1]=std::max(dp[p]+abs(a[i]-a[p]),dp[p+1]+abs(a[i]-a[p+1]));}printf("%I64d",dp[n]);return 0;}
