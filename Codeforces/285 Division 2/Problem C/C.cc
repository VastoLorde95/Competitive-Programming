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

int n, m;
int d[1<<17], x[1<<17];

vector<int> g[1<<17];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(d[i], x[i]);
	}
	
	queue<int> q;
	
	for(int i = 0; i < n; i++){
		if(d[i] == 1){
			q.push(i);
		}
	}	
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		
		if(d[cur] <= 0) continue;
				
		g[cur].pb(x[cur]);
		
		m++;
		
		d[cur]--;
		d[x[cur]]--;
		
		x[x[cur]] ^= cur;
		
		if(d[x[cur]] == 1){
			q.push(x[cur]);
		}
	}
	
	printf("%d\n", m);
	
	for(int i = 0; i < n; i++){
		foreach(it, g[i]) printf("%d %d\n", i, *it);
	}
			
	return 0;
}
