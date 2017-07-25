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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 101, M = 1001;

int n, m;
int x[M];

long double dp[2][N*M];

int main(){
	sd2(n,m);
	
	if(m == 1){
		printf("%.9lf\n", 1.0f);
		return 0;
	}
	
	for(int i = 1; i <= n; i++) sd(x[i]);
	
	for(int i = 1; i <= m; i++){
		dp[1][i] = (double) 1.0f / (m-1);
		if(i == x[1]) dp[1][i] = 0;
	}
	
	int id = 1;
	for(int i = 2; i <= n; i++){
		id = i%2;
		
		for(int j = i-1; j < N*M; j++) dp[1-id][j] += dp[1-id][j-1];
		for(int j = 0; j < N*M; j++) dp[id][j] = 0;
						
		for(int j = i; j <= i*m; j++){
			if(j <= m){
				dp[id][j] = dp[1-id][j-1];
				if(j > x[i]) dp[id][j] -= (dp[1-id][j-x[i]]-dp[1-id][j-x[i]-1]);
				dp[id][j] /= (m-1);
			}
			else{
				dp[id][j] = dp[1-id][j-1] - dp[1-id][j-m-1];
				dp[id][j] -= (dp[1-id][j-x[i]]-dp[1-id][j-x[i]-1]);
				dp[id][j] /= (m-1);
			}
		}
	}	

	int sum1 = 0;
	for(int i = 1; i <= n; i++) sum1 += x[i];
	
	long double sum2 = 0;
	for(int i = 0; i < sum1; i++) sum2 += dp[id][i];
	
	sum2 *= (m-1);
	
	printf("%.9lf\n", (double) sum2+1);	
		
	return 0;
}
