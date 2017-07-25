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

const ll p = 1000003;

ll fast(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1) ret = ret * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret;
}

ll f[p];

ll getpow(ll x){
	ll pp = p, c = 0;
	
	while(pp <= x){
		c += x / pp;
		pp *= p;
	}
	
	return c;
}

ll getf(ll x){
	if(x <= 1) return 1;
	ll a = x / p;
	ll b = x % p;
	
	if(a&1) return (f[b] * getf(a) % p) * (p-1) % p;
	return f[b] * getf(a) % p;
}

ll solve(){
	ll n, l, r;
	cin >> n >> l >> r;
	
	ll t = r - l + 1;
	
	if(getpow(n+t) > getpow(t) + getpow(n)) return p-1;
	
	ll ans = getf(n+t);
	ans = ans * fast(getf(n), p-2) % p;
	ans = ans * fast(getf(t), p-2) % p;
	
	if(--ans < 0) ans += p;
	
	assert(0 <= ans < p);
	
	return ans;
}

int main(){
	f[0] = 1;
	for(int i = 1; i < p; i++) f[i] = f[i-1] * i % p;

	int t;
	cin >> t;
	while(t--) cout << solve() << endl;
	return 0;
}
