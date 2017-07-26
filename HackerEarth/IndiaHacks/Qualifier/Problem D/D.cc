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
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 100100;

int n, m;
vector<int> g[N];
int active[N], ok[N], res[N], v[N], t[N], tim;

void dfs(int cur, int prev){
	active[cur] = 1, v[cur] = 1, t[cur] = tim++, ok[cur] = t[cur];
//	tr2(prev, cur);
	foreach(it, g[cur]){
		if(*it == cur) continue;
		if(v[*it]){
			if(active[*it]){
				res[cur] = 1;
				ok[cur] = min(ok[cur], t[*it]);
			}
			else{
				if(ok[*it] <= t[cur]){
					res[cur] = 1;
					ok[cur] = min(ok[cur], ok[*it]);
				}
			}
			continue;
		}
		
		dfs(*it, cur);
		
		if(ok[*it] <= t[cur]){
			ok[cur] = min(ok[cur], ok[*it]);
			res[cur] = 1;
		}
	}
	active[cur] = 0;
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
	}
	
	for(int i = 1; i <= n; i++){
		if(!v[i]) dfs(i, -1);
	}
	
	
	int tot = 0;
	for(int i = 1; i <= n; i++){
		printf("%d ", res[i]);
		tot += res[i];
	}
	
	puts("");
	
	return 0;
}
