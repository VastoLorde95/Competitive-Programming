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

int dp[2][N];

inline void add(ll &x, ll y){
	x += y;
	if(x >= MOD) x -= MOD;
}

inline void sub(ll &x, ll y){
	x -= y;
	if(x < 0) x += MOD;
}

int main(){ _
	ll n, k, d;
	cin >> n >> k >> d;
	
	if((k*(k+1))/2 > n){
		cout << 0 << endl;
		return 0;
	}
	
	n -= (k * (k+1)) / 2;
	
	dp[0][0] = 1;
	int id = 0;
	
	for(int i = 1; i <= k; i++){
		id ^= 1;
		vector<ll> r(k, 0);
		for(int j = 0; j <= n; j++){
			add(r[j % i], dp[id^1][j]);
			if(j - i * d >= 0) sub(r[j % i], dp[id^1][j - i * d]);
			dp[id][j] = r[j % i];
		}
	}

	assert(0 <= dp[id][n] and dp[id][n] < MOD);
	
	cout << dp[id][n] << endl;
	
	return 0;
}
