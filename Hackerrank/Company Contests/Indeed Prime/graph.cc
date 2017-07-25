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

int n, e, k;
vector<pair<int, int> > g[10001];
vector<pair<int, int> > s[10001];
int d[10001][1011];

void dfs(int cur, int prev, int l){
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		
        dfs(it->fi, cur, l);
        d[cur][l] = min(d[cur][l], d[it->fi][l] + it->se);
	}
    return;
}

void dfs2(int cur, int prev, int l){
    foreach(it, g[cur]){
		if(it->fi == prev) continue;
		
        d[it->fi][l] = min(d[it->fi][l], d[cur][l] + it->se);
        
        dfs(it->fi, cur, l);
	}
    return;
}

int main(){
	sd3(n,e,k);
	
    cout << n << endl;
    
	int a, b, w;
	for(int i = 1; i < n; i++){
		sd3(a,b,w);
		g[a].pb(mp(b,w));
		g[b].pb(mp(a,w));
	}
	for(int i = 0; i < e; i++){
		sd3(a,b,w);
		s[a].pb(mp(b,w));
		s[b].pb(mp(a,w));
	}
	
    for(int i = 0; i <= k; i++){
		for(int j = 1; j <= n; j++){
			d[j][i] = 1e9;
		}
	}
    
	for(int i = 1; i <= n; i++){
		if(g[i].size() <= 1){
			d[i][0] = 0;
		}
	}
	
	dfs(1, -1, 0);
    dfs2(1, -1, 0);
	
    for(int j = 1; j <= k; j++){
        for(int i = 1; i <= n; i++){
           d[i][j] = d[i][j-1];
           foreach(it, s[i]){
               d[i][j] = min(d[i][j], d[it->fi][j-1] + it->se);
           }
        }
     dfs(1, -1, 0);
     dfs2(1, -1, 0);
	}
	
    cout << n << endl;
    
    for(int i = 1; i <= n; i++){
        cout << d[i][k] << "\n";
    }
    
	return 0;
}
