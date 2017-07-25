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

const int N = 1010;

struct point{
	int x, y;
	int id;
};

int n;
vector<int> g[N];
int sz[N];
int ans[N];

point pivot;

bool cmp(const point &p1, const point &p2){
	return (p1.y - pivot.y) * (p2.x - pivot.x) < (p2.y - pivot.y) * (p1.x - pivot.x);
}

void mapit(int root, vector<point> p, int cur, int par){
	ans[cur] = root+1;
	if(p.size() == 1) return;
	
	vector<point> np;
	for(auto pp : p){
		if(pp.id != root) np.pb(pp);
		else pivot = pp;
	}
	
	sort(np.begin(), np.end(), cmp);
	
	int ptr = 0;
	for(int c : g[cur]){
		if(c == par) continue;
		
		vector<point> nxt;
		for(int j = 0; j < sz[c]; j++){
			nxt.pb(np[ptr++]);
		}
		
		mapit(nxt[0].id, nxt, c, cur);
	}
	
}

void dfs(int x, int p = -1){
	sz[x] = 1;
	foreach(it, g[x]){
		if(*it == p) continue;
		dfs(*it, x);
		sz[x] += sz[*it];
	}
}

int main(){ _
	cin >> n;
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	vector<point> p(n);
	
	int bottomleft = -1;
	int mnx = 100000;
	int mny = 100000;
	
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
		
		if(p[i]. x < mnx or (p[i].x == mnx and p[i].y < mny)){
			mnx = p[i].x;
			mny = p[i].y;
			bottomleft = i;
		}
	}
	
	dfs(1);
	mapit(bottomleft, p, 1, -1);
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
