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

int n, m, ans, grid[5001][5001], cnt[5001], tmp;
string s;

int main(){ _
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			if(s[j-1] == '1') grid[i][j] = grid[i][j-1] + 1;
		}
	}

	for(int  j = 1; j <= m; j++){
		tmp = 0;
		for(int i = 0; i <= j; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) cnt[grid[i][j]]++; // number of rows that have grid[i][j] number of continuous ones ending at column j
		for(int i = j; i >= 1; i--){
			tmp += cnt[i];
			ans = max(ans, tmp*i);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
