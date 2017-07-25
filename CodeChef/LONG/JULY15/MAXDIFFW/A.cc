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

int n, g[51][51], vi[51][51];

void solve(){
	int u, v, w, x, y, z, mx = 0;
	int start, nxt, up = min(n,15);
	
	srand(time(NULL));
	
	
	cout << start << " " << nxt << endl;
	vi[start][nxt] = 1;
	if(scanf("%d%d",&x, &y) != -1){
		vi[x][y] = 1;
		start = y;
	}

	while(true){
		nxt = -1;
		int mxx = -1000000;
		for(int i = 1; i <= n; i++){
			if(i == start) continue;
			if(vi[start][i] == 0){
				int mxx2 = 0;
				for(int j = 1; j <= n; j++){
					if(j == i) continue;
					if(vi[i][j] == 0 and g[i][j] > mxx2){
						mxx2 = g[i][j];
					}
				}
				if(g[start][i]-mxx2 > mxx){
					mxx = g[start][i]-mxx2;
					nxt = i;
				}
			}
			
		}
		if(nxt == -1) break;
		
		vi[start][nxt] = 1;
		cout << start << " " << nxt << endl;
		
		if(scanf("%d%d",&x, &y) != -1){
			vi[x][y] = 1;
			start = y;
		}
		else{
			break;
		}
	}
	
}

void solve2(){
	srand(time(NULL));
	
	int mx = 0, start = -1, nxt = 0, x, y;
	for(int i = 1; i <= n; i++){
		for(int jj = 1; jj <= n; jj++){
			int j  = (rand()%n) + 1;
			if(i == j) continue;
			int mx2 = 0;
			for(int k = 1; k <= n; k++){
				if(k == j) continue;
				for(int l = 1; l <= n; l++){
					int node = l;//(rand()%n)+1;
					if(node == k) continue;
					for(int m = 1; m <= n; m++){
						
						if(m == node) continue;
						mx2 = max(mx2, g[i][j] - g[j][k] + g[k][node] - g[node][m]);
					}
				}
			}
			if(mx2 > mx){
				mx = mx2;
				start = i, nxt = j;
			}
		}
	}	

	cout << start << " " << nxt << endl;
	vi[start][nxt] = 1;
	if(scanf("%d%d",&x, &y) != -1){
		vi[x][y] = 1;
		start = y;
	}

	while(true){
		nxt = -1;
		int mxx = -1000000;
		for(int i = 1; i <= n; i++){
			if(i == start) continue;
			if(vi[start][i] == 0){
				int mxx2 = 0;
				for(int j = 1; j <= n; j++){
					if(j == i) continue;
					if(vi[i][j] == 0 and g[i][j] > mxx2){
						mxx2 = g[i][j];
					}
				}
				if(g[start][i]-mxx2 > mxx){
					mxx = g[start][i]-mxx2;
					nxt = i;
				}
			}
			
		}
		if(nxt == -1) break;
		
		vi[start][nxt] = 1;
		cout << start << " " << nxt << endl;
		
		if(scanf("%d%d",&x, &y) != -1){
			vi[x][y] = 1;
			start = y;
		}
		else{
			break;
		}
	}
}

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sd(g[i][j]);
		}
	}
	
	solve();
	
	return 0;
}
