#include <bits/stdc++.h>

using namespace std;

//O(2/27 * (n A[i]^3))

const int sm=18;
const int maxi=3e5+5;
const int big=1e7;
const int me=40;
const int ms=821;

int lg[maxi],a[maxi],st[sm], p[maxi][sm], dp[me+1][ms],s[maxi],best[me+1][ms];
int n;

void calc()
{
    st[0]=1;
    lg[1]=0;
    for (int i=1;i<sm;i++)
    {
        st[i]=st[i-1]*2;
        lg[st[i]]=i;
    }

    for (int i=2;i<=maxi;i++)
        if (!lg[i]) lg[i]=lg[i-1];
}

void update_sparse()
{

    for (int i=1;i<sm;i++)
   for (int poz=0;poz<=n;poz++)
    if (s[p[poz][i-1]]<=s[p[poz+st[i-1]][i-1]])
     p[poz][i]=p[poz][i-1];  else
      p[poz][i]=p[poz+st[i-1]][i-1];


}

int get_min(int l, int r)
{
   int range=(r-l)+1;
   if (s[p[l][lg[range]]]<=s[p[r-st[lg[range]]+1][lg[range]]])
      return p[l][lg[range]]; else
       return p[r-st[lg[range]]+1][lg[range]];
}

int main()
{
   scanf("%d",&n);

   calc();

  p[0][0]=0;
  for (int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
    p[i][0]=i;
  }

  update_sparse();

  int ans=0;
  int am=0;
  int len=0;

  for (int i=1;i<=n;i++)
    if (a[i]>0)
     {
       dp[a[i]][a[i]]=i;
       for (int j=a[i]+1;j<=(a[i]*(a[i]+1))/2;j++)
        dp[a[i]][j]=best[a[i]-1][j-a[i]];

        for (int j=a[i];j<=(a[i]*(a[i]+1))/2;j++)
        for (int k=a[i];k<=me;k++)
            best[k][j]=max(best[k-1][j],dp[k][j]);

      int lef=0;
      for (int k=ms-1;k>=0;k--)
        if (best[me][k]>lef)
      {
          int idx=get_min(lef,best[me][k]-1);
          if (ans<s[i]-s[idx]-k)
          {
             ans=s[i]-s[idx]-k;
             am=1;
             len=i-idx+1;
          } else
          if (ans==s[i]-s[idx]-k && len>i-idx+1)
          {
             len=i-idx+1;
             am=1;
          }
          else
            if (ans==s[i]-s[idx]-k && len==i-idx+1)  am++;

          lef=best[me][k];
      }
    }
  if (ans==0) am=n;
  printf("%d %d\n",ans,am);

  return 0;
}
