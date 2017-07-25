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

const int N = 100100;

int n, c[N], res, l1[N], l2[N];
vector<int> g[N];

void dfs(int cur, int prev){
	l1[cur] += c[cur];
	bool leaf = true;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		dfs(*it, cur);
		leaf = false;
		if(c[*it] and c[cur]){
			if(1+l1[*it] >= l1[cur]){
				l2[cur] = l1[cur];
				l1[cur] = 1+l1[*it];
			}
			else if(1+l1[*it] > l2[cur]){
				l2[cur] = 1+l1[*it];
			}
		}
		
	}
	
	if(c[cur] > 0)
		res = max(res, l1[cur]+l2[cur]-((leaf)? 0: 1));
		
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(c[i]);
	}
	
	int x;
	for(int i = 1; i < n; i++){
		sd(x);
		g[i+1].pb(x);
		g[x].pb(i+1);
	}
	
	dfs(1,-1);
	
	printf("%d\n", res);
	
	return 0;
}
