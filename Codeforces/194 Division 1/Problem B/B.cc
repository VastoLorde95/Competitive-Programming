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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, g[1001][1001], r[1001], c[1001], u[1001], x, y, cnt, v;

int main(){
	sd2(n,m);
	
	for(int i = 0; i < m; i++){
		sd2(x,y);
		g[x][y] = 1;
	}
	
	for(int i = 2; i < n; i++){
		v = 0;
		for(int j = 1; j <= n; j++){
			v |= g[i][j];
		}
		r[i] = v;
	}
	
	
	for(int j = 2; j < n; j++){
		v = 0;
		for(int i = 1; i <= n; i++){
			v |= g[i][j];
		}
		c[j] = v;		
	}
	
	for(int j = 2; j < n; j++){
		if(!c[j]){
			u[j] = 1;
			cnt++;
		}
	}
	
	if(n > 3){
		for(int i = 2; i < n; i++){
			if(!r[i]){
				cnt++;
			}
		}
		if(n%2 == 1 and r[(n+1)/2] == 0 and c[(n+1)/2] == 0) cnt--;
	}
	
	cout << cnt << endl;
	
	return 0;
}
