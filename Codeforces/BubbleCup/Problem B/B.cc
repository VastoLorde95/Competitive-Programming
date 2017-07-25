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

typedef pair<int, int> pii;
typedef long long ll;

const int LOGN = 17;

int n, k, stop, cur = 1, ind, x, y, lca;
int p[LOGN][1<<LOGN], l[1<<LOGN], v[1<<LOGN], step[1<<LOGN], p2[1001000];

vector<pii> g[1<<LOGN];
int b1[1<<LOGN], b2[1<<LOGN], degree[1<<LOGN];

map<pii, int> bad;

ll ans, MOD = 1e9 + 7;

void dfs(int cur, int prev, int depth){
	l[cur] = depth;
	p[0][cur] = prev;
	
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		dfs(it->fi, cur, depth+1);
	}
	
	return;
}

void jumpTable(){
	for(int j = 1; j < LOGN; j++){
		for(int i = 1; i <= n; i++){
			p[j][i] = p[j-1][p[j-1][i]];
		}
	}
	return;
}

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);
	
	
	int tmp = step[l[x]];
	
	for(int i = tmp; i >= 0; i--) 
		if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
	
	
	for(int i = tmp; i >= 0; i--){
		if(p[i][x] > 0 and p[i][x] != p[i][y]){
			x = p[i][x], y = p[i][y];
		}
	}
	return p[0][x];
}

void input(){
	sd(n);
	
	int a, b;
	for(int i = 1; i < n; i++){
		sd3(a,b,x);
		
		if(!x){
			g[a].pb(mp(b,1));
			g[b].pb(mp(a,1));
		}
		else{
			g[a].pb(mp(b,1));
			g[b].pb(mp(a,0));
			bad[mp(b,a)] = 0;
		}
		degree[a]++;
		degree[b]++;
	}
	
	step[1] = 0;
	for(int i = 2; i <= n; i++){
		step[i] = step[i-1];
		if((i&(i-1)) == 0) step[i]++;
	}
	
	p2[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		p2[i] = (p2[i-1]*2)%MOD;
	}
	
}

ll fast(int cnt){
	long long ret = 1;
	while(cnt > 0) ret = (ret*2)%MOD, cnt--;
	return ret;
}

int main(){
	input();
	
	dfs(1,1,0);
	
	jumpTable();
	
	sd(k);
	for(int i = 0; i < k; i++){
		sd(stop);
		if(stop == cur) continue;
		x = cur, y = stop;
		lca = LCA(x,y);
		
//		tr4("#",x,y,lca);
		
		if(lca == y){
			b1[x]++;
			b1[y]--;
		}
		else if(lca == x){
			b2[y]++;
			b2[x]--;
		}
		else{
			b1[x]++;
			b2[y]++;
			
			b1[lca]--;
			b2[lca]--;
		}
		
		cur = stop;
		
//		for(int j = 1; j <= n; j++){
//			tr3(j,b1[j],b2[j]);
//		}
	
		
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(degree[i] == 1){
			q.push(i);
			degree[i]--;
		}
	}
	
	while(!q.empty()){
		cur = q.front(); q.pop();
		if(v[cur]) continue;
		v[cur] = 1;
		
		x = p[0][cur];
		
		b1[x] += b1[cur];
		b2[x] += b2[cur];
		
		if(bad.count(mp(cur,x))) bad[mp(cur,x)] = b1[cur];
		if(bad.count(mp(x,cur))) bad[mp(x,cur)] = b2[cur];
		
		degree[x]--;
		if(degree[x] == 1) q.push(x);
			
	}

	foreach(it, bad){
		ans += p2[it->se]-1ll;
		if(ans >= MOD) ans -= MOD;
	}
	
	printf("%I64d\n", ans);
	return 0;
}
