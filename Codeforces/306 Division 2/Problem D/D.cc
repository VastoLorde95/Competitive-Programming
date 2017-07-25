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

int k, g[205][205], d[205];

int main(){
	sd(k);
	if(k%2 == 0){
		puts("NO"); return 0;
	}
	
	puts("YES");
	
	if(k == 1){
		cout << "2 1\n1 2\n"; return 0;
	}
	
	g[k][2*k] = g[2*k][k] = 1;
	
	g[2*k+1][2*k+2] = g[2*k+2][2*k+1] = 1;
	g[2*k+3][2*k+4] = g[2*k+4][2*k+3] = 1;
	
	int cnt = 3;
	
	for(int i = 1; i < k; i++){
		g[i][k] = g[k][i] = 1;
		g[i+k][2*k] = g[2*k][i+k] = 1;
		
		g[i][2*k+1] = g[2*k+1][i] = 1;
		g[i][2*k+2] = g[2*k+2][i] = 1;
		
		g[i+k][2*k+3] = g[2*k+3][i+k] = 1;
		g[i+k][2*k+4] = g[2*k+4][i+k] = 1;
		
		cnt += 6;
	}
	

	for(int i = 1; i < k; i++){
		for(int j = i+1; j < k; j++){
			g[i][j] = g[j][i] = 1;
			cnt++;
		}
		for(int j = i+1; j < k; j++){
			g[i+k][j+k] = g[j+k][i+k] = 1;
			cnt++;
		}
	}
	
	for(int i = 1; i < k; i += 2){
		g[i][i+1] = g[i+1][i] = 0;
		cnt--;
		g[i+k][i+k+1] = g[i+k+1][i+k] = 0;
		cnt--;
	}
	
	cout << 2*k + 4 << " " << cnt << endl;
	
	for(int i = 1; i <= 2*k + 4; i++){
		for(int j = i+1; j <= 2*k + 4; j++){
			if(g[i][j] > 0){
				cout << i << " " << j << endl;
			}
		}
	}
	
	return 0;
}
