#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int N = 510;
const double INF = 1e9;

int n, m;
vector<pair<int, double> > g[N];
vector<pair<int, double> > r[N];
vector<pair<int, double> > c[N];

double dis[N];

int ok1[N];
int ok2[N];

bool f(double val, int A, int B){
	for(int i = 1; i <= n; i++){
		c[i].clear();
		if(ok1[i] and ok2[i]){
			foreach(it, g[i]){
				if(ok1[it->fi] and ok2[it->fi]){
					c[i].pb(mp(it->fi, it->se - val));
				}
			}
		}
	}	
	c[B].pb(mp(A,0));

	for(int i = 1; i <= n; i++){
		dis[i] = INF;
	}
	dis[A] = 0;

	for(int k = 1; k < n; k++){
		for(int i = 1; i <= n; i++){
			foreach(it, c[i]){
				int j = it->fi;
				double w = it->se;
				
				if(dis[i] + w < dis[j]){
					dis[j] = dis[i] + w;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		foreach(it, c[i]){
			int j = it->fi;
			double w = it->se;
			
			if(dis[i] + w < dis[j]) return true;
		}
	}
	
	return false;
	
}

void dfs1(int x){
	if(ok1[x]) return;
	ok1[x] = 1;
	foreach(it, g[x]) dfs1(it->fi);
}

void dfs2(int x){
	if(ok2[x]) return;
	ok2[x] = 1;
	foreach(it, r[x]) dfs2(it->fi);
}

void solve(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		g[i].clear();
		r[i].clear();
		ok1[i] = ok2[i] = 0;
	}
	
	for(int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		g[x].pb(mp(y,z));
		r[y].pb(mp(x,z));
	}
	
	int A, B;
	cin >> A >> B;
	
	dfs1(A);
	dfs2(B);
	
	if(!ok1[B]){
		cout << -1 << endl;
		return;
	}
	
	double lo = 0, hi = 100, mid;
	
	while(hi-lo > 1e-9){
		mid = (lo + hi) / 2;
		
		if(f(mid, A, B)) hi = mid;
		else lo = mid;
	}
	
	cout << fixed << setprecision(8) << lo << endl;
	
	
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
