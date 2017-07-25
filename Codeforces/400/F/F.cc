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

const int N = 100100;


int pt;
bool cmp(const int &i, const int &j){
	if(i < pt and j < pt){
		return i < j;
	}
	else if(i > pt and j > pt){
		return i < j;
	}
	else{
		return i > j;
	}
}

vector<int> nxt[N];

int a[N];
int b[N];

int lft[N];
int rgt[N];

pii tosort[N];

bool importance(const int &i, const int &j){
	return tosort[i] < tosort[j];
}

vector<int> face[N];
vector<int> g[N];

map<pii, int> id;
set<pii> used;

void buildFace(int from, int to, int f){
	face[f].pb(to);
	used.insert(mp(from,to));
	
	pt = to;
	
	vector<int> &v = nxt[to];
	int nxt = *upper_bound(v.begin(), v.end(), from, cmp);
	
	if(used.count(mp(to, nxt))) return;
	buildFace(to, nxt, f);
}

int vis[N];
int usd[N];
int sz[N];
int lvl[N];

void dfs(int x, int h){
	sz[x] = 1;
	vis[x] = h;
	foreach(it, g[x]){
		if(usd[*it]) continue;
		if(vis[*it] == h) continue;
			
		dfs(*it, h);
		sz[x] += sz[*it];
	}
}

int findCentroid(int x, int n, int prev){
	foreach(it, g[x]){
		if(vis[*it] != vis[x] or *it == prev) continue;
		if(sz[*it] > n/2) return findCentroid(*it, n, x);
	}
	return x;
}

void decompose(int x, int h){
	dfs(x, h);
	int c = findCentroid(x, sz[x], -1);
	
	lvl[c] = h;
	usd[c] = 1;
	
	foreach(it, g[c]){
		if(!usd[*it]) decompose(*it, h+1);
	}
}

int main(){ _
	int n, m;
	cin >> n >> m;
	
	if(m == 0){
		cout << 1 << endl;
		return 0;
	}
	if(m == 1){
		cout << "1 2" << endl;
		return 0;
	}
	
	nxt[1].pb(n);
	nxt[n].pb(1);
	for(int i = 2; i <= n; i++){
		nxt[i].pb(i-1);
		nxt[i-1].pb(i);
	}
	
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		
		if(a[i] < b[i]) swap(a[i], b[i]);
		
		id[mp(a[i], b[i])] = id[mp(b[i], a[i])] = i;
		
		nxt[a[i]].pb(b[i]);
		nxt[b[i]].pb(a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		pt = i;
		sort(nxt[i].begin(), nxt[i].end(), cmp);
	}
	
	int cur = 0;
	
	for(int i = 0; i < m; i++){
		if(!used.count(mp(a[i], b[i]))){
			face[++cur].pb(a[i]);
			
			buildFace(a[i], b[i], cur);
			
			for(int j = 1; j < face[cur].size(); j++){
				int x = face[cur][j-1], y = face[cur][j];
				
				if(x-1 != y and !(x == 1 and y == n)){
					int k = id[mp(x,y)];
					if(x > y)
						lft[k] = cur;
					else
						rgt[k] = cur;
				}
			}
			
		}
		if(!used.count(mp(b[i], a[i]))){
			face[++cur].pb(b[i]);
			
			buildFace(b[i], a[i], cur);
			
			for(int j = 1; j < face[cur].size(); j++){
				int x = face[cur][j-1], y = face[cur][j];
				
				if(x-1 != y and !(x == 1 and y == n)){
					int k = id[mp(x,y)];
					if(x > y)
						lft[k] = cur;
					else
						rgt[k] = cur;
				}
			}
		}
		
		int x = lft[i], y = rgt[i];
		
		assert(x > 0 and y > 0);
		
		g[x].pb(y);
		g[y].pb(x);
	}

	for(int i = 1; i <= cur; i++){
		int mx = 0, smx = 0;
		for(int j = 1; j < face[i].size(); j++){
			int x = face[i][j];
			if(x > mx){
				smx = mx;
				mx = x;
			}
			else if(x > smx) smx = x;
		}
		
		tosort[i] = mp(mx, smx);
	}
	
	vector<int> faces;
	for(int i = 1; i <= cur; i++) faces.pb(i);
	
	sort(faces.begin(), faces.end(), importance);
	
	decompose(1, 1);
	
	for(int x : faces) cout << lvl[x] << ' ';
	cout << endl;

	return 0;
}
