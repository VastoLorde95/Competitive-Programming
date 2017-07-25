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
const ll MOD = 1e9 + 7;

ll fast(ll a, ll b){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int n;
int a[N];

inline void add(ll &x, ll y){
	x += y;
	if(x >= MOD) x -= MOD;
}

ll y = fast(2, MOD-2);

void solve(){
	sd(n);
	
	for(int i = 0; i <= n; i++){
		cin >> a[i];
	}
	
	ll x = fast(2, n);
	
	ll sum = (x * a[1] % MOD) * a[0] % MOD;
	ll cur = (x * a[0] % MOD) % MOD;
	
	for(int i = 2; i <= n; i++){
		add(cur, x * a[i-1] % MOD);
		cur = cur * y % MOD;
		add(sum, cur * a[i] % MOD);
	}
	printf("%d\n", (int) sum);
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
