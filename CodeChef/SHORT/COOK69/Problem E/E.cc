#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const int N = 100100;

ll bitTwister(ll x, ll y){
  x ^= x >> 11;
  x ^= (x << 7) & 2636928640ll;
  x ^= (x << 15) & 4022730752ll;
  x ^= (x >> 18);
  return (1812433253ll * (x ^ (x >> 30)) + y) & 4294967295ll;
}

vector<int> g[N], h[N];
int tme, l[N], r[N];
int hgt[N];
int n, q;

ll a[N], val[2*N];;
map<pii, ll> res;


inline void dfs(int x, int ht){
	l[x] = ++tme;
	hgt[x] = ht;
	h[ht].pb(tme);
	val[tme] = a[x];
	foreach(it, g[x]) dfs(*it, ht+1);	
	r[x] = ++tme;
}

void init(){
	res.clear();
	
	sd2(n,q);
	for(int i = 1; i <= n; i++) g[i].clear(), h[i].clear();
	
	for(int i = 1; i <= n; i++) scanf("%lld", a+i);
	
	for(int i = 2; i <= n; i++){
		int p; sd(p);
		g[p].pb(i);
	}
	
	tme = 0;
	dfs(1, 1);
}

void solve(){
	init();
	
	while(q--){
		int v, d;
		sd2(v,d);
		d += hgt[v];
		
		int i = lower_bound(h[d].begin(), h[d].end(), l[v]) - h[d].begin();
		int j = upper_bound(h[d].begin(), h[d].end(), r[v]) - h[d].begin() - 1;
		if(res.count(mp(h[d][i], h[d][j]))){
			printf("%lld\n", res[mp(h[d][i], h[d][j])]);
		}
		else{
			ll x = val[h[d][i]];
			for(int k = i+1; k <= j; k++){
				x = bitTwister(x, val[h[d][k]]);
			}
			res[mp(h[d][i], h[d][j])] = x;
			printf("%lld\n", x);
		}
	}
	
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
