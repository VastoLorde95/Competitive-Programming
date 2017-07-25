#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 100100;
const int M = 33000;

vector<int> p;
bool isp[M];

ll fast(ll a, ll b, ll MOD){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

void pre(){
	for(int i = 1; i < M; i++) isp[i] = true;
	
	for(int i = 2; i < M; i++){
		if(!isp[i]) continue;
		
		for(ll j = 1ll*i*i; j < M; j += i) isp[j] = false;
		
		p.pb(i);
	}
}

const int K = 10;

ll g[N];
ll pwrs[N][K];

vector<int> f;

void get(int n, ll m){
	g[1] = 1;
	
	for(int i = 2; i <= n; i++){
		int num = i;
		
		for(int j = 0; j < f.size(); j++){
			pwrs[i][j] = 0;
			
			int x = f[j];
			int y = 0;
			
			while(num % x == 0){
				num /= x;
				y++;
			}
			
			pwrs[i][j] = pwrs[i-1][j] + y * i;
		}
		
		if(num == 1){
			g[i] = g[i-1];
			continue;
		}
		
		g[i] = g[i-1] * fast(num, i, m) % m;
	}
}

void solve(){
	ll n, m, q;
	scanf("%lld%lld%lld", &n,&m,&q);
	
	f.clear();
	
	ll phi = m;
	ll tmp = m;		
	for(int &x : p){
		if(tmp % x == 0){
			f.pb(x);
			phi -= phi / x;
			
			while(tmp % x == 0) tmp /= x;
		}
		if(tmp == 1) break;
		if(1ll * x * x > tmp) break;
	}
	if(tmp > 1){
		f.pb(tmp);
		phi -= phi / tmp;
	}
	
	get(n, m);
	
	int r;
	while(q--){
		sd(r);
		
		ll ans = (g[n] * fast(g[r], phi-1, m) % m) * fast(g[n-r], phi-1, m) % m;
		
		for(int j = 0; j < f.size(); j++){
			ll y = pwrs[n][j] - pwrs[r][j] - pwrs[n-r][j];
			if(!y) continue;
			ans = ans * fast(f[j], y, m) % m;
		}
		
		printf("%d\n", (int) ans);
	}
	
}

int main(){
	pre();

	int t;
	sd(t);
	
	while(t--) solve();
	
	return 0;
}
