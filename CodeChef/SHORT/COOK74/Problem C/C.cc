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
const int N = 100100;

ll dp[N];
string s;

int main(){ _ 
	cin >> s;
	
	int n = s.length();
	
	if(n == 1){
		ll ans = 'Z' - s[0];
		cout << ans << endl;
		return 0;
	}
	
	for(int i = n-1; i >= 0; i--){
		dp[i] = 'Z' - s[i];
		dp[i] = (dp[i] + (dp[i+1] * 26) % MOD) % MOD;
	}	

//	for(int i = 0; i < n; i++){
//		tr(i, dp[i]);
//	}

	ll ans = 0;
	ll val = 0;
	
	for(int i = 0; i < n; i++){
		ans += dp[i+1] * ('Z' - s[i]) % MOD;
		if(ans >= MOD) ans -= MOD;
		
		ans += ('Z' - s[i]);
		if(ans >= MOD) ans -= MOD;
	}			
	
	assert(ans >= 0 and ans < MOD);
	cout << ans << endl;
	
	return 0;
}
