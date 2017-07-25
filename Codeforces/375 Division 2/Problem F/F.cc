#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int N = 200100;
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

int n, m;
vector<pii> tmp, e;
vector<int> x;
vector<int> y;

void print(vector<pii> &tree){
	set<pii> s;
	foreach(edge, tree){
		s.insert(*edge);
	}
	tree.clear();
	foreach(it, s) tree.pb(*it);
	foreach(edge, tree){
		printf("%d %d\n", edge->fi, edge->se);
	}
}

int s, t, ds, dt;
map<int,int> f;
bool check(){
	set<int> ss, tt;
	for(auto &node : x) ss.insert(find(node));
	for(auto &node : y) tt.insert(find(node));
	
	foreach(it, ss) f[*it]++;
	foreach(it, tt) f[*it]++;
	
	int cnt1 = 0, cnt2 = 0;
	foreach(it, ss) if(f[*it] == 1) cnt1++;
	foreach(it, tt) if(f[*it] == 1) cnt2++;
	
	if(cnt1 > ds or cnt2 > dt) return false;
	return true;
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++) create(i);
	for(int i = 0; i < m; i++){
		int u, v; sd2(u,v); tmp.pb(mp(u,v));
	}
	
	sd2(s,t); sd2(ds,dt);
	
	bool conn = false;	
	for(int i = 0; i < m; i++){
		int u = tmp[i].fi, v = tmp[i].se;
		if(u == s and v == t) conn = true;
		else if(u == t and v == s) conn = true;
		else if(u == s) x.pb(v);
		else if(v == s) x.pb(u);
		else if(u == t) y.pb(v);
		else if(v == t) y.pb(u);
		else e.pb(mp(u,v));
	}
	
	vector<pii> tree;
	for(auto &edge : e){
		int x = edge.fi, y = edge.se;
		if(find(x) == find(y)) continue;
		merge(x,y); tree.pb(mp(x,y));
	}
	
	if(!check()){
		puts("No");
		return 0;
	}
	
	int degs = 0, degt = 0;
	
	set<int> bad1;
	foreach(it, x){
		int c = find(*it);
		if(c == find(s)){
			bad1.insert(*it);	
			continue;
		}
		
		if(f[c] > 1) continue;
		
		merge(*it, s);
		degs++;
		tree.pb(mp(s,*it));
		bad1.insert(*it);
	}

	set<int> bad2;
	foreach(it, y){
		int c = find(*it);
		if(c == find(t)){
			bad2.insert(*it);
			continue;
		}
		if(f[c] > 1) continue;
		
		merge(*it, t);
		degt++;
		tree.pb(mp(t,*it));
		bad2.insert(*it);
	}

	if(tree.size() == n-2){
		if(!conn){
			puts("No");
			return 0;
		}
		else if(degs == ds or degt == dt){
			puts("No");
			return 0;
		}
		
		tree.pb(mp(s,t));
		puts("Yes");
		print(tree);
		return 0;
	}
	
	foreach(it, x){
		if(degs == ds) break;
				
		if(bad1.count(*it)) continue;
		int c = find(*it);
		if(c == find(s)) continue;
		
		merge(c, s);
		tree.pb(mp(*it, s));
		
		++degs;
	}
	
	int spcl = find(s);
	bool used = false;
	foreach(it, y){
		if(degt == dt) break;
		
		if(bad2.count(*it)) continue;
		int c = find(*it);
		if(c == find(t)) continue;
		
		if(c == spcl and !used){
			tree.pb(mp(t,*it));
			++degt;
			used = true;
			merge(c, t);
			continue;
		}
		
		merge(c, t);

		tree.pb(mp(t, *it));
		++degt;
	}
	
	if(tree.size() < n-1){
		puts("No");
		return 0;
	}
	
	puts("Yes");
	print(tree);
	
	return 0;
}
