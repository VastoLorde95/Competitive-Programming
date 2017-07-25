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

const int LOGN = 18;
const int N = 1 << LOGN;
const int M = 320;
const ll MOD = 1e9 + 7;

vector<int> g[N];
int n, m;

int p[LOGN][N], l[N];

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

int lft[N], rgt[N];
int tim;

void dfs(int cur, int prev){
	p[0][cur] = prev;
	lft[cur] = ++tim;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		l[*it] = l[cur] + 1;
		dfs(*it, cur);
	}
	rgt[cur] = tim;
}

void buildJumpTable(){
	for(int i = 1; i < LOGN; i++)
		for(int j = 1; j <= n; j++)
			p[i][j] = p[i-1][p[i-1][j]];
}

ll ma[2][2], ret[2][2], res[2][2];

void mul(ll a[][2], ll b[][2]){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			res[i][j] = 0;			
			for(int k = 0; k < 2; k++) res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
		}
	}
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			a[i][j] = res[i][j];

	return;
}

void fast(ll exponent){
	ret[0][0] = 1, ret[0][1] = 0;
	ret[1][0] = 0, ret[1][1] = 1;
	
	while(exponent > 0){
		if(exponent%2) mul(ret, ma);
		mul(ma, ma);
		exponent >>= 1;
	}
	
	for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) ma[i][j] = ret[i][j];
	return;
}

pair<ll,ll> fib(ll x){
	x--;
	if(x == 0) return mp(1, 0);
	if(x == 1) return mp(1, 1);
	ma[0][0] = 1, ma[0][1] = 1;
	ma[1][0] = 1, ma[1][1] = 0;
	fast(x);
	
	return mp(ma[0][0], ma[0][1]);
}

ll c[N];
ll f[N];

vector<pair<pair<ll, ll>, pair<ll, ll> > > buffer;

ll cost(int x){
	ll total = c[x];
//	tr(meta, x, total);
	int t = lft[x];
	foreach(it, buffer){
		int y = it->fi.fi;
		if(lft[y] <= t and t <= rgt[y]){
			ll d = l[x] - l[y];
			
			ll t1 = (it->se.fi * f[d+2]) % MOD;
			ll t2 = (it->se.se * f[d+1]) % MOD;
			ll t3 = (t1 + t2 - it->se.fi + MOD) % MOD;
			
			total += t3;
			if(total >= MOD) total -= MOD;
		}
	}
	return total;
}

vector<pair<ll, ll> > up[N];

void update(int cur, int prev, ll f1, ll f2, ll total){
	c[cur] += total;
	if(c[cur] >= MOD) c[cur] -= MOD;
	
	c[cur] += f1;
	if(c[cur] >= MOD) c[cur] -= MOD;
	
	total += f1;
	if(total >= MOD) total -= MOD;
	
	ll nf1 = (f1 + f2) % MOD, nf2 = f1;
	
	while(!up[cur].empty()){
		ll x1 = up[cur].back().fi;
		ll x2 = up[cur].back().se;
		up[cur].pop_back();
		
		c[cur] = (c[cur] + x2)%MOD;
		total = (total + x2)%MOD;
		
		nf1 += x1;
		if(nf1 >= MOD) nf1 -= MOD;
		nf2 += x2;
		if(nf2 >= MOD) nf2 -= MOD;
	}
	
	foreach(it, g[cur]){
		if(*it == prev) continue;
		update(*it, cur, nf1, nf2, total);
	}
}

int main(){
	f[1] = f[2] = 1;
	for(int i = 3; i < N; i++){
		f[i] = f[i-1] + f[i-2];
		if(f[i] >= MOD) f[i] -= MOD;
	}
	
	sd2(n,m);
		
	int pr;
	for(int i = 1; i < n; i++){
		sd(pr);
		g[i+1].pb(pr);
		g[pr].pb(i+1);
	}
	
	l[1] = 1;
	dfs(1,1);
	
	buildJumpTable();
	
	char ch; ll x, y;
	for(int i = 1; i <= m; i++){
		scanf(" %c %lld %lld", &ch, &x, &y);
		
		if(ch == 'U'){
			buffer.pb(mp(mp(x,y), fib(y+1)));
			if(buffer.size() == M){
				foreach(it, buffer){
					 
					up[it->fi.fi].pb(it->se);
				}
				update(1, 1, 0, 0, 0);
				buffer.clear();
			}
		}
		else{
			int lca = LCA(x, y);
			
			ll ans = cost(x) + cost(y);
			if(ans >= MOD) ans -= MOD;
			
			ans = (ans - cost(lca) + MOD) % MOD;
			if(lca != 1){
				ans = (ans - cost(p[0][lca]) + MOD) % MOD;
			}
			
			printf("%lld\n", ans);
		}
	}
	
	return 0;
}
