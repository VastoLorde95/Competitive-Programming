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

const long double PI = 3.1415926535897932384626433832795;

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

const int N = 200100;

vector<pii> g[N];
int root[N];

vector<int> comp[N];
int v[N];
int t[N];
int a[N];

void dfs(int cur, int prev, int c){
	if(v[cur]) return;
	v[cur] = 1;
	
	comp[c].pb(cur);
	
	foreach(it, g[cur]){
		if(it->se == prev) continue;
		dfs(it->fi, it->se, c);
	}
}

int xx;
bool getCycle(int cur, int prev){
	if(v[cur]) return true;
	
	v[cur] = 1;
	foreach(it, g[cur]){
		if(it->se == prev) continue;
		if(getCycle(it->fi, it->se)){
			if(xx == -1) xx = cur;
			return true;
		}
	}
	
	return false;
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if(i != a[i]){
			g[a[i]].pb(mp(i,i));
			g[i].pb(mp(a[i],i));
		}
		else
			root[i] = 1;
	}
	
	int c = 0;
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			dfs(i,-1, c++);
		}
	}
	
	memset(v, 0, sizeof v);
	
	bool ok = false;
	int id = 0;
	int cnt = 0;
	
	for(int i = 0; i < c; i++){
		bool r = false;
		for(int j = 0; j < comp[i].size(); j++){
			int it = comp[i][j];
			if(root[it]){
				r = true;
				swap(comp[i][0], comp[i][j]);
				break;
			}
		}
		if(!r){
			xx = -1;
			getCycle(comp[i][0],-1);
			a[xx] = xx;
			swap(comp[i][0], xx);
		}
		else{
			ok = true;
			id = i;
		}
	}
	
	if(ok){
		swap(comp[0], comp[id]);
	}
	else{
		cnt++;
	}
	
	for(int i = 1; i < c; i++){
		cnt++;
		a[comp[i][0]] = comp[0][0];
	}

	printf("%d\n", cnt);	
	for(int i = 1; i <= n; i++){
		printf("%d ", a[i]);
	}
	puts("");
	
	return 0;
}
