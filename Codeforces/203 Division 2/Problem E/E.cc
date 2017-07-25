#include <bits/stdc++.h>

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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 310;

int n, m, k;
int a[N], bad[N];
vector<pair<int,int> > e;

int main(){
	sd3(n,m,k);
	if(k == n){
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= k; i++){
		sd(a[i]);
		bad[a[i]] = 1;
	}
	
	vector<int> v;
	for(int i = 1; i <= n; i++) if(!bad[i]) v.pb(i);
	
	int r = v.size();	
	for(int i = 1; i <= n; i++) if(bad[i]) v.pb(i);
		
	swap(v[0], v[r]);

	// add all except k-1 edges
	// make the graph connected, this is the first priority
	for(int i = 0; i < n-1; i++) e.pb(mp(v[i], v[i+1]));
		
	// make the subgraph G - v[0] complete
	for(int i = 1; i < n; i++) for(int j = i+2; j < n; j++) e.pb(mp(v[i],v[j]));
	
	// only add those edges from v[0] such that there are no marked vertices
	// on the path between v[0] and any other marked vertex
	for(int i = 2; i <= r; i++) e.pb(mp(v[0], v[i]));
	
	if(e.size() < m){
		puts("-1");
		return 0;
	}
	
	// print the first m edges to ensure the graph is connected
	// if we can still print edges, we print those that do no affect the result
	// i.e. distance between v[0] and any other marked vertex is always >= 2 but Valera cannot compute it
	for(int i = 0; i < m; i++) printf("%d %d\n", e[i].fi, e[i].se);
	
	return 0;
}
