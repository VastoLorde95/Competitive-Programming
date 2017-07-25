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

const int N = 300100;
int p[N], rank[N], size[N], best[N];

int n, m, q, b1[N], b2[N], br1[N], br2[N], v[N];
vector<int> g[N];

void create(int x){
	p[x] = x;
	rank[x] = 0;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(rank[px] > rank[py]) p[py] = px;
	else p[px] = py;
	if(rank[px] == rank[py]) rank[py] = rank[py] + 1;
	return;
}

int dfs1(int c, int p){
	v[c] = 1;
	foreach(it, g[c]){
		if(*it == p) continue;
		
		int l = 1+dfs1(*it, c);
		if(l >= b1[c]){
			b1[c] = l;
			br1[c] = *it;
		}
		else if(l >= b2[c]){
			b2[c] = l;
			br2[c] = *it;
		}
	}
	return b1[c];
}

void dfs2(int c, int p, int l, int dad){
	b1[c] = max(b1[c], l);
	
	foreach(it, g[c]){
		if(*it == p) continue;
		
		if(*it == br1[c]){
			dfs2(*it, c, max(l, b2[c])+1, dad);
		}
		else{
			dfs2(*it, c, max(l, b1[c])+1, dad);
		}
	}
	
	best[dad] = max(best[dad], b1[c]+b2[c]);
	return;
}

int main(){
	sd3(n,m,q);
	int a, b;
	
	for(int i = 1; i <= n; i++) create(i);
		
	for(int i = 0; i < m; i++){
		sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);
		merge(a,b);
	}
	
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			dfs1(i, -1);
			dfs2(i, -1, 0, find(i));
		}
	}

	int t, x, y;
	
	while(q--){
		sd(t);
		if(t == 1){
			sd(x);
			printf("%d\n", best[find(x)]);
		}
		else{
			sd2(x,y);
			int u = find(x), v = find(y);
			if(u == v) continue;
			
			int nbest = max(1 + (best[u]+1)/2 + (best[v]+1)/2, max(best[u], best[v]));
			
			merge(x,y);
			best[find(x)] = nbest;
		}
	}
		
	
	return 0;
}
