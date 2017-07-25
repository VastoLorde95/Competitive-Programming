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

int n, t, a[101], inf = 1e9;
int g[101][101];

void mul(int a[][101], int b[][101]){
	int res[101][101];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			res[i][j] = -inf;			
			for(int k = 1; k <= n; k++){
				res[i][j] = max(res[i][j], a[i][k]+b[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = res[i][j];
		}
	}
}

int ret[101][101];
void fast(int x){
	while(x > 0){
		if(x%2) mul(ret, g);
		mul(g,g);
		x >>= 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = ret[i][j];
		}
	}
	return;
}


int main(){
	sd2(n,t);
	for(int i = 1; i <= n; i++) sd(a[i]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i] > a[j]){
				g[i][j] = -inf; continue;
			}
			
			g[i][j] = 1;
			for(int k = 1; k < j; k++)
				if(a[k] <= a[j]) g[i][j] = max(g[i][j], g[i][k]+1);
		}
	}
	
	fast(t);

	int res = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			res = max(res, g[i][j]);
		}
	}
	
	printf("%d\n", res);
	
	return 0;
}
