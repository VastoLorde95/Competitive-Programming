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

int n, d, x, y, inf = 1e9, g[101][101], a[101], dis[101], v[101];
vector<pair<int, int> > c;

int distt(int x, int y){
	x--, y--;
	return abs(c[x].fi-c[y].fi)+abs(c[x].se-c[y].se);
}

bool check(int val){
	for(int i = 2; i <= n; i++) dis[i] = -1;
	dis[1] = val;
	memset(v, 0, sizeof v);
	
	for(int i = 1; i < n; i++){
		int vertex, mx = -inf;
		
		for(int j = 1; j <= n; j++){
			if(v[j] == 0 and dis[j] > mx){
				mx = dis[j];
				vertex = j;
			}
		}
		
		if(vertex == n) break;
		
		v[vertex] = 1;
		
		for(int j = 1; j <= n; j++) dis[j] = max(dis[j], mx + g[vertex][j]);
	}
	
	if(dis[n] >= 0){
//		tr("here");
		return true;
	}
	return false;
	
}

int main(){	
	sd2(n,d);
	
	for(int i = 2; i <= n-1; i++){
		sd(a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		sd2(x,y);
		c.pb(mp(x,y));
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j){
				g[i][j] = -inf;
			}
			else{
				g[i][j] = a[i] - (d*distt(i,j));
			}
		}
	}
	
	int lo = 1, hi = inf, mid;
	
	while(lo <= hi){
//		tr2(lo,hi);
		mid = (lo+hi)/2;
		if(check(mid)) hi = mid-1;
		else lo = mid+1;			
	}
	
	printf("%d\n",lo);	
				
	return 0;
}
