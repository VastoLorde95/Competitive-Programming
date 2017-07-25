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

int n;
long long a[500100], tot[500100], sum;
vector<long long> vals[500100];
vector<int> g[500100];

void dfs(int cur, int prev){
	foreach(it, g[cur]){
		if(*it == prev) continue;
		dfs(*it, cur);
		vals[cur].pb(tot[*it]);
		tot[cur] += tot[*it];
	}
	
	tot[cur] += a[cur];
}

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1,-1);
	
	long long ans = 0;
	
	for(int i = 1; i <= n; i++){
		foreach(it, g[i]){
			if(tot[*it] > tot[i]){
				vals[i].pb(sum-tot[i]);
				break;
			}
		}
		
		sort(vals[i].begin(), vals[i].end(), greater<long long>());
		
		long long tmp = a[i];
		
		for(int j = 1; j < vals[i].size(); j++){
			tmp += vals[i][j];
		}
		ans = max(ans, tmp);
	}
	
	tr(ans);
	
	return 0;
}
