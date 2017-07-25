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

const long double PI = 3.1415926535897932384626433832795;

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

const int N = 50100;
const int ROOT = 400;

int n, m;
vector<int> g[N];
int good[N];

int reachable[N];

unordered_map<ll, ll> h;

int main(){
	sd2(n,m);
	
	for(int i = 0; i < m; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}	

	ll ans = 0;
	
	for(int i = 1; i <= n; i++){
		if(g[i].size() <= ROOT){
			good[i] = 1;
			continue;
		}
		
		foreach(it, g[i]) reachable[*it] = 1;
		
		ll cnt;
		for(int j = 1; j <= n; j++){
			if(!good[j]) continue;
			
			cnt = 0;
			foreach(it, g[j]) cnt += reachable[*it];
			
			ans += (cnt * (cnt-1)) / 2;
		}
		
		foreach(it, g[i]) reachable[*it] = 0;
	}
	
	for(int i = 1; i <= n; i++){
		if(!good[i]) continue;
		
		sort(g[i].begin(), g[i].end());
		
		vector<int> v;
		foreach(it, g[i]) if(good[*it]) v.pb(*it);
		
		int d = v.size();
		ll base;
		for(int j = 0; j < d; j++){
			base = 100000ll * v[j];
			for(int k = j+1; k < d; k++){
				ans += h[base +  v[k]]++;
			}
		}
	}
	
	printf("%lld\n", ans/2);


	return 0;
}
