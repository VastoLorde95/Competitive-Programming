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

const int LOGN = 17;
const int N = 1<<LOGN;

int n, m, q;
int p[LOGN][N], l[N];
vector<int> ppl[LOGN][N];
vector<int> a[N];
vector<int> g[N];

void merge(vector<int> &v1, vector<int> &v2, vector<int> &v3){
	int up = min(10, (int)(v2.size() + v3.size()));
	v1.clear();
	int l = 0, r = 0, i = 0;
	while(i < up and l < v2.size() and r < v3.size()){
		if(v2[l] == v3[r]){
			v1.pb(v2[l]);
			l++, r++;
		}
		else if(v2[l] < v3[r]){
			v1.pb(v2[l++]);
		}
		else{
			v1.pb(v3[r++]);
		}
		i++;
	}
	while(i < up and l < v2.size()){
		v1.pb(v2[l++]);
		i++;
	}
	while(i < up and r < v3.size()){
		v1.pb(v3[r++]);
		i++;
	}
	return;
}

void query(){
	// TODO build level array, and jump table p[LOGN][N];
	int x, y, k; sd3(x,y,k);
	if(l[x] < l[y]) swap(x,y);
	vector<int> res;
	merge(res, a[x], a[y]);
	
	for(int i = LOGN-1; i >= 0; i--){
		if(p[i][x] != -1 and l[p[i][x]] >= l[y]){
			vector<int> tmp;
			merge(tmp, res, ppl[i][x]);
			res = tmp;
			
			x = p[i][x];
		}
	}
	
	if(x == y){
		k = min(k, (int) res.size());
		printf("%d ", k);
		for(int i = 0; i < k; i++){
			printf("%d ", res[i]);
		}
		puts("");
		return;
	}
	
	for(int i = LOGN-1; i >= 0; i--){
		if(p[i][x] != -1 and p[i][y] != -1 and p[i][x] != p[i][y]){
			vector<int> tmp;
			merge(tmp, res, ppl[i][x]);
			res = tmp;
			merge(tmp, res, ppl[i][y]);
			res = tmp;
			x = p[i][x], y = p[i][y];
		}
	}
	
	vector<int> tmp;
	merge(tmp, res, a[p[0][x]]);

	k = min(k, (int)tmp.size());
	printf("%d ", k);
	for(int i = 0; i < k; i++){
		printf("%d ", tmp[i]);
	}
	puts("");
	return;
}

void preprocess(){
	for(int j = 1; j < LOGN; j++)
		for(int i = 1; i <= n; i++)
			p[j][i] = p[j-1][p[j-1][i]];

	for(int i = 1; i <= n; i++) merge(ppl[0][i], a[i], a[p[0][i]]);
	for(int j = 1; j < LOGN; j++){
		for(int i = 1; i <= n; i++){
			merge(ppl[j][i], ppl[j-1][i], ppl[j-1][p[j-1][i]]);
		}
	}
	
	return;
}

void dfs(int cur, int prev, int d){
	p[0][cur] = prev;
	l[cur] = d;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		dfs(*it, cur, d+1);
	}
	return;
}

int main(){
	sd3(n,m,q);
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(int i = 1; i <= m; i++){
		int c; sd(c);
		if(a[c].size() < 10) a[c].pb(i);
	}
	
	dfs(1, -1, 0);
	preprocess();
	
	while(q--) query();
	
	return 0;
}
