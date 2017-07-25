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

int n, m;
int vv[200100], ok[200100], vis[200100], taken[200100], used[200100];
vector<int> c[200100], var[200100];
vector<pair<int, int> > g[200100];
int inf = 1e9;

bool match(int cur){
	bool ret = false;
	ok[cur] = 1;
	foreach(it, g[cur]){
		if(used[it->se]) continue;
		used[it->se] = 1;
		
		if(ok[it->fi]){
			taken[it->se] = cur;
			ret = true;
			break;
		}
		
		if(match(it->fi)){
			taken[it->se] = cur;
			ret = true;
			break;
		}
		
		taken[it->se] = it->fi;
	}
	return ret;
}

int main(){
	sd2(n,m);
	for(int i = 1; i <= m; i++) vv[i] = -1;
	for(int i = 1; i <= n; i++){
		ok[i] = 0;
		int k, x; sd(k);
		for(int j = 0; j < k; j++){
			sd(x);
			c[i].pb(x);
			if(x > 0) var[abs(x)].pb(i);
			else var[abs(x)].pb(-i);
		}
	}
	
	for(int i = 1; i <= m; i++){
		if(var[i].size() == 0){
			vv[i] = 0; continue;
		}
		if(var[i].size() == 1){
			vv[i] = (var[i][0] > 0)? 1: 0; 
			ok[abs(var[i][0])] = 1;
		}
		else{
			if(var[i][0] < 0 and var[i][1] < 0){
				vv[i] = 0;
				ok[abs(var[i][0])] = ok[abs(var[i][1])] = 1;
			}
			else if(var[i][0] > 0 and var[i][1] > 0){
				vv[i] = 1;
				ok[var[i][0]] = ok[var[i][1]] = 1;
			}
			else{
				int x = abs(var[i][0]), y = abs(var[i][1]);
				g[x].pb(mp(y,i));
				g[y].pb(mp(x,i));
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!ok[i]){
			if(!match(i)){
				puts("NO");
				return 0;
			}
		}
	}
	
	puts("YES");
	
	for(int i = 1; i <= m; i++){
		if(taken[i]){
			foreach(it, var[i]){
				if(abs(*it) == taken[i]){
					if(*it > 0) vv[i] = 1;
					else vv[i] = 0;
				}
			}
		}
		if(vv[i] == -1) vv[i] = 0;
		printf("%d", vv[i]);
	}
	
	printf("\n");
	
	
	
	
	return 0;
}

