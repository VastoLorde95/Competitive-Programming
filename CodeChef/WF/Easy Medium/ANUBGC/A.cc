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

const int N = 18;
const int M = 10;

ll dp[N][M][2][2][2];

vector<int> itov(ll x){
	vector<int> ret;
	while(x){
		ret.pb(x % 10);
		x /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void get(ll x){
	vector<int> v = itov(x);
	int n = v.size();
	
	for(int i = 0; i <= n; i++){
		memset(dp[i], 0, sizeof dp[i]);
	}
	
	for(int i = 0; i < M; i++){
		dp[0][i][1][0][0] = 1;
	}
	
	for(int i = 0; i < n; i++){
		for(int dig = 0; dig < M; dig++){
			for(int eq = 0; eq < 2; eq++){
				for(int has = 0; has < 2; has++){
					for(int nz = 0; nz < 2; nz++){
						ll val = dp[i][dig][eq][has][nz];
						if(!val) continue;
						
						int mnd = (eq)? v[i] : 9;
						
						for(int nd = 0; nd <= mnd; nd++){
							int neq = (eq and nd == v[i]);
							int nnz = (nz or nd > 0);
							int nhas = (has or (nd == dig and nnz));

							dp[i+1][dig][neq][nhas][nnz] += val;
						}
					}
				}
			}
		}
	}
	
	ll sum = 0;
	
	for(int dig = 0; dig < M; dig++){
		for(int eq = 0; eq < 2; eq++){
			sum += dp[n][dig][eq][1][1];
		}
	}
	
	x *= 10;
	
	ll g = __gcd(sum, x);
	sum /= g;
	x /= g;
	cout << sum << '/' << x << '\n';
	
}

void solve(){
	ll n;
	cin >> n;
	get(n);
}

int main(){ _
	int t;
	cin >> t;
	
	while(t--) solve();
		
	return 0;
}
