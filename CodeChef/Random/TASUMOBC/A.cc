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

vector<int> itov(ll x){
	vector<int> ret;
	while(x){
		ret.pb(x % 3);
		x /= 3;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

const ll MOD = 1e9 + 7;
const int N = 40;
const int M = 3;

ll dp[N][M][2];

int C(int n, int k){
	if(n < k) return 0;
	if(k == 0 or k == n) return 1;
	if(k == 1) return n;
	if(k == 2) return (n*(n-1)) / 2;
}

ll get(ll x){
	vector<int> v = itov(x);
	int n = v.size();
	
	memset(dp, 0, sizeof dp);
	dp[0][1][1] = 1;
	for(int i = 0; i < n; i++){
		for(int rem = 1; rem < M; rem++){
			for(int eq = 0; eq < 2; eq++){
				ll val = dp[i][rem][eq];
				if(!val) continue;
				
				int mnd = (eq)? v[i] : 2;
				for(int nd = 0; nd <= mnd; nd++){
					int neq = (eq and nd == v[i]);
					int nrem = (rem * C(v[i], nd)) % 3;
					
					dp[i+1][nrem][neq] += val;
				}
			}
		}
	}

	ll res = 0;
	for(int eq = 0; eq < 2; eq++){
		for(int rem = 1; rem < M; rem++){
			res += dp[n][rem][eq] * rem % MOD;
			if(res >= MOD) res -= MOD;
		}
	}
	
	return res;
}

void solve(){
	ll n;
	cin >> n;
	cout << get(n) << '\n';
}

int main(){ _
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
