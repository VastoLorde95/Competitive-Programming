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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

int n, in[300300], out[300300];
vector<int> g[300300];
char s[4];
vector<int> v;
string res;

// we will either get a cycle or a single chain. If it is a chain, the recursion will end, else it will continue;
void dfs(int cur){
	while(!g[cur].empty()){
		int nxt = g[cur].back();
		g[cur].pop_back();
		dfs(nxt);
	}
	v.pb(cur);
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		int x = (int)(1000*s[0]) + (int)s[1];
		int y = (int)(1000*s[1]) + (int)s[2];
		g[x].pb(y);
		out[x]++;
		in[y]++;
	}
	
	
	int start = -1;
	for(int i = 0; i < 300300; i++){
		if(in[i]+1 == out[i]){
			if(start != -1){
				puts("NO"); return 0;
			}
			start = i;
		}
		else if(in[i] == out[i]);
		else if(in[i] == out[i]+1);
		else{
			puts("NO"); return 0;
		}
	}
	if(start == -1){
		for(int i = 0; i <= 300300; i++){
			if(out[i] > 0){
				start = i; break;	
			}
		}
	}
	
	dfs(start);
	reverse(v.begin(), v.end());
	
	if(v.size() != n+1){
		puts("NO"); return 0;	
	}
	
	res += (char)(v[0]/1000);
	
	foreach(it, v){
		res += (char)(*it%1000);
	}	
		
	printf("YES\n%s\n", res.c_str());
	
	return 0;
}
