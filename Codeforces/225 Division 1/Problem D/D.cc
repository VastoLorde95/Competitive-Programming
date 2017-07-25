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

int n, a[1001], off = 10000;
long long MOD = 1e9+7, dp[2][21000], ans;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	
	int indx = 0, up = off+off;
	dp[0][off] = 1;
	dp[0][off+a[0]] = 1;
	dp[0][off-a[0]] = 1;
	
	for(int i = 1; i < n; i++){
		indx ^= 1;
				
		for(int j = 0; j <= up; j++){
			dp[indx][j] = 0;
			if(j-a[i] >= 0)
				dp[indx][j] += dp[1-indx][j-a[i]];
			if(j+a[i] <= up)
				dp[indx][j] += dp[1-indx][j+a[i]];
			dp[indx][j] %= MOD;
		}
		
		ans = (ans + dp[indx][off])%MOD;	
		dp[indx][off] += 1;
	}
	
	tr(ans);
	
	return 0;
}
