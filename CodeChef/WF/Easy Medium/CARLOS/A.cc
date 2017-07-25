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

const int M = 200;
const int N = 200100;
const ll INF = 1e9;

int dp[2][M];
int g[M][M];

void solve(){
	int m, k, n;
	sd3(m,k,n);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			g[i][j] = INF;
		}
		g[i][i] = 0;
	}	
	
	for(int i = 0; i < k; i++){
		int x, y;
		sd2(x,y);
		x--, y--;
		g[x][y] = g[y][x] = 1;
	}


	for(int k = 0; k < m; k++){	
		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				if(i == j or g[i][j] == 1) continue;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	int xx;
	sd(xx);
	--xx;
	for(int i = 0; i < m; i++){
		dp[0][i] = g[xx][i];
		if(i > 0) dp[0][i] = min(dp[0][i], dp[0][i-1]);
	}
	
	int id = 0;
	for(int i = 1; i < n; i++){
		sd(xx);
		--xx;
		id ^= 1;
		dp[id][0] = dp[id^1][0] + g[xx][0];
		for(int j = 1; j < m; j++){
			dp[id][j] = min(dp[id][j-1], dp[id^1][j] + g[xx][j]);
		}
	}
	
	int ans = (dp[id][m-1] >= INF)? -1 : dp[id][m-1];
	
	printf("%d\n", ans);
	
}

int main(){
	int t;
	sd(t);
	while(t--) solve();	
	return 0;
}
