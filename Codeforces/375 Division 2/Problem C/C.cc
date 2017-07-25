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

map<int, vector<int> > f;
map<int, int> g;
vector<int> a;
int n, m;

int main(){
	sd2(n,m);

	a.resize(n);
	for(int i = 0; i < n; i++){
		sd(a[i]), f[a[i]].pb(i);
	}
	
	int mx = n / m, cost = 0;
	
	vector<int> res(n);
	
	for(int i = 1; i <= m; i++){
		g[i] = mx;
		while(g[i] and !f[i].empty()) res[f[i].back()] = i, g[i]--; f[i].pop_back();
	}	
	
	auto it = f.begin();
	for(int i = 1; i <= m; i++){
		while(g[i]){
			if(it->se.empty()) it++;
			while(g[i] and it->se.size() > 0){
				res[it->se.back()] = i, g[i]--; (it->se).pop_back(), cost++;
			}
		}
	}
	
	while(it != f.end()){
		while(it->se.size() > 0) res[it->se.back()] = it->fi, it->se.pop_back();
		it++;
	}
	
	
	printf("%d %d\n", mx, cost);
	foreach(it, res) printf("%d ", *it);
	puts("");
	
	return 0;
}
