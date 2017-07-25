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

const int N = 300100;

vector<int> g[N];
set<int> colors;

int col[N];
vector<int> v[N];

void dfs(int x, int p = -1){
	unordered_set<int> s;
	
	for(int a : v[x]){
		if(col[a]) s.insert(col[a]);
	}
	
	int clr = 1;
	for(int a : v[x]){
		if(col[a]) continue;
		while(s.count(clr)){
			++clr;
		}
		
		col[a] = clr;
		s.insert(clr);
	}
	
	foreach(it, g[x]){
		if(*it == p) continue;
		dfs(*it, x);
	}
}

int main(){ _
	int n, m;
	cin >> n >> m;	
	
	for(int i = 1; i <= n; i++){
		int s;
		cin >> s;
		for(int j = 0; j < s; j++){
			int x;
			cin >> x;
			v[i].pb(x);
		}
	}	
	
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(1);
	
	int mx = 0;
	for(int i = 1; i <= m; i++){
		if(!col[i]) col[i] = 1;
		mx = max(mx, col[i]);
	}
	
	cout << mx << endl;
	for(int i = 1; i <= m; i++){
		cout << col[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
