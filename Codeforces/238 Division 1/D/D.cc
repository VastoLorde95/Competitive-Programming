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

const int LOGN = 17;
const int N = 1 << LOGN;

ll x[N];
ll y[N];

int n;
int rgt[N];

int p[LOGN][N];
int l[N];

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);
	
	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) 
		if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];

	return p[0][x];
}

vector<int> g[N];

void dfs(int x, int prev = n){
	p[0][x] = prev;
	for(int y : g[x]){
		l[y] = l[x] + 1;
		dfs(y, x);
	}
}

int main(){ _
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
	
	int mx = y[n];
	rgt[n] = -1;
	for(int i = n-1; i > 0; i--){
		int pos = i+1;
		
		while(pos < n){
			int nxt = rgt[pos];
			if((y[nxt] - y[i]) * (x[pos] - x[i]) + (x[nxt] - x[i]) * y[i] > (x[nxt] - x[i]) * y[pos]){
				pos = nxt;
			}
			else break;
		}
		
		rgt[i] = pos;
	}
	
	for(int i = 1; i < n; i++){
		g[rgt[i]].pb(i);
	}
	
	dfs(n);
	
	for(int j = 1; j < LOGN; j++){
		for(int i = 1; i <= n; i++){
			p[j][i] = p[j-1][p[j-1][i]];
		}
	}
	
	int m;
	cin >> m;
	
	while(m--){
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << ' ';
	}
	cout << endl;
	
	return 0;
}
