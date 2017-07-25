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

const int N = 1001000;
int p[N], rnk[N];
int n, m;

void create(int x){
	p[x] = x, rnk[x] = 0;
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

int get(int x, int y){
	return (x - 1) * m + y;
}

vector<vector<int> > g;

int minrow[N];
int mincol[N];

map<int, pii> r[N];
map<int, pii> c[N];

vector<pii> groups[N];
int visited[N];

vector<pair<int, pii> > sorted;

int main(){
	sd2(n,m);
	
	g.resize(n+1);
	for(int i = 1; i <= n; i++){
		g[i].resize(m+1);
		for(int j = 1; j <= m; j++){
			sd(g[i][j]);
			create(get(i,j));
			
			sorted.pb(mp(g[i][j], mp(i, j)));
		}
	}
	
	sort(sorted.begin(), sorted.end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int num = g[i][j];
			if(!r[i].count(num)){
				r[i][num] = mp(i,j);
			}
			else{
				int x1 = r[i][num].fi, y1 = r[i][num].se;
				merge(get(i, j), get(x1, y1));
			}
		}
	}
	
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			int num = g[i][j];
			if(!c[j].count(num)){
				c[j][num] = mp(i,j);
			}
			else{
				int x1 = c[j][num].fi, y1 = c[j][num].se;
				merge(get(i, j), get(x1, y1));
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int id = find(get(i, j));
			groups[id].pb(mp(i,j));
		}
	}
	
	foreach(it, sorted){
		int x = it->se.fi, y = it->se.se;
		int id = find(get(x, y));
		
		if(visited[id]) continue;
		visited[id] = 1;
		
		int mx = 0;
		for(int i = 0; i < groups[id].size(); i++){
			x = groups[id][i].fi, y = groups[id][i].se;
			mx = max(mx, minrow[x]);
			mx = max(mx, mincol[y]);
		}
		
		mx++;
		for(int i = 0; i < groups[id].size(); i++){
			x = groups[id][i].fi, y = groups[id][i].se;
			g[x][y] = mx;
			minrow[x] = mx;
			mincol[y] = mx;
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
