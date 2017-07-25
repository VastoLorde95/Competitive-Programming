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

const int N = 20100;

vector<int> g[N];
vector<int> rg[N];

int vis[N];
int in[N];

void dfs(int x){
	stack<int> s;
	vis[x] = 1;
	foreach(it, rg[x]){
		dfs(*it);
	}
}

void solve(){
	int n, m;
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
		in[i] = 0;
		g[i].clear();
		rg[i].clear();
	}
	
	for(int i = 1; i <= n; i++){
		int d, x;
		sd(d);
		
		for(int j = 0; j < d; j++){
			sd(x);
			g[x].pb(i);
			rg[i].pb(x);
		}
	}
	
	for(int i = 0; i < m; i++){
		int x;
		sd(x);
		if(!vis[x]){
			dfs(x);
		}
	}
	
	priority_queue<int> q;
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			foreach(it, g[i]){
				if(vis[*it]) in[*it]++;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){	
		if(vis[i] and in[i] == 0){
			q.push(-i);
		}
	}
	
	vector<int> res;
	
	while(!q.empty()){
		int cur = -q.top();
		q.pop();
		
		res.pb(cur);
		
		foreach(it, g[cur]){
			if(!vis[*it]) continue;
			if(--in[*it] == 0) q.push(-(*it));
		}
	}
	
	printf("%d\n", (int) res.size());
	for(int &x: res){
		printf("%d ", x);
	}
	printf("\n");
	
}

int main(){
	int q;
	sd(q);
	while(q--) solve();
	return 0;
}
