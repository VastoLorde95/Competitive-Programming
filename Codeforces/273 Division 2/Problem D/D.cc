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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

map<pair<pair<int,int>,int>, long long> memo;

int r, g, dp[200001], MOD = 1000000007, ans;

int main(){
	sd2(r,g);
	
	int h = (sqrt(8*(r+g)+1)-1)/2.0;
	
	dp[0] = 1;
	for(int i = 1; i <= h; i++){
		for(int j = r-i; j >= 0; j--){
			dp[i+j] += dp[j]; // use the i red blocks for construction of the next level
			if(dp[i+j] >= MOD) dp[i+j] -= MOD;
		}
	}
	
	for(int i = max((h*(h+1))/2-g,0); i <= r; i++){
		ans += dp[i];
		if(ans >= MOD) ans -= MOD;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
