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

int t, n, p;
int g[25][25];

int main(){
	sd(t);
	while(t--){
		sd2(n,p);
		memset(g, 0, sizeof g);
		for(int i = 1; i <= 5; i++){
			for(int j = 1; j <= 5; j++){
				g[i][j] = g[j][i] = 1;	
			}
			g[i][i] = 0;
		}
		
		
		for(int i = 6; i <= n; i++){
			int cnt = 0;
			for(int j = 1; j < i and cnt < 2; j++){
				if(g[i][j] == 0){
					g[i][j] = g[j][i] = 1;
					cnt++;
				}
			}
		}
		
		int cnt = 0;
		while(cnt < p){
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= n; k++){
					if(j != k  and g[j][k] == 0){
						g[j][k] = g[k][j] = 1;
						cnt++;			
						k = j = n+1;
					}
				}
			}
		}
		
		cnt = 2*n+p;
		for(int i = 1; i <= n and cnt > 0; i++){
			for(int j = i+1; j <= n and cnt > 0; j++){
				if(g[i][j] > 0){
					printf("%d %d\n", i, j);
					cnt--;
				}
			}
		}
	}
	return 0;
}
