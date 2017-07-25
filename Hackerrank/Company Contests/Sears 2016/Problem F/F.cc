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

const ld PI = 3.1415926535897932384626433832795;

const int N = 200100;
const int M = 50;

int p[N][M], rnk[N][M], size[N][M];

void create(int x, int k){
	p[x][k] = x;
	rnk[x][k] = 0;
	return;
}

int find(int x, int k){
	if(x != p[x][k]) return p[x][k] = find(p[x][k], k);
	return x;
}

void merge(int x, int y, int k){
	int px = find(x, k), py = find(y, k);
	if(px == py) return;
	if(rnk[px][k] > rnk[py][k]) p[py][k] = px;
	else p[px][k] = py;
	if(rnk[px][k] == rnk[py][k]) rnk[py][k] = rnk[py][k] + 1;
	return;
}

int n, m, c;

vector<pair<pii, int> > edges;

int main(){
	sd3(n,m,c);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= c; j++){
			create(i, j);
		}
	}
	
	for(int i = 0; i < m; i++){
		int u, v, w;
		sd3(u,v,w);
		edges.pb(mp(mp(u,v),w));
	}
	
	for(int i = 0; i <= c; i++){
		for(int j = 0; j < m; j++){
			if(edges[j].se == i) continue;
			
			merge(edges[j].fi.fi, edges[j].fi.se, i);
		}
	}
	
	int q; sd(q);
	for(int i = 0; i < q; i++){
		int x, y; sd2(x,y);
		
		if(find(x,0) != find(y,0)){
			printf("0\n");
			continue;
		}
		
		int ans = 0;
		for(int j = 1; j <= c; j++){
			if(find(x,j) != find(y,j)) ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
