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

const int N = 200100;
const ll MOD = 1e9 + 7;

int n, k;
vector<pii> v;

set<int> c;
map<int, int> f;
int cnt;
int invf[4*N];

int r[4*N];

ll fact[4*N];

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll C(int n, int k){
	return (fact[n] * fast(fact[k], MOD-2) % MOD) * fast(fact[n-k], MOD-2) % MOD;
}

int main(){
	fact[0] = 1;
	for(int i = 1; i < 4*N; i++){
		fact[i] = fact[i-1] * i % MOD;
	}
	
	sd2(n,k);
	for(int i = 0; i < n; i++){
		int l, r; sd2(l,r);
		v.pb(mp(l,r));
		c.insert(l);
		c.insert(r);
		c.insert(r+1);
	}
	
	foreach(it, c){
		f[*it] = ++cnt;
		invf[cnt] = *it;
	}
	
	for(int i = 0; i < n; i++){
		v[i].fi = f[v[i].fi];
		v[i].se = f[v[i].se];
		
		r[v[i].fi]++;
		r[v[i].se+1]--;
	}
	
	for(int i = 1; i <= cnt; i++){
		r[i] += r[i-1];
	}
	
	ll ans = 0;
	for(int i = 1; i < cnt; i++){
		if(r[i] >= k){
			ans += C(r[i], k) * (invf[i+1] - invf[i]) % MOD;
			if(ans >= MOD) ans -= MOD;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
