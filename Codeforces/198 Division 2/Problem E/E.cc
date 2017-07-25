#include <bits/stdc++.h>
#define sd(x) scanf("%d",&x)

using namespace std;

const int N = 5000;
typedef long long ll;

int n, p[N], u[N], v[N];
ll ans, MOD = 1e9 + 7, f[N], dp[N][N];

ll go(int x, int y){
	if(dp[x][y] > 0) return dp[x][y];
	if(x == 0 and y == 1) return 0;
	if(x < 0 or y < 0) return 0;
	
	return dp[x][y] = ((x*go(x,y-1))%MOD + ((y-1)*go(x+1,y-2))%MOD)%MOD;
}


int main(){
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (f[i-1]*i)%MOD;

	int x = 0, y = 0;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
		if(p[i] == -1) x++;
		else u[i] = v[p[i]] = 1;
	}
	
	for(int i = 1; i <= n; i++) if(u[i] == 0 and v[i] == 0) y++;
	
	x -= y;
	
	for(int i = 0; i <= n; i++){
		dp[i][0] = f[i];
		dp[i][1] = (dp[i][0]*i)%MOD;		
	}
	
	cout << go(x,y) << endl;	
			
	return 0;
}
