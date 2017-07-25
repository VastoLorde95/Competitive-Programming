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

int n, k, a[300100], cnt1, cnt2, l1, l2;
long long dp[300100];
vector<pair<int, int> > g[300100];

int main(){
	sd2(n,k);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	sort(a+1, a+n+1);
	
	cnt1 = n%k, cnt2 = k - cnt1;
	l1 = n/k+1, l2 = n/k;
	
	for(int i = 0; i <= cnt1; i++){
		for(int j = 0; j <= cnt2; j++){
			int x = (i*l1 + j*l2);
			if(x > 0 and x <= n){
				g[x].pb(mp(i,j));
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		dp[i] = 1e18;
	}
	
	dp[0] = 0;
	
	tr5("$",l1,cnt1,l2,cnt2)
	
	for(int i = 1; i <= n; i++){
		foreach(it, g[i]){
			int x = it->fi, y = it->se;
			long long v1 = 1e18, v2 = 1e18;
			if(x > 0) v1 = dp[i-l1] + abs(a[(x*l1) + (y*l2)] - a[((x-1)*l1) + (y*l2) + 1]);
			if(y > 0) v2 = dp[i-l2] + abs(a[(x*l1) + (y*l2)] - a[(x*l1) + ((y-1)*l2) + 1]);
//			tr6(x,y,i,dp[i],v1,v2)
			dp[i] = min(dp[i],min(v1,v2));
			tr4(x,y,i,dp[i])
		}	
	}


	
	
	cout << dp[n] << "\n";
	
	return 0;
}
