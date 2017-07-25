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

ll n, a, b, q;
ll c[N];

int main(){ _
	cin >> n >> a >> b >> q;
	
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			ll i, x;
			cin >> i >> x;
			c[i] = x;
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
			
			ll want = c[r] * fast(a, MOD-2) % MOD;
			
			ll get = 0;
			ll mul = 1;
			ll alpha = a * fast(b, MOD-2) % MOD;
			
			for(int i = r-1, j = 0; i >= l; i--, j++){
				if(j%2 == 0){
					get += c[i] * mul % MOD;
					get %= MOD;
				}
				else{
					get -= c[i] * mul % MOD;
					get %= MOD;
					if(get < 0) get += MOD;
				}
				mul = mul * alpha % MOD;
			}
			
			get = get * fast(b, MOD-2) % MOD;


			assert(0 <= get and get < MOD);
			assert(0 <= want and want < MOD);
//			tr(get);
			
			if(get == want) cout << "Yes" << endl; else cout << "No" << endl;
		}
	}
	
	return 0;
}
