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

const ll MOD = 1e9 + 7;
const int N = 210;

ll dp[N][N];
int p[N];

void solve(){
	memset(dp, 0, sizeof dp);

	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}

	sort(p+1, p+n+1, greater<int>());
	
	dp[0][0] = 1;
	
	for(int i = 1; i <= n; i++){
		int z = i+1;
		while(z <= n and p[z] == p[z-1]) z++;
		
		int choice = z - i;
		
		ll p1 = 1, p2 = 1;
		for(int j = 1; j <= choice; j++){
			p1 = p1 * (i+j-2) % MOD;
			if(j > 1)
				p2 = p2 * (i + j - 2) % MOD;
		}
		
		z--;
		for(int j = 1; j <= k; j++){
			dp[z][j] = ((dp[i-1][j] * p1 % MOD) + ((dp[i-1][j-1] * choice % MOD) * p2 % MOD)) % MOD;
		}
		i = z;

	}
	
	ll ans = 0;
	for(int i = 1; i <= k; i++){
		ans += dp[n][i];
		if(ans >= MOD) ans -= MOD;
	}
	
	assert(0 <= ans < MOD);
	
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
