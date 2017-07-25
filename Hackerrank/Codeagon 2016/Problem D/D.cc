#include <bits/stdc++.h>

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

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 3001;

int T, n, m, x, y, r, t;

int g[N][N][2], inf = 1e9;
int d[N][2], v[N][2];


int go(int s, int dd){
	for(int i = 1; i <= n; i++){
		d[i][0] = d[i][1] = inf;
		v[i][1] = v[i][0] = 0;
	}
	
	d[s][0] = 0;
	
	priority_queue<pair<int, pair<int, int> > > q;
	q.push(mp(0, mp(0, s)));
	
	while(!q.empty()){
		pair<int, pair<int, int > > p = q.top(); q.pop();
		
		int cur = p.se.se;
		int taxi = -p.se.fi;
		
		if(v[cur][taxi]) continue;

		v[cur][taxi] = 1;
		
		for(int i = 1; i <= n; i++){
			if(i == cur) continue;
			if(cur == 2 and i == 4){
			}
			if((g[cur][i][0] == inf and g[cur][i][1] == inf)) continue;
			
			if(!v[i][0] and !taxi){
				int len = d[cur][taxi] + g[cur][i][0];
				if(len < d[i][0]){
					d[i][0] = len;
					q.push(mp(-d[i][0], mp(0, i)));
				}
			}
			
			if(!v[i][1]){
				if(taxi){
					int len = d[cur][taxi] + g[cur][i][0];
					
					if(len < d[i][1]){
						d[i][1] = len;
						q.push(mp(-d[i][1], mp(-1, i)));
					}
				}
				else{
					int len = d[cur][taxi] + g[cur][i][1];
					if(len < d[i][1]){
						d[i][1] = len;
						q.push(mp(-d[i][1], mp(-1, i)));
					}
				}
			}
		}
	}
	
	if(d[dd][0] == inf and d[dd][1] == inf) return -1;
	return min(d[dd][0], d[dd][1]);
	
}

int main(){
	sd(T);
	while(T--){
		sd2(n,m);
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				g[i][j][0] = g[i][j][1] = inf;
			}			
			g[i][i][0] = g[i][i][1] = 0;
		}
		
		for(int i = 0; i < m; i++){
			sd2(x,y);
			sd2(r,t);
			g[x][y][0] = g[y][x][0] = min(g[x][y][0], r);
			g[x][y][1] = g[y][x][1] = min(g[x][y][1], t);
		}
		
		int s, d;
		sd2(s,d);
		
		printf("%d\n", go(s,d));
	}		
	return 0;
}
