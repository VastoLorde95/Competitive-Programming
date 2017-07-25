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

int n, x, l[10101], r[10101], indx;
ll dp[10101][2];
vector<int> pts;

int main(){
	sd2(n,x);
	pts.pb(x);
	
	for(int i = 0; i < n; i++){
		sd2(l[i],r[i]);
		pts.pb(l[i]);
		pts.pb(r[i]);
	}
	
	sort(pts.begin(), pts.end());
	
	int m = pts.size();
	for(int i = 0; i < m; i++) dp[i][0] = abs(pts[i] - x);

	for(int i = 0; i < n; i++){
		indx ^= 1;
		for(int j = 0; j < m; j++){
			if(pts[j] < l[i])
				dp[j][indx] = dp[j][1-indx] + l[i] - pts[j];
			else if(pts[j] > r[i])
				dp[j][indx] = dp[j][1-indx] + pts[j] - r[i];
			else
				dp[j][indx] = dp[j][1-indx];
		}
		
		for(int j = 1; j < m; j++) dp[j][indx] = min(dp[j][indx], dp[j-1][indx] + pts[j] - pts[j-1]);
		for(int j = m-2; j >= 0; j--) dp[j][indx] = min(dp[j][indx], dp[j+1][indx] + pts[j+1] - pts[j]);	
	}
	
	ll ans = 1e18;
	for(int i = 0; i < m; i++) ans = min(ans, dp[i][indx]);
	
	tr(ans);
	
	return 0;
}
