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

int n, m, q, l[1002][1002], r[1002][1002], u[1002][1002], d[1002][1002], g[1002][1002], op, x, y;

int main(){
	sd3(n,m,q);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sd(g[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			l[i][j] = (g[i][j] == 1)? l[i][j-1]+1 : 0;
			u[i][j] = (g[i][j] == 1)? u[i-1][j]+1 : 0;
		}
	}	
	
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			r[i][j] = (g[i][j] == 1)? r[i][j+1]+1 : 0;
			d[i][j] = (g[i][j] == 1)? d[i+1][j]+1 : 0;
		}
	}
	
	
	while(q--){
		sd3(op,x,y);
		if(op == 1){
			g[x][y] ^= 1;
			
			for(int i = x; i <= n; i++) u[i][y] = (g[i][y] == 1)? u[i-1][y]+1 : 0;
			for(int i = x; i >= 1; i--)	d[i][y] = (g[i][y] == 1)? d[i+1][y]+1 : 0;
			for(int i = y; i <= m; i++)	l[x][i] = (g[x][i] == 1)? l[x][i-1]+1 : 0;
			for(int i = y; i >= 1; i--)	r[x][i] = (g[x][i] == 1)? r[x][i+1]+1 : 0;
		}
		else{
			if(g[x][y] == 0){
				printf("0\n"); continue;
			}
			
			int ans = 0;
			for(int ll = y, rr = y, cur = u[x][y];;){
				while(rr <= m and u[x][rr] >= cur) rr++;
				while(ll >= 1 and u[x][ll] >= cur) ll--;
				ans = max(ans, cur*(rr-ll-1));
				
				if(ll >= 1){
					if(rr <= m){
						if(u[x][ll] >= u[x][rr]) cur = u[x][ll];
						else cur = u[x][rr];
					}
					else cur = u[x][ll];
				}
				else{
					if(rr <= m) cur = u[x][rr];
					else break;
				}	
			}	
			
			
			for(int ll = y, rr = y, cur = d[x][y];;){
				while(rr <= m and d[x][rr] >= cur) rr++;
				while(ll >= 1 and d[x][ll] >= cur) ll--;
				ans = max(ans, cur*(rr-ll-1));
				
				if(ll >= 1){
					if(rr <= m){
						if(d[x][ll] >= d[x][rr]) cur = d[x][ll];
						else cur = d[x][rr];
					}
					else cur = d[x][ll];
				}
				else{
					if(rr <= m) cur = d[x][rr];
					else break;
				}	
			}
			
			for(int ll = x, rr = x, cur = l[x][y];;){
				while(rr <= n and l[rr][y] >= cur) rr++;
				while(ll >= 1 and l[ll][y] >= cur) ll--;
				ans = max(ans, cur*(rr-ll-1));
				
				if(ll >= 1){
					if(rr <= n){
						if(l[ll][y] >= l[rr][y]) cur = l[ll][y];
						else cur = l[rr][y];
					}
					else cur = l[ll][y];
				}
				else{
					if(rr <= n) cur = l[rr][y];
					else break;
				}	
			}
			
			
			
			for(int ll = x, rr = x, cur = r[x][y];;){
				while(rr <= n and r[rr][y] >= cur) rr++;
				while(ll >= 1 and r[ll][y] >= cur) ll--;
				ans = max(ans, cur*(rr-ll-1));
				
				if(ll >= 1){
					if(rr <= n){
						if(r[ll][y] >= r[rr][y]) cur = r[ll][y];
						else cur = r[rr][y];
					}
					else cur = r[ll][y];
				}
				else{
					if(rr <= n) cur = r[rr][y];
					else break;
				}	
			}
			
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
