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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef long long ll;

const int N = 5010;

int n, a, b, k;
ll dp[N][2], MOD = 1e9+7;

int main(){ _
	cin >> n >> a >> b >> k;
	
	dp[a][0] = 1;
	for(int i = 1; i <= k; i++){
		int id = i&1;
		for(int j = 1; j <= n; j++) dp[j][id] = 0;
		for(int j = 1; j < b; j++) (dp[j][1-id] += dp[j-1][1-id]) %= MOD;
		for(int j = n; j > b; j--) (dp[j][1-id] += dp[j+1][1-id]) %= MOD;
		
		for(int j = 1; j <= n; j++){
			int d = 1+abs(j-b)/2;
			if(j < b){
				dp[j][id] = (dp[b-d][1-id] - dp[j][1-id] + dp[j-1][1-id] + MOD)%MOD;
			}
			else if(j > b){
				dp[j][id] = (dp[b+d][1-id] - dp[j][1-id] + dp[j+1][1-id] + MOD)%MOD;
			}
			else{
				dp[j][id] = 0;
			}
		}
	}
	
	ll ans = 0;
	int id = k&1;
	for(int i = 1; i <= n; i++){
		ans += dp[i][id];
		if(ans >= MOD) ans -= MOD;
	}
	
	cout << ans << '\n';
	
	return 0;
}
