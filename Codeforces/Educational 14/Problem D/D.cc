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

const int N = 1001000;

int n, m;
int p[N];
vector<int> g[N];
vector<int> comp[N];

int v[N];
int ans[N];

void dfs(int cur, int id){
	if(v[cur]) return;
	v[cur] = 1;
	comp[id].pb(cur);
	foreach(it, g[cur]){
		dfs(*it, id);
	}
}

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
	}
	
	for(int i = 1; i <= m; i++){
		int a, b; sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			dfs(i, cnt);
			vector<int> t;
			foreach(it, comp[cnt]){
				t.pb(p[*it]);
			}
			sort(t.begin(), t.end(), greater<int>());
			sort(comp[cnt].begin(), comp[cnt].end());
			
			for(int j = 0; j < t.size(); j++){
				ans[comp[cnt][j]] = t[j];
			}
			
			cnt++;
		}
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	puts("");
	
	return 0;
}
