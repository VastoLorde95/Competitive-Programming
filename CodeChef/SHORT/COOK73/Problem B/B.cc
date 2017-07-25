#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const ll MOD = 1e9 + 7;
const int N = 100100;

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b&1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll f[N], invf[N];

const int LOGN = 17;
int n, sp[LOGN][1<<LOGN], k[1<<LOGN], o[1<<LOGN];

void pre(){
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = f[i-1] * i % MOD;
	invf[N-1] = fast(f[N-1], MOD-2);
	for(int i = N-2; i >= 0; i--) invf[i] = invf[i+1] * (i+1) % MOD;
	
	for(int i = 2; i < N; i++){
		k[i] = k[i-1] + ((i&(i-1)) == 0);
		if(k[i] == k[i-1]) o[i] = o[i-1];
		else o[i] = ((o[i-1]+1)<<1)-1;
	}
}

ll C(int n, int k){
	return (f[n] * invf[k] % MOD) * invf[n-k] % MOD;	
}

vector<int> g[N];
int sz[N];

ll ans;

void dfs(int x){
	if(x == 0) sz[x] = 0; else sz[x] = 1;
	
	vector<int> v;
	foreach(it, g[x]){
		dfs(*it);
		sz[x] += sz[*it];
		v.pb(sz[*it]);
	}
	
	if(v.empty()) return;
	
	int tot = v.back();
	for(int i = (int)(v.size()) - 2; i >= 0; i--){
		ans = ans * C(tot + v[i] - 1, v[i] - 1) % MOD;
		tot += v[i];
	}
}

void sparseTable(){
	for(int j = 1; j < LOGN; j++){
		for(int i = 1; (i+(1<<j)-1) <= n; i++){
			sp[j][i] = max(sp[j-1][i], sp[j-1][i+(1<<(j-1))]);
		}
	}
	return;
}

int rmq(int x, int y){
	if(y < x) return 0;
	int l = y-x+1;
	return max(sp[k[l]][x], sp[k[l]][y-o[l]]);
}

int c[N];

void solve(){
	sd(n);
	
	for(int i = 0; i <= n; i++) g[i].clear();
	
	bool ok = true;
	
	for(int i = 1; i <= n; i++){
		sd(c[i]);
		if(i+c[i]+1 > n) g[0].pb(i); else g[i+c[i]+1].pb(i);
		if(i+c[i]+1 > n+1) ok = false;
		sp[0][i] = i+c[i]+1;
	}
	
	if(!ok){
		printf("0\n"); return;
	}

	sparseTable();
	
	for(int i = 1; i <= n; i++){
		int x = i+1, y = sp[0][i] - 1;
		if(rmq(x, y) > sp[0][i]){
			ok = false;
		}
	}
	
	if(!ok){
		printf("0\n"); return;
	}
	
	ans = 1;
	
	dfs(0);
	
	printf("%lld\n", ans);
}

int main(){
	pre();

	int t;
	sd(t);
	while(t--) solve();
	
	return 0;
}
