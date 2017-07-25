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
#include <chrono>
#include <random>
#include <array>
 
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
 
int t, n, k, g[100][100];
pair<int, int> p[3000], f[3000], l[3000];

bool inrange(int x, int y){
	if(x >= 0 and x < n and y >= 0 and y < n) return true;
	return false;
}

long long bfs(int x, int y){
	long long score = 0;
	queue<pair<int, int> > q;
	q.push(mp(x,y));
	
	int cur = 1;
	
	memset(g, 0, sizeof g);	
	
	while(!q.empty() and cur <= k){
		pair<int, int> pr = q.front(); q.pop();
		x = pr.fi, y = pr.se;
		if(!inrange(x, y) or g[x][y] > 0) continue;
		
		g[x][y] = l[cur++].se;
		f[g[x][y]] = mp(x,y);
		
		q.push(mp(x+1,y));
		q.push(mp(x-1,y));
		q.push(mp(x,y+1));
		q.push(mp(x,y-1));
		
	}
	
	double a = 0, b = 0;
	int cnt, tmp;
	for(int i = 1; i <= k; i++){
		x = p[i].fi, y = p[i].se;
		a += (double) (abs(x-f[i].fi) + abs(y-f[i].se))/ (l[i].fi);
		tmp = 0, cnt = 0;
		if(inrange(x+1,y) and g[x+1][y] > 0) tmp += abs(l[g[x+1][y]].fi - l[i].fi), cnt++;
		if(inrange(x-1,y) and g[x-1][y] > 0) tmp += abs(l[g[x-1][y]].fi - l[i].fi), cnt++;
		if(inrange(x,y+1) and g[x][y+1] > 0) tmp += abs(l[g[x][y+1]].fi - l[i].fi), cnt++;
		if(inrange(x,y-1) and g[x][y-1] > 0) tmp += abs(l[g[x][y-1]].fi - l[i].fi), cnt++;
		
		if(cnt > 0)
			b += (double) (tmp/cnt);
	}
	
//	tr2(a,b);
	return (long long)(a*1000 + b*10);
}

int main(){
	sd(t);
	
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	
	while(t--){
		sd2(n,k);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				sd(g[i][j]);
				if(g[i][j] > 0){
					p[g[i][j]] = mp(i,j);
				}
			}			
		}
	
		for(int i = 1; i <= k; i++){
			sd(l[i].fi); l[i].se = i;
			l[i].fi *= -1;
		}
		
		shuffle(l+1, l+k+1, default_random_engine(seed));		
//		sort(l+1, l+k+1);
		
		int x = 0, y = 0;
		long long mn = 1e18;
		
		int up = min(n,40);
		
		for(int i = 0; i < up; i++){
			for(int j = 0; j < up; j++){
				long long tmp = bfs(i,j);
				if(tmp < mn){
					x = i, y = j, mn = tmp;
				}
			}
		}
		
		bfs(x,y);
//		tr(mn);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%d ", g[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
} 
