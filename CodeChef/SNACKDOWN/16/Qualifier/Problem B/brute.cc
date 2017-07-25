#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const long double PI = 3.1415926535897932384626433832795;

const int N = 100100;
const ll INF = (1ll << 60);

int n;
int a[N];
ll dp[N];

void solve(){
	sd(n);
	
	bool all_neg = true;
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if(a[i] > 0) all_neg = false;
	}
	
	ll ans = -INF;
	
	if(all_neg){
		for(int i = 1; i <= n; i++){
			ans = max(ans, 1ll*a[i]);
		}
		printf("%lld\n", ans);
		return;
	}
	
	for(int i = 1; i <= n; i++){
		ll sum = 0, mn = 0;
		for(int j = i; j <= n; j++){
			sum += a[j];
			mn = min(mn, 1ll*a[j]);
			ans = max(ans, sum - mn);
		}
	}
	
	printf("%lld\n", ans);
	
}

int main(){
	int t; sd(t);
	while(t--) solve();
	return 0;
}
