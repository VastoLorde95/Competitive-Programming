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

int n, g[1001][1001], dp[1001][1001], a[1001][1001], b[1001][1001], p1[1001][1001], p2[1001][1001];
int zx, zy;
bool zero = false;

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sd(g[i][j]);
			int tmp = g[i][j];
						
			if(tmp == 0){
				zero = true;
				g[i][j] = 10;
				tmp = 10;
				zx = i, zy = j;
			}
			
			while(tmp%2 == 0) a[i][j]++, tmp /= 2;
			while(tmp%5 == 0) b[i][j]++, tmp /= 5;
		}
	}
	
	for(int i = 1; i <= n; i++){
		
		p1[1][i] = p2[1][i] = 1;
		p1[i][1] = p2[i][1] = 2;
		
		a[1][i] += a[1][i-1];
		b[1][i] += b[1][i-1];
		
		a[i][1] += a[i-1][1];
		b[i][1] += b[i-1][1];
		
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= n; j++){
			if(a[i][j-1] < a[i-1][j]){
				a[i][j] += a[i][j-1];
				p1[i][j] = 1;
			}
			else{
				a[i][j] += a[i-1][j];
				p1[i][j] = 2;
			}
			
			if(b[i][j-1] < b[i-1][j]){
				b[i][j] += b[i][j-1];
				p2[i][j] = 1;
			}
			else{
				b[i][j] += b[i-1][j];
				p2[i][j] = 2;
			}
		}
	}
	
	int ans = min(a[n][n], b[n][n]);
	
	if(zero and ans >= 1){
		printf("1\n");
		for(int i = 1; i < zx; i++) printf("D");
		for(int i = 1; i < zy; i++) printf("R");
		for(int i = zx; i < n; i++) printf("D");
		for(int i = zy; i < n; i++) printf("R");
		return 0;
	}
	else{
		string res;
		printf("%d\n", ans);
		if(a[n][n] < b[n][n]){
			for(int x = n, y = n; x > 1 or y > 1;){
				if(p1[x][y] == 1){
					res = 'R' + res; y--;
				}
				else{
					res = 'D' + res; x--;
				}
			}
		}
		else{
			for(int x = n, y = n; x > 1 or y > 1;){
				if(p2[x][y] == 1){
					res = 'R' + res; y--;
				}
				else{
					res = 'D' + res; x--;
				}
			}
		}
		printf("%s\n", res.c_str());
	}
	
	return 0;
}
