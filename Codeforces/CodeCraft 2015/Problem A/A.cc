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
#define LET(x, a) __typeof(a) x(a)
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

typedef long long ll;

const int N = 1<<17;
const int M = 10100;

int n, m, u, v, l, x, y, root, num = -1, depth, type;

ll cnt[N], le[N];
vector<int> level[N], g[N];
vector<pair<int, int> > q;
pair<int, int> range[N];

void dfs(int cur, int dep){
	depth = max(depth, dep);
	level[dep].pb(++num);
	int tmp = num;
	foreach(it, g[cur]){
		dfs(*it, dep+1);
	}
	
	range[cur] = mp(tmp,num);
	return;
}

void propogate(int cur, int dep){
	ll tmp = 0;
	foreach(it, g[cur]){
		propogate(*it, dep+1);
		tmp += cnt[*it];
	}
	cnt[cur] = tmp + le[dep];
	return;
}

int main(){
	sd2(n,m);
	for(int i = 1; i < n; i++){
		sd2(u,v);
		g[u].pb(v);
	}
	
	dfs(1,0);
	
	for(int i = 0; i <= depth; i++){
		sort(level[i].begin(), level[i].end());
	}
	
	root = int(sqrt(m))+1;
	while(m--){
		sd(type);
		if(type == 1){
			sd2(l,y);
			q.pb(mp(l,y));
		}
		else{
			sd(x);
			ll ans = cnt[x];
//			tr5(x,ans,q.size(),range[x].fi, range[x].se);
			
			foreach(it, q){
				l = it->fi, y = it->se;
//				tr3("q",l,y);
				vector<int>::iterator it2 = upper_bound(level[l].begin(), level[l].end(), range[x].fi);
				if(it2 != level[l].begin()) it2--;
				
//				tr2("first search", *it2);
				
				int l1 = it2 - level[l].begin();
				it2 = upper_bound(level[l].begin(), level[l].end(), range[x].se);
				if(it2 != level[l].begin()) it2--;
				
//				tr2("second search", *it2);
				int l2 = it2 - level[l].begin();
				l = max(l2-l1+1,0);
				ans += (1LL * y) * l;
			}
			printf("%I64d\n", ans);
		}
		if(q.size() == root){
			memset(le, 0, sizeof le);
			foreach(it, q) le[it->fi] += it->se;
			
			propogate(1,0);
			
			q.clear();
		}
	}
	
	return 0;
}
