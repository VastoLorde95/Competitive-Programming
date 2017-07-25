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

int n;
vector<int> g[N];
int c[N];
map<int, int> col;

ll dfs(int cur, int prev){
	col[c[cur]]++;
	
	ll ret = col.size();
	
	foreach(it, g[cur]){
		if(*it == prev) continue;		
		ret += dfs(*it, cur);
	}
	
	if(--col[c[cur]] == 0) col.erase(c[cur]);
	return ret;
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(c[i]);
	}
	
	for(int i = 1; i < n; i++){
		int a, b;
		sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	
	for(int i = 1; i <= n; i++){
		col.clear();
		printf("%lld\n", dfs(i,-1));
	}
	
	return 0;
}
