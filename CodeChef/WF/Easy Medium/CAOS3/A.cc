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

const int N = 22;

int g[N][N];
int mn[N][N];
int grund[N][N][N][N];

void solve(){
	int n, m;
	cin >> n >> m;
	
	memset(g, 0, sizeof g);
	memset(mn, 0, sizeof mn);
	memset(grund, 0, sizeof grund);
	
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			g[i][j+1] = (s[j] == '^');
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!g[i][j]) continue;
			
			int a = 0, b = 0, c = 0, d = 0;
			
			for(int k = j-1; k >= 1 and g[i][k]; k--, a++);
			for(int k = j+1; k <= m and g[i][k]; k++, b++);
			for(int k = i-1; k >= 1 and g[k][j]; k--, c++);
			for(int k = i+1; k <= n and g[k][j]; k++, d++);
			
			if(min(min(a,b),min(c,d)) >= 2){
				mn[i][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int x1 = 1; x1 + i <= n; x1++){
				for(int y1 = 1; y1 + j <= m; y1++){
					int x2 = x1 + i;
					int y2 = y1 + j;
					
					set<int> vals;
					for(int a = x1; a <= x2; a++){
						for(int b = y1; b <= y2; b++){
							if(mn[a][b]){
								int z = 0;
								z ^= grund[x1][y1][a-1][b-1];
								z ^= grund[x1][b+1][a-1][y2];
								z ^= grund[a+1][y1][x2][b-1];
								z ^= grund[a+1][b+1][x2][y2];
								
								vals.insert(z);
								
							}
						}
					}
					
					int mex = 0;
					while(vals.count(mex)) mex++;
					
					grund[x1][y1][x2][y2] = mex;
				}
			}
		}
	}
	
	if(grund[1][1][n][m]) cout << "Asuna" << endl; else cout << "Kirito" << endl;

}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
