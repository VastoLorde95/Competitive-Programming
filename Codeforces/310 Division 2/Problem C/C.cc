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

int n, k, m, x, cnt;
int sz[100100], s[100100], pos[100100], last[100100], open[100100];

int main(){
	sd2(n,k);
	for(int i = 1; i <= k; i++){
		sd(m);
		sz[i] = m;
		for(int j = 1; j <= m; j++){
			sd(x);
			s[x] = i; pos[x] = j;
			if(j == m) last[x] = 1;	
		}				
	}
	
	for(int  i = 1; i < n; i++){
		if(s[i+1] == s[i]){
			 if(open[s[i]] == 1) cnt++;
			 continue;
		}
		
		if(last[i] == 1 or open[s[i]] == 1){
			if(open[s[i+1]] > 0){
				cnt++;
			}
			else{
				open[s[i+1]] = 1;
				cnt += sz[s[i+1]]-pos[i+1];
				cnt++;
			}
		}
		else{
			open[s[i]] = 1;
			cnt += sz[s[i]]-pos[i];
			if(open[s[i+1]] > 0){
				cnt++;
			}
			else{
				open[s[i+1]] = 1;
				cnt += sz[s[i+1]]-pos[i+1];
				cnt++;
			}
		}
	}
	
	tr(cnt);
	
	return 0;
}
