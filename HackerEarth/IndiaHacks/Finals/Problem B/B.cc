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

const int N = 300100;

int n, m, k;
vector<int> g[N];
int v[N];

void bad(){
	puts("impossible");
	exit(0);
}

void good(){
	puts("possible");
	exit(0);
}

int main(){
	sd3(n,m,k);
	
	for(int i = 1; i <= m; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);		
	}
	
	if(n - 1 - (int) g[1].size() < k){
		bad();
	}
	
	map<pair<ll, int>, ll> h;
	
	const ll p = 123571113171923ll;
	const ll base = 31;
	
	for(int i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end());

		
		
		ll val = 0, x;
		foreach(it, g[i]){
			x = *it;
			val = (x + (val * base)%p)%p;
		}
		
		h[mp(val, g[i].size())]++;
	}
	
	foreach(it, h){
		if(it->fi.se > 0 and it->se == n - it->fi.se){
			bad();
		}
	}
	
	// now check if we can make a graph such that node 1 has degree exactly k

	int oye = 0;
	for(int i = 2; i <= n; i++){
		if((int) g[i].size() == n-2 and g[i].size() > 0 and g[i][0] != 1) oye++;
	}
	
	if(oye > k) bad();
	if(oye == k){
		if(k != n-1){
			bad();
		}
	}
		
	good();
	
	return 0;
}
