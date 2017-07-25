#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 500500;

int p[N], rnk[N], size[N];

void create(int x){
	p[x] = x, rnk[x] = 0;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	if(rnk[px] > rnk[py]) p[py] = px;
	else p[px] = py;
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}


int n;
vector<int> g1[N], g2[N];
set<pii> s;

vector<pii> edges;
pii match[N];

void dfs1(int cur, int prev){
	foreach(it, g1[cur]){
		if(*it == prev) continue;
		
		if(find(cur) != find(*it)){
			edges.pb(mp(cur,*it));
		}
		
		dfs1(*it, cur);
	}
}

void dfs2(int cur, int prev){
	foreach(it, g2[cur]){
		if(*it == prev) continue;
		
		if(find(cur) != find(*it)){
			int id = find(*it);
			match[id] = mp(cur, *it);	
		}
		
		dfs2(*it, cur);
	}
}

/*
After compressing the tree, if we have an edge u-v, where u and v are some compressed co-ordinates of the original tree and
if v is a leaf, then if we delete the edge u-v, then only way that u-v remains connected in the new tree is if there exists some other
edge from v to some other node u'.

If we perform dfs1 and dfs2 from the same root node in both the new tree and the old tree, then it is guaranteed that we will enter component v via u' in dfs2 and the algo will ensure that u-v will get replace by u'-v

Moreover if we have some sequence of edges u-v-w in the compressed version of the original tree, then it is clear that there must also be some edge u'-v (where u' is in the same side as u or v) in the new tree else component v will be disconnected in the new tree. Once again since both traversals have used the same root, we will discover the edge u'-v from u' to v in the traversal.


*/

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++) create(i);
	
	int u, v;
	for(int i = 1; i < n; i++){
		sd2(u,v);
		if(u > v) swap(u,v);
		g1[u].pb(v);
		g1[v].pb(u);
		s.insert(mp(u,v));
	}
	
	for(int i = 1; i < n; i++){
		sd2(u,v);
		if(u > v) swap(u,v);
		g2[u].pb(v);
		g2[v].pb(u);
		if(s.count(mp(u,v))) merge(u, v);
	}

	dfs1(1, -1);
	dfs2(1, -1);
	
	printf("%d\n", (int) edges.size());
	// we traverse in the reverse order to go in the order of the leaf edges
	for(int i = (int) edges.size() - 1; i >= 0; i--){
		u = edges[i].fi, v = edges[i].se;
		int id = find(v);
		int u1 = match[id].fi, v1 = match[id].se;
		printf("%d %d %d %d\n", u, v, u1, v1);
	}
	
	return 0;
}
