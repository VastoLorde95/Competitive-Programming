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

int n, m, k, visit[100100], cnt;
long long d[100100];
bool train[100100];
vector<pair<int, pair<int, int> > > g[100100];

void sp(){
	priority_queue<pair<long long, int> > q;
	for(int i = 1; i <= n; i++) d[i] = 1e18, train[i] = false;
	int cur;
	d[1] = 0;
	q.push(mp(0,1));
	while(!q.empty()){
		pair<long long, int> p = q.top(); q.pop();
		cur = p.se;
		
		if(visit[cur] == 1) continue;
		
		visit[cur] = 1;
		foreach(it, g[cur]){
			int next = it->se.fi, w = it->se.se;
			if(visit[next] == 1) continue;
			
			
			long long ndis = d[cur] + w;
			
			if(ndis < d[next]){
				d[next] = ndis;
				if(it->fi == 1) train[next] = true;
				else train[next] = false;
			}
			if(ndis == d[next] and it->fi == 0) train[next] = false;
			
			q.push(mp(-d[next], next));
		}
	}
	
	for(int i = 1; i <= n; i++) if(train[i]) cnt++;
	
}

int main(){
	sd3(n,m,k);
	for(int i = 0; i < m; i++){
		int u, v, x;
		sd3(u,v,x);
		g[u].pb(mp(0,mp(v,x)));
		g[v].pb(mp(0,mp(u,x)));
	}
	for(int i = 0; i < k; i++){
		int s, y;
		sd2(s,y);
		g[1].pb(mp(1,mp(s,y)));
		g[s].pb(mp(1,mp(1,y)));
	}
	
	sp();
	
	printf("%d\n", k-cnt);
	
	return 0;
}
