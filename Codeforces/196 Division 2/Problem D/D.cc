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

int x, n, m, d, p[100100], f[100100], dis[100100], mx1[100100], mx2[100100], b1[100100], b2[100100], nearest[100100];
vector<int> g[100100];

int findP(int cur, int prev){
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		if(findP(*it, cur)){
			p[cur] = 1;
		}
	}
	return p[cur];
}

int calcMaxBranch(int cur, int prev){
	foreach(it, g[cur]){
		if(p[*it] != 1 or *it == prev) continue;
		
		int tmp = 1 + calcMaxBranch(*it, cur);
		if(tmp > mx1[cur]){
			mx2[cur] = mx1[cur]; b2[cur] = b1[cur];
			mx1[cur] = tmp; b1[cur] = *it;
		}
		else if (tmp > mx2[cur]){
			mx2[cur] = tmp; b2[cur] = *it;
		}
	}
	return mx1[cur];
}

void furthestInP(int cur, int prev, int l){	
	f[cur] = max(l, mx1[cur]);
	
	foreach(it, g[cur]){
		if(*it == prev or p[*it] != 1) continue;
		
		if(*it != b1[cur]) furthestInP(*it, cur, 1 + f[cur]);
		else 			   furthestInP(*it, cur, 1 + max(l, mx2[cur]));
	}
	return;
}

void distToP(int cur, int prev, int l, int near){
	dis[cur] = l;
	nearest[cur] = near;
	
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		if(p[*it] == 1) distToP(*it, cur, 0, *it);
		else distToP(*it, cur, 1+l, near);
	}
	return;
}

int main(){
	sd3(n,m,d);
	
	int last;
	
	for(int i = 0; i < m; i++){
		sd(x);
		p[x] = 1;
		last = x;
	}
	
	int u, v;
	
	x = last;
	
	for(int i = 1; i < n; i++){
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}	
	
	findP(x, -1);
	calcMaxBranch(x, -1);
	furthestInP(x, -1, 0);	
	distToP(x, -1, 0, x);

	int cnt = 0;
	
	for(int i = 1; i <= n; i++){
//		tr4(i, dis[i], nearest[i], f[nearest[i]]);
		if(dis[i] + f[nearest[i]] <= d) cnt++;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
