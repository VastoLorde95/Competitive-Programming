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

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 500500;

int n, m;
vector<int> g[N];
vector<int> res[N];

int ok[N];

int p[N], rnk[N], size[N];

void create(int x){
	p[x] = x;
	rnk[x] = 0;
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

int main(){
	sd2(n,m);
	int u, v;
	for(int i = 0; i < m; i++){
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}

	set<int> s;
	for(int i = 1; i <= n; i++){
		ok[i] = 1;
		s.insert(i);
		create(i);
	}
	

	int cnt = 0;
	
	vector<int> tmp, err;
	for(int i = 1; i <= n; i++){
		if(ok[i]){
			tmp.clear();
			foreach(it, g[i]){
				if(s.count(*it)){
					tmp.pb(*it);
					s.erase(*it);
				}
			}
			
			err.clear();
			foreach(it, s){
				merge(i, *it);
				err.pb(*it);
				ok[*it] = 0;
			}
			cnt++;
			foreach(it, tmp) s.insert(*it);
			foreach(it, err) s.erase(*it);

			
			for(int i = 1; i < err.size(); i++){
				int u = err[i];
				tmp.clear();
				foreach(jt, g[u]){
					if(s.count(*jt)){
						tmp.pb(*jt);
						s.erase(*jt);
					}	
				}
				
				vector<int> next;
				foreach(jt, s){
					if(find(u) != find(*jt)){
						merge(u, *jt);
						next.pb(*jt);
						ok[*jt] = 0;
					}
				}
				
				err.insert(err.end(), next.begin(), next.end());
				
				foreach(jt, next) s.erase(*jt);
				foreach(jt, tmp) s.insert(*jt);
			}
			
		}
	}	
	
	for(int i = 1; i <= n; i++){
		res[find(i)].pb(i);
	}
	
	int tot = 0;
	for(int i = 1; i <= n; i++){
		if(res[i].size() > 0) tot++;
	}
	
	printf("%d\n", tot);
	for(int i = 1; i <= n; i++){
		if(res[i].size() > 0){
			printf("%d ", (int) res[i].size());
			foreach(it, res[i]) printf("%d ", *it);
			puts("");
		}
	}
	
	return 0;
}
