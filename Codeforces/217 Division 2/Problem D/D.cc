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

const int N = 2100;

int n, m;
char g[N][N];
int sum[N][N], tot;

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		scanf("%s", g[i]);
		for(int j = 0; j < m; j++){
			sum[i][j] = (g[i][j] == 'w');
			tot += (g[i][j] == 'w');
		}
	}
	
	for(int i = 0; i < n; i++)
		for(int j = 1; j < m; j++)
			sum[i][j] += sum[i][j-1];
	
	for(int j = 0; j < m; j++)
		for(int i = 1; i < n; i++)
			sum[i][j] += sum[i-1][j];
	
	int lx = 1e9, hx = 0, ly = 1e9, hy = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == 'w'){
				lx = min(lx, i);
				hx = max(hx, i);
				ly = min(ly, j);
				hy = max(hy, j);
			}
		}
	}	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == 'w'){
				if(i == lx or i == hx or j == ly or j == hy) continue;
				puts("-1"); return 0;
			}
		}
	}
	
	int x1 = hx-lx+1, y1 = hy-ly+1;
	int L = max(x1,y1);
	if(L > n or L > m){
		puts("-1"); return 0;
	}
	
	if(L > x1){
		lx = hx = -1;
		for(int i = 0; i+L-1 < n; i++){
			int t1 = sum[i+L-1][hy];
			int t2 = (ly-1 > 0)? sum[i+L-1][ly-1] : 0;
			int t3 = (i-1 > 0)? sum[i-1][hy] : 0;
			int t4 = (i-1 > 0 and ly-1 > 0)? sum[i-1][ly-1] : 0;
			if(t1-t2-t3+t4 == tot){
				t1 = sum[i+L-2][hy-1];
				t2 = sum[i+L-2][ly];
				t3 = sum[i][hy-1];
				t4 = sum[i][ly];
				if(t1-t2-t3+t4 == 0){
					lx = i, hx = i+L-1; break;
				}
			}
		}
		if(lx == -1){
			puts("-1"); return 0;
		}
	}
	else if(L > y1){
		ly = hy = -1;
		for(int i = 0; i+L-1 < m; i++){
			int t1 = sum[hx][i+L-1];
			int t2 = (i-1 > 0)? sum[hx][i-1] : 0;
			int t3 = (lx-1 > 0)? sum[lx-1][i+L-1] : 0;
			int t4 = (lx-1 > 0 and i-1 > 0)? sum[lx-1][i-1] : 0;
			if(t1-t2-t3+t4 == tot){
				t1 = sum[hx-1][i+L-2];
				t2 = sum[hx-1][i];
				t3 = sum[lx][i+L-2];
				t4 = sum[lx][i];
				if(t1-t2-t3+t4 == 0){
					ly = i, hy = i+L-1; break;
				}
			}
		}
		if(ly == -1){
			puts("-1"); return 0;
		}
	}
	
	
	for(int i = lx; i <= hx; i++){
		if(i == lx or i == hx){
			for(int j = ly; j <= hy; j++){
				if(g[i][j] != 'w') g[i][j] = '+';
			}
		}
		else{
			if(g[i][ly] != 'w') g[i][ly] = '+';
			if(g[i][hy] != 'w') g[i][hy] = '+';
		}
	}	
	
	for(int i = 0; i < n; i++){
		printf("%s\n", g[i]);
	}	
					
	return 0;
}
