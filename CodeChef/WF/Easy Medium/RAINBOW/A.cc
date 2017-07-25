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

const int N = 51;

int g[N][N];
int on[N];
int vis[N];
int n;

void dfs(int x, int &sz){
	if(vis[x]) return;
	sz++;
	vis[x] = 1;
	for(int i = 1; i <= n; i++){
		if(on[i]) dfs(i, sz);
	}
}

void solve(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		on[i] = 1;
		vis[i] = 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> g[i][j];
		}
	}
	
	for(int iter = 1; iter <= n; iter++){
		bool flag = true;
		
		vector<int> turnoff;
		
		for(int i = 1; i <= n; i++){
			if(!on[i]) continue;
			
			int col = -1;
			int cnt = 0;
			
			for(int j = 1; j <= n; j++){
				if(!on[j] or i == j) continue;
				
				if(!cnt){
					cnt++;
					col = g[i][j];
				}
				else if(g[i][j] != col){
					cnt++;
					break;
				}
			}
			
			if(cnt < 2){
				flag = false;
				turnoff.pb(i);
			}
		}
		
		if(flag) break;
		
		for(int i : turnoff) on[i] = 0;
	}
	
	int mx = 0;
	for(int i = 1; i <= n; i++){
		if(on[i] and !vis[i]){
			int sz = 0;
			dfs(i, sz);
			mx = max(mx, sz);
		}
	}
	
	if(mx < 3){
		mx = 0;
	}
	
	cout << mx << endl;
	
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
