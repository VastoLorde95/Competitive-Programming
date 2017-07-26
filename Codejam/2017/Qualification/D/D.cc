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

const int N = 110;

int n, m;
int bg[N][N];
int g[N][N];
int ans;

bitset<N> row;
bitset<N> col;
bitset<N+N> d1;
bitset<N+N> d2;

void init(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = 0;
		}
	}
	
	
	for(int i = 0; i < m; i++){
		char c;
		int x, y;
		cin >> c >> x >> y;
		g[x][y] = (c == '+')? 1 : ((c == 'x')? 2 : 3);
		bg[x][y] = g[x][y];
	}
	
	ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(1 <= g[i][j] and g[i][j] <= 2) ans += 1;
			else if(g[i][j] == 3) ans += 2;
		}
	}
	
	row.reset();
	col.reset();
	d1.reset();
	d2.reset();
}

void flip(int i, int j, int type){
	if(type == 1 or type == 3){
		int diag1 = i-j+n;
		int diag2 = i+j;
		
		d1.flip(diag1);
		d2.flip(diag2);
		
	}
	else if(type == 2 or type == 3){
		row.flip(i);
		col.flip(j);
	}
}

void branch(int r, int cur){
	if(r == n+1){
		if(cur > ans){
			ans = cur;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					bg[i][j] = g[i][j];
				}
			}
		}
		
		return;
	}
	
	int s1 = (n - min(row.count(), col.count())) * 3;
	if(cur + s1 <= ans) return;


	// try to palace o
	if(!row.test(r)){
		for(int c = 1; c <= n; c++){
			int x = r, y = c;

			if(g[x][y] == 3) continue;			
			
			if(g[x][y] == 0){
			}
			else{
				int old = g[x][y];
			}
			
			if(col.test(c)) continue;
			if(d1.test(r-c+n)) continue;
			if(d2.test(r+c)) continue;

			if(g[x][y] == 3) continue;
			
			int old = g[x][y];
			g[x][y] = 3;
			
			if(old == 0){
				flip(r, c, 3);
				branch(r+1, cur+2);
				flip(r, c, 3);
			}
			else if(old == 1 or old == 2){
				flip(r, c, old);
				flip(r, c, 3);
				branch(r+1, cur+1);
				flip(r, c, 3);
				flip(r, c, old);
			}
			
			g[x][y] = old;
		}
	}
	
	if(cur + s1 <= ans) return;
	
	// try to place x
	if(!row.test(r)){
		for(int c = 1; c <= n; c++){
			if(col.test(c)) continue;
			int x = r, y = c;
			if(g[x][y]) continue;
			
			g[x][y] = 2;
			
			flip(r, c, 2);
			branch(r+1, cur+1);
			flip(r, c, 2);
			
			g[x][y] = 0;
		}
	}
	
	if(cur + s1 <= ans) return;
	
	// try to place +
	for(int c = 1; c <= n; c++){
		if(d1.test(r-c+n)) continue;
		if(d2.test(r+c)) continue;
		int x = r, y = c;
		if(g[x][y]) continue;
		
		g[x][y] = 1;
		
		flip(r, c, 1);
		branch(r+1, cur+1);
		flip(r, c, 1);
		
		g[x][y] = 0;
	}
	
	branch(r+1, cur);
}

void solve(){
	init();
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			flip(i, j, g[i][j]);
		}
	}
	
	branch(1, ans);
	
	vector<pair<int, pii> > v;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(bg[i][j] != g[i][j]){
				v.pb(mp(bg[i][j], mp(i,j)));
			}
		}
	}
	
	cout << ans << ' ' << v.size() << endl;
	
	for(auto p : v){
		char c;
		if(p.fi == 1) c = '+';
		else if(p.fi == 2) c = 'x';
		else c = 'o';
		cout << c << ' ' << p.se.fi << ' ' << p.se.se << endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
