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

const int N = 51;
const int MOD = 1e9 + 7;

ll C[N][N];
ll f[N];

void pre(){
	f[0] = 1;
	for(int i = 1; i < N; i++){
		f[i] = f[i-1] * i % MOD;
	}
	
	C[0][0] = 1;
	for(int i = 1; i < N; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
	}
	
	ll ans = 0;
	
	int lim = min(k+1, n);
	for(int c = 1; c <= lim; c++){
		ans += ((C[n-1][c-1] * C[k][c] % MOD) * f[c] % MOD);
		ans %= MOD;
	}
	
	cout << ans << endl;
}

int main(){ _
	pre();
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
