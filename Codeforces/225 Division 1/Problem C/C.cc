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

const int MAXN = 200100;

int n, m, a[200100], f[200100], l[200100], d[200100];
vector<int> g[200100];

int tree[MAXN]; // Careful, indexing begins from 1.
int tree2[MAXN];

int query(int idx){
    int sum = 0;
    while(idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx < MAXN){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query2(int idx){
    int sum = 0;
    while(idx){
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update2(int idx, int val){
    while(idx < MAXN){
        tree2[idx] += val;
        idx += (idx & -idx);
    }
}

int cnt = 1;

void dfs(int cur, int prev, int dep){
	cnt++;
	f[cur] = cnt;
	d[cur] = dep;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		dfs(*it, cur, dep+1);
	}
	
	l[cur] = cnt;
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1,-1,0);
	
	for(int i = 1; i <= n; i++){
		if(d[i]%2){
			update(f[i]-1, a[i]);
			update(f[i], -a[i]);
		}
		else{
			update2(f[i]-1, a[i]);
			update2(f[i], -a[i]);
		}
	}
	
	int type, x, val;
	while(m--){
		sd(type);
		if(type == 1){		
			int x, val; sd2(x,val);
			if(d[x]%2){
				update(f[x]-1, val);
				update(l[x], -val);
				
				update2(f[x]-1, -val);
				update2(l[x], val);
			}
			
			else{
				update2(f[x]-1, val);
				update2(l[x], -val);
				
				update(f[x]-1, -val);
				update(l[x], val);
			}
		}
		else{
			int x, t; sd(x);
			if(d[x]%2)
				t = query(f[x]-1);
			else
				t = query2(f[x]-1);
			printf("%d\n", t);
		}
	}
	
	return 0;
}
