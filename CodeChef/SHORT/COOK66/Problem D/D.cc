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

typedef long long ll;

const int N = 10;

int t, n;
int l[N][N], s[N];

ll MOD = 1e9 + 7;
ll inf = 1e18;

ll dp[N][N][N][2];
ll ways[N][N][N][2];

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){
	sd(t);
	
	while(t--){
		sd(n);
		bool allzero = false;
		for(int i = 1; i <= n; i++){
			sd(s[i]);
			bool ok = false;
			for(int j = 1; j <= s[i]; j++){
				sd(l[i][j]);
				if(l[i][j] != 0) ok = true;
			}
			
			if(!ok) allzero = true;
			
			for(int j = 2; j <= s[i]; j++){
				l[i][j] += l[i][j-1];
			}
		}
		
		if(allzero){
			long long ans = 0;
			long long cnt = 1;
			
			for(int i = 1; i <= n; i++){
				cnt *= ((s[i]*(s[i]+1))/2);
				cnt %= MOD;
			}
			
			printf("%lld %lld\n",ans,cnt);
			continue;
		}
		
		memset(dp, 0, sizeof dp);
		memset(ways, 0, sizeof ways);

		long long p = (s[1]*(s[1]+1))/2;
		
		for(int i = 1; i <= s[1]; i++){
			for(int j = i; j <= s[1]; j++){
				dp[1][i][j][0] = dp[1][i][j][1] = l[1][j]-l[1][i-1];
				ways[1][i][j][0] = ways[1][i][j][1] = 1;
//				tr(func,line,1,i,j,dp[1][i][j][0],dp[1][i][j][1],ways[1][i][j][0],ways[1][i][j][1]);
			}
		}
		
		for(int i = 2; i <= n; i++){
//			tr("$$$");
			for(int j = 1; j <= s[i]; j++){
				for(int k = j; k <= s[i]; k++){
					ll sum = l[i][k]-l[i][j-1];
										
					dp[i][j][k][0] = -inf;
					dp[i][j][k][1] = inf;
					ways[i][j][k][0] = ways[i][j][k][1] = 0;		
					
					ll &a = dp[i][j][k][0], &b = dp[i][j][k][1];
					ll &c = ways[i][j][k][0], &d = ways[i][j][k][1];
						
					ll t1, t2;
					for(int x = 1; x <= s[i-1]; x++){
						for(int y = x; y <= s[i-1]; y++){
							t1 = sum * dp[i-1][x][y][0];	// max
							t2 = sum * dp[i-1][x][y][1];	// min
							
							// max
							if(t1 > a){
								a = t1;
								c = ways[i-1][x][y][0];
							}
							else if(t1 == a){
								c += ways[i-1][x][y][0];
								if(c >= MOD) c -= MOD;
							}
							
							if(t2 > a){
								a = t2;
								c = ways[i-1][x][y][1];
							}
							else if(t2 == a and dp[i-1][x][y][0] != dp[i-1][x][y][1]){
								c += ways[i-1][x][y][1];
								if(c >= MOD) c -= MOD;
							}
							
							// min
							if(t1 < b){
								b = t1;
								d = ways[i-1][x][y][0];
							}
							else if(t1 == b){
								d += ways[i-1][x][y][0];
								if(d >= MOD) d -= MOD;
							}
							
							if(t2 < b){
								b = t2;
								d = ways[i-1][x][y][1];
							}
							else if(t2 == b and dp[i-1][x][y][0] != dp[i-1][x][y][1]){
								d += ways[i-1][x][y][1];
								if(d >= MOD) d -= MOD;
							}
						}
					}
					
//					tr(func,line,i,j,k,a,b,c,d);
					if(sum == 0) c = p;
					if(sum == 0) d = p;
					
				}
			}
			
			p *= (s[i]*(s[i]+1))/2;
			p %= MOD;
		}
		
		ll best = -inf;
		ll cnt = 0;
		
		for(int i = 1; i <= s[n]; i++){
			for(int j = i; j <= s[n]; j++){
				if(dp[n][i][j][0] > best){
					best = dp[n][i][j][0];
					cnt = ways[n][i][j][0];
				}
				else if(dp[n][i][j][0] == best){
					cnt += ways[n][i][j][0];
					if(cnt >= MOD) cnt -= MOD;
				}
			}
		}
		
		printf("%lld %lld\n", best, cnt);
		
	}
	return 0;
}
