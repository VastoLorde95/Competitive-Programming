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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;
 
int n, a, b;
vector<int> g[6001], lis;
int r[6001];

int dfs(int c, int p){
	int mx = 0;
	int tmp = -1;
	int l = lower_bound(lis.begin(), lis.end(), r[c]) - lis.begin();
	
	if(l == lis.size()) lis.pb(r[c]);
	else{
		tmp = lis[l];
		lis[l] = r[c];
	}
	
	foreach(it, g[c]){
		if(*it == p) continue;
		mx = max(mx, dfs(*it, c));
	}
	
	mx = max(mx, (int) lis.size());
	
	if(tmp == -1) lis.pop_back();
	else lis[l] = tmp;
	
	return mx;
}

int main() {

	sd(n);
	for(int i = 1; i <= n; i++) sd(r[i]);
	for(int i = 1; i < n; i++){
		sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}	
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		lis.clear();
		ans = max(ans, dfs(i, -1));
	}
	
	printf("%d\n", ans);
	
    return 0;
}
