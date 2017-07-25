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

const int N = 300100;

int n, m, k;

set<pii> s;
set<int> unvisited;

void good(){
	puts("possible");
	exit(0);
}

void bad(){
	puts("impossible");
	exit(0);
}

void dfs(int x){
	vector<int> nxt;
	foreach(it, unvisited) if(!s.count(mp(x, *it))) nxt.pb(*it);
	foreach(it, nxt) unvisited.erase(*it);
	foreach(it, nxt) dfs(*it);
}

int main(){
	sd3(n,m,k);
	
	int u, v, deg = 0;
	for(int i = 0; i < m; i++){
		sd2(u,v);
		s.insert(mp(u,v));
		s.insert(mp(v,u));
		
		if(u == 1 or v == 1) deg++;
	}
	
	if(n - 1 - deg < k) bad();
	
	for(int i = 2; i <= n; i++) unvisited.insert(i);
	
	dfs(1);

	if(!unvisited.empty()) bad();
	
	for(int i = 2; i <= n; i++) unvisited.insert(i);
	
	int comp = 0;
	while(!unvisited.empty()){
		comp++;
		int x = *unvisited.begin();
		unvisited.erase(x);
		dfs(x);
	}
	
	if(comp > k) bad();
	
	good();
	
	return 0;
}
