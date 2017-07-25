#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, a[10], tot;
long long MOD = 1000000007, c[101][101], dp[101][10];

long long invmod(long long a){
	long long b = MOD-2, ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){

	for(int i = 0; i <= 100; i++){
		c[i][0] = c[i][i] = 1;
	}
	
	for(int i = 0; i <= 100; i++){
		for(int j = 1; j < i; j++){
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;
		}
	}
	
	sd(n);
	for(int i = 0; i < 10; i++){
		sd(a[i]);
		tot += a[i];
	}
	
	if(tot > n){
		cout << 0 << "\n";
		return 0;
	}
	
	for(int i = a[9]; i <= n; i++){
		dp[i][9] = 1;
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 8; j >= 0; j--){
			for(int k = a[j]; k <= i; k++){
				if(j > 0){
					dp[i][j] += (dp[i-k][j+1]*c[i][k])%MOD;
					dp[i][j] %= MOD;
				}
				else{
					dp[i][j] += (dp[i-k][j+1]*c[i-1][k])%MOD;
					dp[i][j] %= MOD;
				}
			}
		}
	}
	
	long long ans = 0;
	
	for(int i = 1; i <= n; i++){
		ans += dp[i][0];
		ans %= MOD;
	}
	
	cout << ans << endl;
	
	
	return 0;
}
