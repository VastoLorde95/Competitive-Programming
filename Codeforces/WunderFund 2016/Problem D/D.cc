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

const int N = 200100;

int n;
long long x, y;
vector<int> g[N];
vector<int> l;

int cnt = 0;

set<pair<int,int> > e;

void dfs1(int cur, int prev){
	int b = 0;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		b++;
		dfs1(*it, cur);
	}
	if(b > 0)
		cnt += b-1;
}

int main(){ _
	cin >> n >> x >> y;
	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		if(u > v) swap(u,v);
		e.insert(mp(u,v));
	}

	if(x < y){
		int start = 0;
		for(int i = 1; i <= n; i++){
			if(g[i].size() == 1){
				start = i;
				break;
			}
		}
		dfs1(start,-1);
		long long res = 0;
		
		res = y*cnt + x*(n-1-cnt);
		cout << res << endl;
	}
	else if(x == y){
		long long res = y*(n-1);
		cout << res << endl;
	}
	else{
		vector<int> v;
		for(int i = 0; i < n; i++){
			v.pb(i+1);
		}
		
		long long res = 1e18;
		long long best = y*(n-1);
		for(int i = 0; i < 80; i++){
			random_shuffle(v.begin(), v.end());
			int cnt = 0;
			for(int j = 1; j < n; j++){
				int x = v[i], y = v[i-1];
				if(x > y) swap(x,y);
				if(e.count(mp(x,y))) cnt++;
			}
			
			res = min(res, x*cnt + y*(n-cnt-1));
			if(res == best) break;
		}
		cout << res << endl;
	}
	
	return 0;
}
