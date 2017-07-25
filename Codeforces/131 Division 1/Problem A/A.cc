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

int dp[200], k, x, n, c[200], tmp[200], in[200], mn = 1000000000;
vector<int> adj[200];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(c[i]);
		c[i]--;
	}
	
	for(int i = 0; i < n; i++){
		sd(k);
		tmp[i] = k;
		for(int j = 0; j < k; j++){
			sd(x);
			x--;
			adj[x].pb(i);
		}
	}
	
	for(int s = 0; s < 3; s++){
		stack<int> m[3];
		
		for(int i = 0; i < n; i++){
			in[i] = tmp[i];
			if(in[i] == 0){
				m[c[i]].push(i);
			}
		}
		
		if(m[s].empty()) continue;
		
		int cnt = 0, cur = s, part, moves = n-1;
		
		while(cnt < n){
			moves++;
			while(!m[cur].empty()){
				part = m[cur].top();
				m[cur].pop();
				cnt++;
				
				for(int i = 0; i < adj[part].size(); i++){
					in[adj[part][i]]--;
					if(in[adj[part][i]] == 0){
						m[c[adj[part][i]]].push(adj[part][i]);
					}
				}
			}
			cur = (cur+1)%3;
		}
		
		mn = min(mn, moves);
	}
	
	printf("%d\n", mn);
	
	return 0;
}
