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

int t, n, m, k, in[10100], out[10100], v[10100];
long long c[10100], dp[10100][310], inf = 1e15;
vector<int> g[10100];

int main(){
	sd(t);
	
	while(t--){
		sd3(n,m,k);
		for(int i = 0; i < n; i++){
			g[i].clear();
			scanf("%lld", c+i);
			in[i] = out[i] = 0;
			v[i] = 0;
			for(int j = 1; j <= k; j++){
				dp[i][j] = -inf;
			}
			
			dp[i][0] = c[i];
			
		}
		
		for(int i = 1; i < n; i++){
			int x, y; sd2(x,y);
			g[x].pb(y);
			out[x]++, in[y]++;
		}
		
		queue<int> q;
		for(int i = 0; i < n; i++){
			if(in[i] == 0){
				q.push(i);
				dp[i][1] = c[i]*m;
			}
		}
		
		ll mx = -inf;
		
		while(!q.empty()){
			int cur = q.front(); q.pop();
			if(v[cur]) continue;
			
			v[cur] = 1;	
				
//			for(int i = 0; i <= k; i++){
//				tr3(cur, i, dp[cur][i]);
//			}			
						
			for(int i = 0; i <= k; i++) mx = max(mx, dp[cur][i]);
			for(int i = 0; i <= k; i++) dp[cur][i] = max(dp[cur][i], 0ll);
			
//			for(int i = 0; i <= k; i++){
//				tr3(cur, i, dp[cur][i]);
//			}			
						
			foreach(it, g[cur]){
				if(v[*it]) continue;
				
				dp[*it][0] = max(dp[*it][0], c[*it] + dp[cur][0]);
				
				for(int i = 1; i <= k; i++){
					dp[*it][i] = max(dp[*it][i], max(dp[cur][i-1] + c[*it]*m, dp[cur][i] + c[*it]));
				}
				
				in[*it]--;
				if(in[*it] == 0){
					q.push(*it);
				}	
			}
			
//			tr2(cur, mx);
		}
		
		for(int i = 0; i < n; i++){
			mx = max(mx, max(c[i], c[i]*m));
		}
		
		printf("%lld\n", mx);
	}
	return 0;
}

