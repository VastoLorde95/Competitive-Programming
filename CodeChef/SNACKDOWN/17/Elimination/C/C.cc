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

const int N = 500500;

vector<int> g1[N];
vector<int> g2[N];

int l1[N], r1[N];
int tme;

vector<int> tree;

int query(int idx, int sum = 0){
    for(; idx; idx -= (idx & -idx)){
    	sum += tree[idx];
    }
    return sum;
}

void update(int idx, int val){
    for(; idx < tree.size(); idx += (idx & -idx)){
    	tree[idx] += val;
    }
}

int ans[N];
int ptr[N];
int par[N];
int n;

void dfs1(){
	for(int i = 1; i <= n; i++){
		ptr[i] = 0;
	}
	
	stack<int> s;
	s.push(1);
	
	while(!s.empty()){
		int x = s.top();
		if(ptr[x] == 0){
//			tr(x);
			l1[x] = ++tme;
		}
		
		if(ptr[x] == g1[x].size()){
			r1[x] = tme;
			s.pop();
		}
		else{
			if(g1[x][ptr[x]] == par[x]){
				ptr[x]++;
				continue;
			}
			
			par[g1[x][ptr[x]]] = x;
			s.push(g1[x][ptr[x]++]);
		}
	}
}

void dfs2(){
	for(int i = 1; i <= n; i++){
		ptr[i] = 0;
	}
	
	stack<int> s;
	s.push(1);
	
	while(!s.empty()){
		int x = s.top();
		
//		tr(x);
		
		if(ptr[x] == 0){
			ans[x] = query(l1[x]);
			update(l1[x],      1);
			update(r1[x] + 1, -1);
		}
		
		if(ptr[x] == g2[x].size()){
			update(l1[x],    -1);
			update(r1[x] + 1, 1);
			s.pop();
		}
		else{
			if(g2[x][ptr[x]] == par[x]){
				ptr[x]++;
				continue;
			}
			par[g2[x][ptr[x]]] = x;
			s.push(g2[x][ptr[x]++]);
		}
	}
}

void solve(){
	cin >> n;
	
	tree.clear();
	tree.resize(n+10, 0);
	
	for(int i = 1; i <= n; i++){
		g1[i].clear();
		g2[i].clear();
	}
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g1[u].pb(v);
		g1[v].pb(u);
	}
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g2[u].pb(v);
		g2[v].pb(u);
	}
	
	tme = 0;
	dfs1();
	dfs2();
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
