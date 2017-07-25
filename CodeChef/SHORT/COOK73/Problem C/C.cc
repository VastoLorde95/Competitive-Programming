#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=4e5+10;
const int mxl=20;
const uli mod=1e9+7;
uli fa[mx],fi[mx];
int maxi[mxl][mx];
int mini[mxl][mx];
uli cmb(int n,int k){ return fa[n]*fi[k]%mod*fi[n-k]%mod; }
uli fxp(uli b,uli x){
   uli a=1;
   for(;x!=0;b=b*b%mod,x>>=1)
      if(x&1ll)a=a*b%mod;   
   return a;
}
int qmax(int l,int r){
   int len=32-__builtin_clz(r-l+1)-1;
   return max(maxi[len][l],maxi[len][r-(1<<len)+1]);
}
int qmin(int l,int r){
   int len=32-__builtin_clz(r-l+1)-1;
   return min(mini[len][l],mini[len][r-(1<<len)+1]);
}
int main(){
//   freopen("secret/4.in","r",stdin);
//   freopen("secret/4.out","w",stdout);
   fa[0]=fi[0]=1;
   for(int i=1;i<mx;i++){
      fa[i]=fa[i-1]*uli(i)%mod;
      fi[i]=fxp(fa[i],mod-2);
   }
   int n,t,l,r;
   scanf("%d %d",&n,&t);
   assert(1<=t && t<=1e5);
   for(int i=0;i<n;i++){
      scanf("%d",&maxi[0][i]);
      assert(maxi[0][i]%2==0);
      assert(0<=maxi[0][i] && maxi[0][i]<=2e5);
   }
   for(int i=0;i<n;i++){
      scanf("%d",&mini[0][i]);
      assert(0<=mini[0][i] && mini[0][i]<=2e5);
   }
   for(int l=1;l<mxl;l++){
      for(int i=0;i<n;i++){
         maxi[l][i]=maxi[l-1][i];
         mini[l][i]=mini[l-1][i];
         int j=i+(1<<(l-1));
         if(j<n){
            maxi[l][i]=max(maxi[l-1][i],maxi[l-1][j]);
            mini[l][i]=min(mini[l-1][i],mini[l-1][j]);
         }
      }
   }
   while(t--){
      scanf("%d %d",&l,&r);
      assert(1<=l && l<=n && l<=r && r<=n );
      --l,--r;
      int x=qmax(l,r)/2;
      int y=qmin(l,r);
      if(y>x){
         puts("0");
         continue;
      }
      --y;
      uli ans=cmb(x+x-y-2,x-y-1)*uli(y+1)%mod*fxp(x,mod-2)%mod;
      printf("%lld\n",ans);
   }
   return 0;
}
