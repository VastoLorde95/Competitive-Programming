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

int n, m, color[100100], v[100100];
vector<int> g[100100];
vector<int> comp[100100];

bool dfs(int cur, int prev, int col, int cnt){
	if(v[cur]){
		if(color[cur] != col) return false;
		return true;
	}
	
	v[cur] = 1;
	color[cur] = col;
	comp[cnt].pb(cur);
	
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		if(!dfs(*it, cur, (col == 1)? 2: 1, cnt)) return false;
	}
	return true;
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		int a, b; sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			if(!dfs(i,-1,1,cnt++)){
				printf("0 1\n"); return 0;
			}
		}
	}
	
	long long ans = 0;
	for(int i = 0; i < cnt; i++){
		if(comp[i].size() > 2){
			int c1 = 0, c2 = 0;
			foreach(it, comp[i]){
				if(color[*it] == 1) c1++; else c2++;
			}
			ans += ((long long)c1*(c1-1))/2 + ((long long)c2*(c2-1))/2;
		}
	}
	
	if(ans > 0){
		printf("1 %I64d\n", ans); return 0;
	}
	
	for(int i = 0; i < cnt; i++){
		if(comp[i].size() > 1){
			ans += (n-2);
		}
	}
	
	if(ans > 0){
		printf("2 %I64d\n", ans); return 0;
	}
	
	printf("3 %I64d\n", ((long long)n*(n-1)*(n-2))/6);
	
	return 0;
}
