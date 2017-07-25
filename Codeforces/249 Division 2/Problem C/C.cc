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

char g[3002][3002];
int n, x, off = 1000;
pair<int, int> a[5000];

int main(){
	sd(n);
	
	for(int i = 0; i <= 3001; i++) for(int j = 0; j <= 3001; j++) g[i][j] = ' ';
	
	a[0].fi = a[0].se = 0;
	for(int i = 1; i <= n; i++){
		sd(x);
		a[i].fi = a[i-1].fi + x; 
		if(i%2 == 1) a[i].se = a[i-1].se + x; else a[i].se = a[i-1].se - x;
	}

	int mx = 0, mn = 5000;
	
	int j = a[0].se+off, k = a[0].fi;
	
	for(int i = 1; i <= n; i++){
		
//		tr2(j,k);
		
		if(a[i].se + off > j){
			j++;
			mx = max(mx, j); mn = min(mn, j);
			for(; j <= a[i].se+off; j++, k++){
				g[j][k] = '/';
			}
		}
		else{
			j--;
			mx = max(mx, j); mn = min(mn, j);
			for(; j > a[i].se+off; j--, k++){
				g[j][k] = '\\';
			}
		}
	}
	
	mx = max(mx, a[n].se+off); mn = min(mn, a[n].se+off);
	
	for(j = mx; j >= mn; j--){
		for(int i = 0; i < a[n].fi; i++){
			cout << g[j][i];
		}
		if(j != mn) cout << "\n";
	}
	
	return 0;
}
