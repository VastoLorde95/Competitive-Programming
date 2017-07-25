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

typedef long double ld;

int n, m, k, indx, best, d[100100], od[100100], f[100100], lst[100100], v[100100];
vector<int> g[100100];
ld mn = 1e9;
priority_queue<pair<ld, int> > q;

int main(){
	sd3(n, m, k);
	for(int i = 0; i < k; i++){
		int fort; sd(fort);
		f[fort] = 1;
	}
	
	for(int i = 0; i < m; i++){
		int a, b; sd2(a,b);
		g[a].pb(b), g[b].pb(a);
		d[a]++, d[b]++;
		if(f[a]) od[b]++; if(f[b]) od[a]++;
	}
	
	for(int i = 1; i <= n; i++){
		if(!f[i]) q.push(mp((ld) od[i]/ (ld) d[i], i));
	}
	
	while(!q.empty()){
		pair<ld, int> p = q.top(); q.pop();
		ld tmp = (ld) od[p.se]/ (ld) d[p.se];
		
		if(tmp != p.fi or v[p.se]) continue;
		
		v[p.se] = 1;
		lst[indx++] = p.se;
		
		if(p.fi < mn) mn = p.fi, best = indx-1;
		
		foreach(it, g[p.se]){
			if(!f[*it] and !v[*it]){
				od[*it]++;
				q.push(mp((ld) od[*it]/ (ld) d[*it], *it));
			}	
		}
	}
	
	vector<int> res;
	for(int i = best; i < indx; i++) res.pb(lst[i]);
	
	printf("%d\n", (int) res.size());
	foreach(it, res) printf("%d ", *it);
	printf("\n");
	
	return 0;
}
