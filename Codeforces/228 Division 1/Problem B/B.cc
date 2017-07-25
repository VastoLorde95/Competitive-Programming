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

int k, g[2001][2001], cur = 3, up;

int main(){
	sd(k);
	
	if(k == 1){
		printf("2\n");
		printf("NY\nYN\n");
		return 0;
	}
	
	for(int i = 30-1; i >= 0; i--){
		if((k&(1<<i)) > 0){
			up = i;
			int len = i;
			
			g[cur][1] = g[cur+1][1] = 1;
			g[1][cur] = g[1][cur+1] = 1;
			
			cur += 2;
			i--;
			
			while(i--){
				g[cur][cur-1] = g[cur][cur-2] = 1;
				g[cur+1][cur-1] = g[cur+1][cur-2] = 1;
				
				cur += 2;
			}
			g[cur][cur-1] = g[cur][cur-2] = 1;
			cur++;
			
			len = 30-len;
			len--;
			
			while(len--){
				g[cur][cur-1] = 1;
				cur++;
			}
						
			g[2][cur-1] = 1;
		}
	}
	
	for(int i = 0; i < up; i++){
		if((k&(1<<i)) > 0){
			if(i == 0){
				g[cur][1] = 1;
				cur++;
				int len = 30-1;
				while(len--){
					g[cur][cur-1] = 1;
					cur++;
				}
				g[2][cur-1] = 1;
			}
			else{
				int x = (2*(i+1));
				g[cur][x] = g[cur][x-1] = 1;
				cur++;
				int len = 30-i-1;
				while(len--){
					g[cur][cur-1] = 1;
					cur++;
				}
				g[2][cur-1] = 1;
			}
		}
	}
	
	printf("%d\n", cur-1);
	
	for(int i = 1; i < cur; i++){
		for(int j = 1; j < cur; j++){
			if(g[i][j]) g[j][i] = 1;
		}
	}
	
	for(int i = 1; i < cur; i++){
		for(int j = 1; j < cur; j++){
			if(g[i][j]) printf("Y"); else printf("N");
		}
		printf("\n");
	}
	
	return 0;
}
