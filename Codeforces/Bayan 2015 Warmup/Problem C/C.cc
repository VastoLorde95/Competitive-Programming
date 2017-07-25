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

int n, m, cnt;
int g[1002][1002], up[1002][1002], lef[1002][1002], tot[1002][1002];
int x, y;
char s[1002];

bool ok = true;

int rect(int x1, int y1, int x2, int y2){
	return tot[x2][y2] - tot[x2][y1-1] - tot[x1-1][y2] + tot[x1-1][y1-1];
}

void go(int i, int j, int dir){
	if(rect(i-x+1, j-y+1, x, y) < x*y){
		return;
	}
	if(dir == 1)
		cnt -= x;
	else cnt -= y;
	
	if(g[x][y+1]) go(x,y+1,1);
	else if(g[x+1][y]) go(x+1,y,2);
	
	return;
}

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		for(int j = 1; j <= m; j++){
			g[i][j] = (s[j-1] == 'X');
			cnt += g[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
				up[i][j] = up[i-1][j] + 1;
				lef[i][j] = lef[i][j-1] + 1;
			}
			else{
				up[i][j] = 0;
				lef[i][j] = 0;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!g[i+1][j]) y = max(y, up[i][j]);
			if(!g[i][j-1]) x = max(x, lef[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			tot[i][j] = tot[i][j-1] + up[i][j];
		}
	}
	
	tr2(x,y);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
				if(rect(i,j,i+x-1,j+y-1) < x*y){
					printf("-1\n"); return 0;
				}
				
				cnt -= x*y;
				
				if(cnt == 0){
					printf("%d\n", x*y); return 0;
				}
				
				i = i+x-1;
				j = j+y-1;
				
				if(g[i][j+1]) go(i,j+1,1);
				if(g[i+1][j]) go(i+1,j,2);
				else{
					printf("-1\n"); return 0;	
				}
				
				if(cnt == 0){
					printf("%d\n", x*y);
				}
				else{
					printf("-1\n");
				}
				return 0;
			}
		}
	}
	
	return 0;
}
