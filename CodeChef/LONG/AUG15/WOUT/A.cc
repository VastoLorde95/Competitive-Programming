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

long long dp[1001000], n, h, ans, cur;
int t, ll, hh;

int main(){
	sd(t);
	while(t--){
		scanf("%lld%lld",&n,&h);
		for(int i = 0; i < n; i++)
			dp[i] = 0;
		for(int i = 0; i < n; i++){
			sd2(ll,hh);
			dp[ll]++;
			dp[hh+1]--;
		}
		for(int i = 1; i < n; i++){
			dp[i] += dp[i-1];
		}

		cur = 0;
		for(int i = 0; i < h; i++){
			cur += dp[i];
		}	
	
	
		ans = n*h - cur;
		for(int i = h; i < n; i++){
			cur += dp[i];
			cur -= dp[i-h];
			ans = min(ans, n*h - cur);
		}
		printf("%lld\n", ans);
		
	}
	return 0;
}
