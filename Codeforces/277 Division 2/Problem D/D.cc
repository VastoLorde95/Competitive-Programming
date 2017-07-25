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

int d, n, a[2001], u, v;
vector<int> g[2001];
long long ans, MOD = 1000000007;

long long dfs(int cur, int prev, int mn, int start){
	if(a[cur] > mn+d or a[cur] < mn) return 0;
	
	if(a[cur] == mn and cur < start) return 0;
		
	long long tmp = 1;
	
	for(int i = 0; i < g[cur].size(); i++){
		v = g[cur][i];
		if(v != prev){
			tmp *= (1+dfs(v, cur, mn, start));
			tmp %= MOD;
		}
	}
	
	return tmp;
}

int main(){
	sd2(d,n);
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	for(int i = 1; i < n; i++){
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(int i = 1; i <= n; i++){
		ans += dfs(i, -1, a[i], i);
		ans %= MOD;
	}	
	
	cout << ans << endl;
	
	return 0;
}
