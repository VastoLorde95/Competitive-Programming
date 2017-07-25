#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, k, d[100100], deg[100100], cur[100100], start = -1, cnt, mx;
vector<int> g[100100], s[100100];

int main(){
	sd2(n,k);
	for(int i = 1; i <= n; i++){
		sd(d[i]);
		if(!d[i]){
			start = i;
		}
		s[d[i]].pb(i);
		mx = max(mx, d[i]);
	}
	if(s[0].size() != 1){
		printf("-1\n"); return 0;
	}
		
	for(int i = 1; i <= mx; i++){
		if(s[i-1].empty()){
			puts("-1"); return 0;
		}
		
		for(int j = 0; j < s[i].size(); j++){
			if(deg[s[i-1][cur[i-1]]] == k){
				cur[i-1]++;
				if(cur[i-1] == s[i-1].size()){
					puts("-1"); return 0;
				}
			}
			
			g[s[i-1][cur[i-1]]].pb(s[i][j]);
			deg[s[i-1][cur[i-1]]]++;
			deg[s[i][j]]++;
			cnt++;
		}
	}
	
	printf("%d\n",cnt);
	
	for(int i = 1; i <= n; i++){
		foreach(it, g[i]){
			printf("%d %d\n", i, *it);
		}
	}
	
	return 0;
}
