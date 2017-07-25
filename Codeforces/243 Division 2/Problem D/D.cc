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

int n, m, k;
int a[100][100], b[100], mn = 1000;

int calc(int row){
	int c1 = 0, c2 = 0, tot = 0;
	for(int i = 0; i < n; i++){	
		c1 = c2 = 0;
		for(int j = 0; j < m; j++){
			if(a[row][j] == a[i][j]) c1++; else c2++;
		}
		tot += m - max(c1,c2);
	}
	return tot;
}

int main(){
	sd3(n,m,k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			sd(a[i][j]);
		}
	}	
	
	if(n > k){
		for(int i = 0; i < n; i++){
			mn = min(mn, calc(i));
		}
	}
	else{
		for(int i = 0; i < (1<<n); i++){
			for(int j = 0; j < n; j++){
				if((i&(1<<j)) > 0){
					b[j] = 1;
				}
				else{
					b[j] = 0;
				}
			}	
			int tot = 0;
			for(int j = 0; j < m; j++){
				int c1 = 0, c2 = 0;
				for(int k = 0; k < n; k++){
					if(b[k] == a[k][j]) c1++; else c2++;
				}
				tot += n - max(c1,c2);
			}
			
			mn = min(mn, tot);
		}
	}
	
	if(mn <= k) cout << mn << "\n";
	else cout << -1 << "\n";
	return 0;
}
