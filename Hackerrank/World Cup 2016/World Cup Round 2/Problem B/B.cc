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

int n, a[40], b[40];
long long ans;
map<int,int> dp[40];

int main(){
	sd(n);
	
	if(n == 1){
		printf("0\n"); return 0;
	}
	
	for(int i = 1; i <= n; i++){
		sd(a[i]); b[i] = b[i-1] + a[i];
	}
	
	int mid = (n+1)/2;
	
	
	dp[0][0]++;
	dp[1][a[1]]++;
	
	for(int i = 2; i <= mid; i++){
		int sum = 0;
		for(int j = 0; i-j >= 1; j++){
			sum += a[i-j];
			foreach(it, dp[i-j-1]){
				dp[i][sum^it->fi] += it->se;
			}
		}
	}
	
	dp[n+1][0]++;
	dp[n][a[n]]++;
	
	for(int i = n-1; i > mid; i--){
		int sum = 0;
		for(int j = 0; i+j <= n; j++){
			sum += a[i+j];
			foreach(it, dp[i+j+1]){
				dp[i][sum^it->fi] += it->se;
			}
		}
	}
	
	for(int i = 0; i <= mid; i++){
		foreach(it, dp[i]){
			for(int j = mid+1; j <= n; j++){
				ans += (long long) (it->se) * (long long) dp[j+1][it->fi ^ (b[j]-b[i])];
			}
		}
	}
		
	printf("%lld\n", ans);
	
	return 0;
}
