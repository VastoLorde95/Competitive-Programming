#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 1100;

int n, m, p;
int g[N][N];
long long dp[N][N], inf = 1e17;
long long pd[N][N];

bool ok(int x, int y){
	if(x < 1 or x > n or y < 1 or y > m) return false;
	return true;
}

int main(){
	sd3(n,m,p);
	
	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= m+1; j++){
			g[i][j] = -inf;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sd(g[i][j]);
		}
	}

	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= m+1; j++){
			dp[i][j] = pd[i][j] = -inf;
		}
	}

	dp[1][1] = g[1][1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 and j == 1) continue;
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + g[i][j];
		}
	}
	
	pd[n][m] = g[n][m];
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(i == n and j == m) continue;
			pd[i][j] = max(pd[i+1][j], pd[i][j+1]) + g[i][j];
		}
	}

	long long res = dp[n][m];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			res = max(res, dp[i-1][j+1] + g[i][j+1] + g[i][j] + pd[i+1][j] - p);
			res = max(res, dp[i-1][j+1] + g[i][j] + pd[i][j+1] - p);
			res = max(res, dp[i+1][j-1] + g[i+1][j] + g[i][j] + pd[i][j+1] - p);
			res = max(res, dp[i+1][j-1] + g[i][j] + pd[i+1][j] - p);
			res = max(res, dp[i][j] + g[i][j+1] + pd[i+1][j] - p);
			res = max(res, dp[i][j] + g[i+1][j] + pd[i][j+1] - p);
		}
	}

	printf("%lld\n", res);
	
	return 0;
}
