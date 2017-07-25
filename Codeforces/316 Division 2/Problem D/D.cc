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

int n, m, p, maxd, t, v, h;
char c[500100];
vector<int> g[500100];
vector<pair<int, int> > d[500100];
string s;
int f[500100], l[500100];

void dfs(int cur, int depth){
	f[cur] = ++t;
	d[depth].pb(mp(t, d[depth].back().se ^ (1<<(s[cur-1]-'a'))));
	
	foreach(it, g[cur]) dfs(*it, depth+1);
	
	l[cur] = ++t;
}

int main(){ _
	cin >> n >> m;
	for(int i = 2; i <= n; i++){
		cin >> p;
		g[p].pb(i);
	}
	
	for(int i = 1; i <= n; i++){
		d[i].resize(1);
	}
	
	cin >> s;
	
	dfs(1,1);
	
	while(m--){
		cin >> v >> h;
		int l1 = lower_bound(d[h].begin(), d[h].end(), mp(f[v], -1)) - d[h].begin() - 1;
		int l2 = lower_bound(d[h].begin(), d[h].end(), mp(l[v], -1)) - d[h].begin() - 1;
		int val = d[h][l1].se ^ d[h][l2].se;
		if(val == 0){
			cout << "Yes\n";
		}
		else if((val&(val-1)) == 0){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	
	
	return 0;
}
