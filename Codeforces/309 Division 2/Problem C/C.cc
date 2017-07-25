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

long long dp[1001][1001], sum[1001][1001], MOD = 1000000007, f[1001];
int k, n, c[1001], l;

long long inv_mod(long long x){
	long long ret = 1, y = MOD - 2;
	while(y){
		if(y%2) ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y >>= 1;
	}
	return ret;
}

long long nCr(int x, int y){
	return (((f[x] * inv_mod(f[y]))%MOD)*inv_mod(f[x-y]))%MOD;
}

int main(){
	f[0] = 1;
	for(int i = 1; i <= 1000; i++){
		f[i] = (f[i-1]*i)%MOD;
	}
	
	sd(k);
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		n += c[i];
	}	
	
	for(int i = c[1]; i <= n-k+1; i++){
		dp[1][i] = nCr(i-1, c[1]-1);
		sum[1][i] = (sum[1][i-1] + dp[1][i])%MOD;
	}
	
	l = c[1];
	
	for(int i = 2; i <= k; i++){
		for(int j = l+c[i]; j <= n-k+i; j++){
			dp[i][j] = (sum[i-1][j-1]*nCr(j-l-1,c[i]-1))%MOD;
			sum[i][j] = (sum[i][j-1] + dp[i][j])%MOD;
		}
		l += c[i];
	}
	
	cout << dp[k][n] << endl;
	
	
	
	return 0;
}
