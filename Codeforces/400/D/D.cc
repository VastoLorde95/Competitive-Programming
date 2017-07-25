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

const int N = 100100;

int r[N];

vector<pii> g[N];
vector<int> k[N];

bool flag = true;

int color[N];

void dfs(int x, int p){
	color[x] = p;
	
	foreach(it, g[x]){
		int y = it->fi, tp = it->se;
		if(color[y]){
			if(tp == 1 and color[y] != color[x]){
				flag = false;
			}
			if(tp == 0 and color[y] == color[x]){
				flag = false;
			}
			continue;
		}
		
		if(tp == 1)
			dfs(y, p);
		else
			dfs(y, 3-p);
	}
}

int main(){ _
	int n, m;
	cin >> n >> m;
	
	int s = 1;
	
	for(int i = 1; i <= n; i++){
		cin >> r[i];
		s = s & r[i];
	}
	
	if(s){
		cout << "YES" << endl;
		return 0;
	}
	
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			int a;
			cin >> a;
			k[a].pb(i);
		}
	}
	
	for(int i = 1; i <= n; i++){
		int x = k[i][0], y = k[i][1];
		
		g[x].pb(mp(y, r[i]));
		g[y].pb(mp(x, r[i]));
	}
	
	for(int i = 1; i <= m; i++){
		if(color[i]) continue;
		dfs(i, 1);
	}
	
	cout << ((flag)? "YES" : "NO") << endl;
	
	return 0;
}
