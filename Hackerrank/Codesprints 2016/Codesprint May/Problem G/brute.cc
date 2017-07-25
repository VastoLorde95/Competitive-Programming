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

const int N = 1001;

struct state{
	int cur;
	int mx;
	set<int> s;
};

int n, m, q;

vector<pii> g[N];
int t[N];
int best;
int iter;

int main(){
	sd3(n,m,q);
	for(int i = 1; i <= n; i++){
		sd(t[i]);
	}
	
	for(int i = 1; i <= m; i++){
		int x, y, u;
		sd3(x,y,u);
		tr(x,y,u);
		g[x].pb(mp(y,u));
		g[y].pb(mp(x,u));
	}
	
	for(int i = 1; i <= q; i++){
		int x, y, k;
		sd3(x, y, k);
		
		set<int> s;
		best = 1e9;
		iter = 0;
		
		dfs(x, -1, y, k, 0, s);
		done:
		if(best == 1e9) best = -1;
		printf("%d\n", best);
		
	}
	
	return 0;
}
