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

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef long long ll;

int t;
int a, b, c;
ll n, dp[35000];

int main(){
	sd(t);
	while(t--){
		scanf("%lld%d%d%d",&n,&a,&b,&c);
			
		if(n == 1){
			printf("0\n"); continue;
		}
		
		if(a < b) swap(a,b);
		if(b < c) swap(b,c);
		if(a < b) swap(a,b);
		
		for(int i = 0; i < c; i++){
			dp[i] = 1;
		}
		
		int ans = -1;
		
		for(int i = c; i < b; i++){
			dp[i] = dp[i-c];
			if(dp[i] >= n){
				ans = i; break;	
			}
		}
		
		if(ans != -1){
			printf("%d\n", ans); continue;
		}
		
		for(int i = b; i < a; i++){
			dp[i] = dp[i-b] + dp[i-c];
			if(dp[i] >= n){
				ans = i; break;	
			}
		}

		if(ans != -1){
			printf("%d\n", ans); continue;
		}

		for(int i = a;; i++){
			dp[i] = dp[i-a] + dp[i-b] + dp[i-c];
			if(dp[i] >= n){
				ans = i; break;
			}
		}
			
		printf("%d\n", ans);
		
		
	}
	return 0;
}
