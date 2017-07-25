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

int n, u, v;
int a[100100], c[100100];
bool leaf[100100];
long long mn[100100], d[100100], sum = 0;
vector<int> gr[100100];

bool flag = false;

void countChildren(int cur, int prev){
	foreach(i, gr[cur]){
		if(*i == prev) continue;
		c[cur]++;
		countChildren(*i, cur);
	}
	return;
}

void dfs(int cur, int prev){
	long long lcm = 1;
	
	d[cur] = 1, mn[cur] = 1e18;
	
	foreach(i, gr[cur]){
		if(*i == prev) continue;
		dfs(*i, cur);
		
		lcm = (lcm/__gcd(lcm,d[*i]))*d[*i];
		mn[cur] = min(mn[cur], mn[*i]);
	}
	
	foreach(i, gr[cur]){
		if(*i == prev) continue;
		
		if(lcm > mn[*i]){
			cout << sum << "\n"; exit(0);
		}
	}
	
	if(c[cur] == 0){
		d[cur] = 1; mn[cur] = a[cur];
		return;
	}
	
	d[cur] = lcm*c[cur];
	mn[cur] = (mn[cur]/lcm)*lcm*c[cur];
	
	return;
	
}
int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		sum += a[i];
	}
	
	for(int i = 1; i < n; i++){
		sd2(u,v);
		gr[u].pb(v);
		gr[v].pb(u);
	}
	
	countChildren(1,-1);
	dfs(1, -1);
	
	cout << sum - mn[1] << "\n";
	return 0;
}
