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

using namespace std;

int n, b[4000], cur, dp[4000][4000], mx = 0;
map<int, int> t;
map<int, int> compress;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd(b[i]);		
		t[b[i]]++;
	}
	
	for(map<int, int>::iterator it = t.begin(); it != t.end(); it++){
		compress[it->first] = cur++;
		mx = max(mx, it->second);
	}
	
	for(int i = 0; i < n; i++){
		b[i] = compress[b[i]];
//		tr(b[i]);
	}
	
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(b[i] != b[j]){
				dp[b[i]][b[j]] = max(dp[b[i]][b[j]], dp[b[j]][b[i]] + 1);
				mx = max(mx, dp[b[i]][b[j]]);
//				tr3(i,j,dp[b[i]][b[j]]); 
			}
		}
	}
	
	printf("%d\n", mx);
	
	
	return 0;
}
