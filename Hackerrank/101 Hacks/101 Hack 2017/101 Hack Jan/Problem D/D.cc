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
const int M = 500;
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

ll n, a, b, q, c[N], F, B;
ll block[M];
ll pw[N];

void update(ll x, ll y){
	ll tot = 0;
	ll alph = a * F % MOD;
	ll mul = 1;
	for(int k = y, i = 0; k >= x; k--, i++){
		if(i % 2 == 0){
			tot += c[k] * mul % MOD;
			tot %= MOD;
		}
		else{
			tot -= c[k] * mul % MOD;
			tot += MOD;
			tot %= MOD;	
		}
		mul = mul * alph % MOD;
	}
	
	block[x / B] = tot;
}

int main(){ _
	cin >> n >> a >> b >> q;

	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	
	F = fast(b, MOD-2);
	
	ll alpha = a * F % MOD;
	
	pw[0] = 1;
	for(int i = 1; i <= n; i++){
		pw[i] = pw[i-1] * alpha % MOD;
	}
	
	B = 1 + int(sqrt(n));
	
	for(int i = 0; i < n; i++){
		int id = i / B;
		int j = (id + 1) * B - 1;
		j = min(1ll*j, n-1);
		
		update(i, j);
		i = j;
	}

	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
		if(t == 1){
			ll p, x;
			cin >> p >> x;
			c[p] = x;
			
			ll id = p / B;
			
			ll low = id * B;
			ll hi = min((id+1) * B - 1, 1ll * (n-1));
			
			update(low, hi);
		}
		else{
			ll l, r;
			cin >> l >> r;
			
			if(l == r){
				
				if(a == 0)
					cout << "Yes" << endl;
				else if(c[l] == 0){
					cout << "Yes" << endl;	
				}
				else{
					cout << "No" << endl;
				}
				continue;
			}
			
			if(l/B == (r-1)/B){
				ll tot = 0;
				ll alph = a * F % MOD;
				ll mul = 1;
				for(int k = r-1, ii = 0; k >= l; k--, ii++){
					if(ii % 2 == 0){
						tot += c[k] * mul % MOD;
						tot %= MOD;
					}
					else{
						tot -= c[k] * mul % MOD;
						tot += MOD;
						tot %= MOD;	
					}
					mul = mul * alph % MOD;
				}
				
				ll expected = c[r] * fast(a, MOD-2) % MOD;
				
				tot = tot * F % MOD;
				
				if(tot == expected){
					cout << "Yes" << endl;
				}
				else{
					cout << "No" << endl;
				}
			}
			else{
				ll tot = 0;
				ll alph = a * F % MOD;
				ll mul = 1;
				
				int ml = ((r-1) / B) * B;
				
				int ii = 0;
				for(int k = r-1; k >= ml; k--, ii++){
					if(ii % 2 == 0){
						tot += c[k] * mul % MOD;
						tot %= MOD;
					}
					else{
						tot -= c[k] * mul % MOD;
						tot += MOD;
						tot %= MOD;	
					}
					mul = mul * alph % MOD;
				}
				
				int rid = (r-1) / B;
				int lid = l / B;
				
				for(int j = rid-1; j > lid; j--){
					if(ii % 2 == 0){
						tot += block[j] * pw[ii-1] % MOD;
					}
					else{
						tot -= block[j] * pw[ii-1] % MOD;
						if(tot < 0) tot += MOD;
					}
					ii += B;
				}
				
				mul = pw[ii];
				for(int k = (lid+1) * B - 1; k >= l; k--, ii++){
					if(ii % 2 == 0){
						tot += c[k] * mul % MOD;
						tot %= MOD;
					}
					else{
						tot -= c[k] * mul % MOD;
						tot += MOD;
						tot %= MOD;	
					}
					mul = mul * alph % MOD;
				}
				
				ll expected = c[r] * fast(a, MOD-2) % MOD;

//				tr(alph, a * fast(b, MOD-2) % MOD);
//				tr(expected);
//				tr(tot);
				
				tot = tot * F % MOD;
				
				if(tot == expected){
					cout << "Yes" << endl;
				}
				else{
					cout << "No" << endl;
				}
				
				
			}
		}
	}		
	
	return 0;
}
