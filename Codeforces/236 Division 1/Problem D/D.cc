#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef long long ll;

int t, n, k, dp[51][1001], r[51][1001];
ll f[51], MOD = 1e9 + 7;
int main(){
	f[0] = 1;
	for(int i = 1; i < 51; i++) f[i] = (f[i-1]*i)%MOD;
	
	for(int i = 0; i < 1001; i++) r[0][i] = 1;
	for(int i = 1; i < 1001; i++){
		for(int j = 1; j < 51; j++){
			for(int k = i; k < 1001; k++){
				dp[j][k] += r[j-1][k-i]; if(dp[j][k] >= MOD) dp[j][k] -= MOD;
			}
		}
		for(int j = 1; j < 51; j++){
			int tot = 0;
			for(int k = 0; k < 1001; k++){
				tot += dp[j][k]; if(tot >= MOD) tot -= MOD;
				r[j][k] = tot;
			}
		}
	}
	
	sd(t);
	while(t--){
		sd2(n,k);
		if(k > 50) printf("0\n");
		else printf("%d\n", (int) (((ll) f[k] * r[k][n])%MOD));
	}
	return 0;
}
