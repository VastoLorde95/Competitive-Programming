#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,itit )  for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back

inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
const int mod = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

//#define DEBUG

#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

int a[N];
vector<int>arr,G[N];
map<int,int> M,M1;
int main(){
  int n;
  scanf("%d",&n);
  REP(i,n){
    scanf("%d",&a[i]); arr.pb(a[i]);
  }
  sort(arr.begin(),arr.end());
  arr.resize(unique(arr.begin(),arr.end())-arr.begin());
  int x=-1,ans=0;
//  sort(arr,arr+n);
  REP(i,n){
    a[i]=lower_bound(arr.begin(),arr.end(),a[i])-arr.begin();
  }
  arr.clear();
  REP(i,n) {
    arr.pb(a[i]);
  }
  sort(arr.begin(),arr.end());
  for(int i=n-1;i>=0;i--){
    G[arr[i]].pb(i);
//    printf("%d\n",a[i]);
  }
  REP(i,n){
    int y=G[a[i]][G[a[i]].size()-1];
    G[a[i]].pop_back();
  //  printf("z%d\n",y);
    x=max(x,y);

    if(x==i) ans++;
  }
  printf("%d\n",ans);
  return 0;
}
