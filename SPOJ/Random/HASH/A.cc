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


// find the number of numbers of the AP modulo m in the range [0, L-1] or [-L+1, 0]
ll res(ll u, ll d, ll n, ll m, ll L, bool flag){
	if(L == 0) return 0;
	if(m == 1 or L >= m) return n+1;
	if(d == 0 or n == 0) return ((flag)? (!u or u >= m-L+1) : (u <= L-1)) * (n+1);
	
	ll k = 0;
	if(flag){
		k = (!u) + (u + n * d + m - 1) / m;
	}
	else{
		k = (u + n * d) / m + 1;
	}
	
	ll f1 = 0, fk = 0;
	if(flag){
		if(u == 0){ // if u == m, then this is the first first block
			f1 = 1;
		}
		else{		
			// u + x1 * d >= m - L + 1
			// u + x2 * d <= m
			ll x1 = max((m - L + 1 - u + d - 1) / d, 0ll);
			ll x2 = min((m - u) / d, n);
			f1 = max(x2 - x1 + 1, 0ll);
		}
		
		if(k >= 2){
			// u + c * d >= high - L + 1
			ll high = (u + n * d + m - 1) / m * m;
			ll c = max((high - L + 1 - u + d - 1) / d, 0ll);
//			ll c = (high - L + 1 - u + d - 1) / d;
			fk = max(n - c + 1, 0ll);
		}
	}
	else{
		if(u <= L-1)
			f1 = min((L-1 - u) / d, n) + 1;
		
		if(k >= 2){
			ll high2 = (u + n * d) / m * m;
			ll c1 = (high2 - u + d - 1) / d;
			ll c2 = min((high2 + L - 1 - u) / d, n);
			fk = max(c2 - c1 + 1, 0ll);
		}
	}
	
	if(k <= 2)
		return f1 + fk;
	if(d == 1)
		return f1 + fk + L * (k - 2);

	// r = nL, s = nd, t = q, 	
	ll nL = L % d, nd = m % d, nm = d, nn = k - 3, q = 0;
	if(flag){
		ll nu;
		if(u){
			nu = u + (2 * m - u) / d * d;
		}
		else{
			nu = u + (m - u) / d * d;
		}
		nu %= m;

		if(nu == 0) nu = m;
		nu = m - nu;
		
		if(nd <= d/2){
			q = res(nu % d, nd, nn, nm, nL, false);
		}
		else{
			q = res((d - (nu % d)), d - nd, nn, nm, nL, true);
		}
	}
	else{
		ll nu = u +  (m - u + d - 1) / d * d;
		nu %= m;
		
		if(d - nd <= d/2){
			q = res(nu % d, d - nd, nn, nm, nL, false);
		}
		else{
			q = res((d - (nu % d)), nd, nn, nm, nL, true);
		}
	}
	
	return f1 + fk + (L/d) * (k-2) + q;
}

void solve(){
	ll a, b, x, n, c, d, m;
	cin >> a >> b >> x >> n >> c >> d >> m;
	
	ll u = (a * x + b) % m;
	
	ll ans = res(u, a, n, m, d+1, false) - res(u, a, n, m, c, false);
	
	assert(0 <= ans and ans <= n+1);
	
	cout << ans << '\n';
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
