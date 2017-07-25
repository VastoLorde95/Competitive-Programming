

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010;
int n,a[N],ans;
map<int,int> cnt,pt;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),cnt[a[i]]++;
	rep(i,0,n) rep(j,0,n) if (i!=j) {
		if (a[i]==0&&a[j]==0) ans=max(ans,cnt[0]);
		pt.clear();
		pt[a[i]]++; pt[a[j]]++;
		int x=a[i],y=a[j],l=2;
		while (1) {
			x+=y; swap(x,y);
			auto it=cnt.find(y);
			if (it==cnt.end()) break;
			if (pt[y]<it->se) {
				pt[y]++;
				l++;
			} else break;
		}
		ans=max(ans,l);
	}
	printf("%d\n",ans);
}
