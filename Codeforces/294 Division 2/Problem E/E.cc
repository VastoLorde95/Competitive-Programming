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

const int LOGN = 17;
const int N = 1 << LOGN;

int n, m;
vector<int> g[N];

int p[LOGN][N], l[N];
int sz[N];

int beg[N], e[N], tme;
vector<pair<pii, int> > seg[N];

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);
	
	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) 
		if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];

	return p[0][x];
}

int getAncestorAtH(int x, int h){
	if(l[x] == h) return x;
	
	int del = l[x] - h, tmp = 0;
	while((1 << tmp) <= del) tmp++;
	tmp--;
	
	while(true){
		if(l[x] == h) return x;
		
		if(l[p[tmp][x]] >= h) x = p[tmp][x];
		tmp--;
	}
}

void dfs(int cur, int prev){
	beg[cur] = ++tme;
	
	sz[cur] = 1;
	p[0][cur] = prev;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		l[*it] = l[cur] + 1;
		dfs(*it, cur);
		sz[cur] += sz[*it];
		
		seg[cur].pb(mp(mp(beg[*it], e[*it]), *it));
	}
	
	sort(seg[cur].begin(), seg[cur].end());
	
	e[cur] = ++tme;
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		int u, v;
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1,1);
	
	for(int i = 1; i < LOGN; i++){
		for(int j = 1; j <= n; j++){
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}
	
	sd(m);
	while(m--){
		int x, y; sd2(x,y);
		
		if(x == y){
			printf("%d\n", n);
			continue;
		}
		
		int z = LCA(x,y);
		
		if(z == x or z == y){
			if(z == y) swap(x,y);
			
			int del = l[y] - l[x];
			if(del % 2){
				printf("0\n");
				continue;
			}
			
			del /= 2;
			
			int h = l[y] - del;
			z = getAncestorAtH(y, h);
			
			int i = lower_bound(seg[z].begin(), seg[z].end(), mp(mp(beg[y], (int)1e9), (int)1e9)) - seg[z].begin() - 1;
			printf("%d\n", sz[z] - sz[seg[z][i].se]);
			continue;
		}
		
		int del = l[x] - l[z] + l[y] - l[z];
		
		if(del % 2){
			printf("0\n");
			continue;
		}
		
		del /= 2;
		
		if(l[x] - del < l[z]) swap(x,y);
		
		int tmp = z;
		z = getAncestorAtH(x, l[x] - del);
		
		int i = lower_bound(seg[z].begin(), seg[z].end(), mp(mp(beg[x], (int)1e9), (int)1e9)) - seg[z].begin() - 1;
		int res = sz[z] - sz[seg[z][i].se];
		
		if(z == tmp){
			i = lower_bound(seg[z].begin(), seg[z].end(), mp(mp(beg[y], (int)1e9), (int)1e9)) - seg[z].begin() - 1;
			res -= sz[seg[z][i].se];
			res += n - sz[z];
		}
		printf("%d\n", res);
	}
	
	return 0;
}
