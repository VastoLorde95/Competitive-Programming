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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, u, v;

int mx1[201], mx2[201], b1[201], b2[201];
int g[201][201];

int findleaf(int x){
	queue<int> s;
	
	int vi[201];
	memset(vi, 0, sizeof vi);
	
	s.push(x);
	
	while(!s.empty()){
		x = s.front();
		s.pop();
		
		vi[x] = 1;
		
		for(int i = 1; i <= n; i++){
			if(g[x][i] and !vi[i]){
				s.push(i);
			}
		}
	}
	
	return x;
}

int dfs(int cur, int prev){
	int tmp = 0;
	for(int i = 1; i <= n; i++){
		if(g[cur][i] and i != prev){
			tmp = max(tmp, 1+dfs(i,cur));
		}
	}
	return tmp;
}

int maxchain(int cur){
	return dfs(cur, -1);
}

int main(){
	sd(n);
	for(int i = 0; i < n-1; i++){
		sd2(u,v);
		g[u][v] = g[v][u] = 1;
	}	
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(g[i][j]){
				g[i][j] = 0, g[j][i] = 0;
				
				int l1 = maxchain(findleaf(i));
				int l2 = maxchain(findleaf(j));

				ans = max(ans, l1*l2);
				
				g[i][j] = 1, g[j][i] = 1;
			}
		}
	}
		
	cout << ans << "\n";
			
	return 0;
}
