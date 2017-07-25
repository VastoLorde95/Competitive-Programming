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

int n, p;
vector<int> g[200100];

long long MOD = 1000000007;
long long cnt[200100], res[200100];


long long inv(long long x){
	long long y = MOD-2, ret = 1;
	while(y){
		if(y%2) ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y >>= 1;
	}
	return ret;
}

void dfs(int cur, int prev){
	cnt[cur] = 1;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		dfs(*it, cur);
		cnt[cur] = (cnt[cur] * ((cnt[*it]+1LL)%MOD))%MOD;
	}
	return;
}

void dfs2(int cur, int prev, long long pro){
	res[cur] = (cnt[cur]*(pro+1))%MOD;
	
	vector<long long> pr1, pr2;
	
	foreach(it, g[cur]){
		if(*it == prev) continue;		
		pr1.pb(cnt[*it]+1);
		pr2.pb(cnt[*it]+1);
	}
	
	for(int i = 1, j = pr1.size(); i < pr1.size(); i++){
		pr1[i] = ((pr1[i]) * pr1[i-1])%MOD;
		pr2[j-i-1] = ((pr2[j-i-1]) * pr2[j-i])%MOD;
	}
	
	for(int i = 0, j = 0; i < g[cur].size(); i++){
		int v = g[cur][i];
		if(v == prev) continue;
		
		long long next = (pro+1)%MOD;
		
		if(j-1 >= 0) next = (next*pr1[j-1])%MOD;
		if(j+1 < pr2.size()) next = (next*pr2[j+1])%MOD;
		
//		tr(next);
		
		dfs2(v, cur, next);
		j++;
	}
	
	return;
}

int main(){
	sd(n);
	for(int i = 2; i <= n; i++){
		sd(p);
		g[i].pb(p);
		g[p].pb(i);
	}
	
	dfs(1, -1);
	dfs2(1, -1, 0);
	
	for(int i = 1; i <= n; i++){
		printf("%d ", (int) res[i]);
	}
	printf("\n");
	return 0;
}
