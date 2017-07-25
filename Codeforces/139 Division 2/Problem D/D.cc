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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef pair<int,int> pii;

int n, m, p[9], x, y, d[16][16][1<<16], v[16][16][1<<16], inf = 1e9, mx, up;
char g[20][20];

pii pos[10];

int getdir(pii p1, pii p2){
	if(p1.fi == p2.fi-1) return 0;
	if(p1.fi == p2.fi+1) return 2;
	if(p1.se == p2.se-1) return 3;
	if(p1.se == p2.se+1) return 1;
}

bool good(int x, int y, int mask){
	if(x < 0 or x >= n or y < 0 or y >= m) return false;
	if(g[x][y] == '#') return false;
	if(v[x][y][mask]) return false;
	int xp = x, yp = y, x1, y1;
	
	for(int i = 2; i <= mx; i++){
		int num = (mask>>(2*i-4))&3;
		
		if(num == 0){
			x1 = xp-1, y1 = yp;
		}
		if(num == 1){
			x1 = xp, y1 = yp+1;
		}
		if(num == 2){
			x1 = xp+1, y1 = yp;
		}
		if(num == 3){
			x1 = xp, y1 = yp-1;
		}
		
		if(x1 == x and y1 == y) return false; 		
		xp = x1, yp = y1;
	}
	return true;
	
}


int opp(int num){
	if(num == 0) return 2;
	if(num == 1) return 3;
	if(num == 2) return 0;
	else return 1;
}

int main(){
	sd2(n,m);
	p[0] = 1;
	for(int i = 1; i < 9; i++){
		p[i] = p[i-1]*4;		
	}
	
	for(int i = 0; i < n; i++){
		scanf("%s", g[i]);
		for(int j = 0; j < m; j++){
			if('1' <= g[i][j] and g[i][j] <= '9'){
				int num = g[i][j]-'0';
				pos[num] = mp(i,j);
				mx = max(mx, num);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < (1<<(2*(mx-1))); k++){
				d[i][j][k] = inf;
			}
		}
	}
	
	up = (1<<(2*mx-2))-1;
	int mask = 0;	
	for(int i = 2; i <= mx; i++){
		mask |= ((getdir(pos[i], pos[i-1])<<(2*i-4)));
	}
	
	pii cur;
	
	x = pos[1].fi, y = pos[1].se;
	
	queue<pair<pii, int> > q;
	q.push(mp(mp(x,y),mask));
	
	d[x][y][mask] = 0;
	
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	int ans = inf;
	
	while(!q.empty()){
		cur = q.front().fi, mask = q.front().se; q.pop();
		x = cur.fi, y = cur.se;
		if(v[x][y][mask]) continue;
		v[x][y][mask] = 1;
		
//		tr4(x,y,mask, d[x][y][mask]);
		
		if(g[x][y] == '@'){
//			tr4(x,y,mask,d[x][y][mask]);
			ans = min(ans, d[x][y][mask]);
		}
		
		for(int i = 0; i < 4; i++){
			int x1 = x+dx[i], y1 = y+dy[i];
			int nmask = (mask<<2)|opp(i);
			nmask &= up;
//			int mmmm; cin >> mmmm;
			if(!good(x1, y1, nmask)) continue;
//			tr4(mask, nmask, x1, y1);
			d[x1][y1][nmask] = min(d[x1][y1][nmask], d[x][y][mask]+1);
			q.push(mp(mp(x1,y1),nmask));
		}	
	}
	
	if(ans == inf) puts("-1"); else printf("%d\n", ans);
	
	return 0;
}
