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

ll inv(ll x){
	return fast(x, MOD-2);
}

const int N = 1001000;

ll a[N];
ll b[N];
ll f[N];

ll get(ll x, ll d){
	return f[x+1] * inv((a[x+1] + b[x+1] * d) % MOD) % MOD;
}

void solve(){
	int t, l, r;
	ll d;
	cin >> t >> l >> r >> d;
	
	d %= MOD;
	
	if(t == 1){
		cout << get(r, d) * inv(get(l-1, d)) % MOD << endl;
	}
	else{
		int n = l, m = r;
		ll pr = 1;
		for(int i = 0; i <= m; i++){
			pr = (pr * get(n, d+i) % MOD);
			pr = (pr * inv(get(n-1, d+i)) % MOD);
		}
		cout << pr << endl;
	}
}

int main(){ _
	a[0] = 1, a[1] = 0;
	b[0] = 0, b[1] = 1;
	f[0] = f[1] = 1;
	for(int i = 2; i < N; i++){
		a[i] = a[i-2] * (i-1) + a[i-1];
		b[i] = b[i-2] * (i-1) + b[i-1];
		f[i] = f[i-1] * i % MOD;
		
//		tr(i, a[i], b[i]);
		
		a[i] %= MOD;
		b[i] %= MOD;
	}
	
	int q;
	cin >> q;
	
	while(q--) solve();
	
	return 0;
}
