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

const ll MOD = 999998727899999ll;
const ll base = 31;
const int N = 100;

ll pw[N];
ll dp[N][N];

void solve(){
	string a, b;
	cin >> a >> b;
	
	int n = a.length();
	int m = b.length();
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		dp[i][0] = MOD;
		for(int j = 1; j <= i; j++){
			bool ok = true;
			for(int x = j, y = i; x < y; x++, y--){
				if(a[x-1] != a[y-1]) ok = false;
			}
			
			if(ok){
				dp[i][0] = min(dp[i][0], dp[j-1][0] + 1);
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		dp[0][i] = MOD;
		for(int j = 1; j <= i; j++){
			bool ok = true;
			for(int x = j, y = i; x < y; x++, y--){
				if(b[x-1] != b[y-1]) ok = false;
			}
			
			if(ok){
				dp[0][i] = min(dp[0][i], dp[0][j-1] + 1);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			
			dp[i][j] = MOD;
			
			ll f1 = 0, b1 = 0;
			
			for(int x = i; x > 0; x--){
				f1 = f1 + (pw[i-x] * a[x-1] % MOD);
				f1 %= MOD;
				
				b1 = ((b1 * base % MOD) + a[x-1]) % MOD;
				
				ll f2 = 0;
				ll b2 = 0;
				
				for(int y = j; y > 0; y--){
					f2 = f2 + (pw[j-y] * b[y-1] % MOD);
					f2 %= MOD;
				
					b2 = ((b2 * base % MOD) + b[y-1]) % MOD;
					
					if( ((f1 * pw[j-y+1] % MOD) + f2) % MOD == (((b2 * pw[i-x+1] % MOD) + b1) % MOD)) {
						dp[i][j] = min(dp[i][j], dp[x-1][y-1] + 1);
					}
					
					if(f1 == b1 and f2 == b2){
						dp[i][j] = min(dp[i][j], dp[x-1][y-1] + 2);
					}
					
					if(f1 == b1){
						dp[i][j] = min(dp[i][j], dp[x-1][j] + 1);
					}
					if(f2 == b2){
						dp[i][j] = min(dp[i][j], dp[i][y-1] + 1);
					}
				}
			}
			
//			tr(i, j, dp[i][j]);
			
		}
	}
	
	cout << dp[n][m] << endl;
	
}

int main(){ _
	pw[0] = 1;
	for(int i = 1; i < N; i++){
		pw[i] = pw[i-1] * base % MOD;
	}
	
	
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
