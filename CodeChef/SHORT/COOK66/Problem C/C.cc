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
int M;

int n, m;
int f[2*N], MOD = 1e9 + 7;

vector<int> g[N];
int l[N], r[N], d[N], res[N], t;

void dfs(int cur, int dep){
	l[cur] = t++;
	d[cur] = dep;
	foreach(it, g[cur])	dfs(*it, dep+1);
	r[cur] = t;
	return;
}

vector<pair<int,int> > buf;
vector<int> q[N];

void propogate(int cur, int x, int y){
	foreach(it, q[cur]){
		int k = *it;
		x += f[k]; if(x >= MOD) x -= MOD;
		y += f[k-1]; if(y >= MOD) y -= MOD;
	}
	
	q[cur].clear();
	
	res[cur] += x;
	if(res[cur] >= MOD) res[cur] -= MOD;
	
	int next = x+y; if(next >= MOD) next -= MOD;
	
	foreach(it, g[cur]){
		propogate(*it, next, x);
	}
}

int main(){
	sd2(n,m);
	for(int i = 1; i < n; i++){
		int x; sd(x);
		g[x].pb(i+1);
	}
	
	dfs(1,0);
	
	f[1] = f[2] = 1;
	for(int i = 3; i < 2*N; i++){
		f[i] = f[i-1] + f[i-2];
		if(f[i] >= MOD) f[i] -= MOD;
	}
	
	M = sqrt(m);
	
	char c;
	for(int i = 0; i < m; i++){
		scanf(" %c", &c);
		if(c == 'U'){
			int x, k; sd2(x, k);
			buf.pb(mp(x,k));
			if(buf.size() == M){
				
				foreach(it, buf){
					x = it->fi, k = it->se;
					q[x].pb(k);
				}
				
				propogate(1, 0, 0);	
				
				buf.clear();
			}
		}
		else{
			int y; sd(y);
			int ans = res[y];
			foreach(it, buf){
				int x = it->fi, k = it->se;
				if(l[x] <= l[y] and l[y] < r[x]){
					ans += f[k+d[y]-d[x]];
					if(ans >= MOD) ans -= MOD;
				}
			}
			assert(ans >= 0 and ans < MOD); 
			printf("%d\n", ans);
		}
	}		
		
	return 0;
}
