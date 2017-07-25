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

int t, n, l, r, a, b, c;
vector<pair<int, int> > g[100100];
int good[100100][51], gp[100100][51], inf = 1e8, up, down, mx, s[100100], order[100100], tp, e, v[100100], parent[100100], flag[100100], tp1, tp2, m[51];
bool ok;
pair<int, int> in[1000], out[1000];


void pre(){
	tp = 0, e = 0;
	s[tp++] = 1;
	parent[1] = -1;
	for(int i = 1; i <= n; i++) v[i] = 0;
		
	while(tp > 0){
		int u = s[tp-1]; --tp;
		if(v[u]) continue;
		v[u] = 1;
		order[e++] = u;
		foreach(it, g[u]){
			if(!v[it->fi]){
				s[tp++] = it->fi;
				parent[it->fi] = u;
			}
		}
	}
}

void dfs(int cur, int val){
	for(int i = e-1; i >= 0; i--){
		cur = order[i];
		for(int i = 1; i <= r; i++){
			good[cur][i] = -inf;
		}
		
		foreach(it, g[cur]){
			if(it->fi == parent[cur]){
				flag[cur] = (it->se <= val);
				continue;
			}
		
			int nflag = (it->se <= val);
			for(int i = 1; i <= r; i++){
				good[cur][i] = max(good[cur][i], good[it->fi][i-1] + nflag);
				if(2*good[cur][i] - i > 0 and i >= l) ok = true;
			}
		}
	
		if(parent[cur] != -1){
			for(int i = 1; i <= r; i++){
				gp[cur][i] = 2*(good[cur][i-1] + flag[cur]) - i;
			}
		}
	
		int cnt = 0;
	
		m[0] = -inf;
	
		foreach(it, g[cur]){
			if(it->fi == parent[cur]) continue;
		
			if(cnt == 0){
				for(int i = 1; i <= r; i++){
					m[i] = gp[it->fi][i];
				}
			}
			else{
				tp1 = 0; tp2 = 0;
				
				up = r, down = l;
			
				in[tp1++] = mp(m[up],m[up]);
				for(int i = up-1; i >= down; i--){
					in[tp1] = mp(max(m[i], in[tp1-1].fi), m[i]); ++tp1;
				}
			
				for(int i = 1; i <= r; i++){
					up--, down--;
					if(down >= 0){
						if(tp1 == 0) in[tp1++] = mp(m[down], m[down]);
						else{
							in[tp1] = mp(max(in[tp1-1].fi, m[down]), m[down]);
							tp1++;
						}
					}
					if(tp2 == 0){
						out[tp2++] = mp(in[tp1-1].se, in[tp1-1].se); tp1--;
						while(tp1 > 0){
							out[tp2] = mp(max(out[tp2-1].fi, in[tp1-1].se), in[tp1-1].se);
							--tp1;
							++tp2;
						}
					}
					
					if(tp2 > 0) --tp2;
				
					mx = -inf;
					if(tp1 > 0) mx = max(mx,in[tp1-1].fi);
					if(tp2 > 0) mx = max(mx, out[tp2-1].fi);
				
					if(mx + gp[it->fi][i] > 0) ok = true;
				}
			
				for(int i = 1; i <= r; i++){
					m[i] = max(m[i], gp[it->fi][i]);
				}
			}
			cnt++;
		}
	}
}

bool f(int val){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= r; j++){
			gp[i][j] = 0;
		}
	}
	ok = false;
	dfs(1, val);
	return ok;
}

vector<int> w;

int solve(){
	pre();
	int lo = 0, hi = n-2, mid;
	
	if(!f(w[hi])) return -1;
	
	while(lo < hi){
		mid  = (lo+hi)>>1;
		if(f(w[mid])) hi = mid;
		else lo = mid+1;
	}
	
	return w[hi];
}



int main(){
	sd(t);
	while(t--){
		sd3(n,l,r);
		for(int i = 1; i <= n; i++) g[i].clear();
		w.clear();
		for(int i = 1; i < n; i++){
			sd3(a,b,c);
			g[a].pb(mp(b,c));
			g[b].pb(mp(a,c));
			w.pb(c);
		}
		sort(w.begin(), w.end());
		printf("%d\n", solve());
	}
	return 0;
}
