#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int M = 21;
const ll MOD = 1e9 + 9;
const int N = 100100;

ll fast(ll a, ll b){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll cube(int n){
	return ((fast(n,2)*8 + fast(n,3)*12 + fast(n,4)*3 + fast(n,6)) % MOD) * fast(24,MOD-2) % MOD;
}

ll tetrahedron(int n){
	return ((fast(n,2)*11 + fast(n,4)) % MOD) * fast(12,MOD-2) % MOD;
}

ll octahedron(int n){
	return ((fast(n,2)*6 + fast(n,4)*17 + fast(n,8)) % MOD) * fast(24,MOD-2) % MOD;
}

ll dodec(int n){
	return ((fast(n,4)*44 + fast(n,6)*15 + fast(n,12)) % MOD) * fast(60,MOD-2) % MOD;
}

ll icosah(int n){
	return ((fast(n,4)*24 + fast(n,8)*20 + fast(n,10)*15 + fast(n,20)) % MOD) * fast(60,MOD-2) % MOD;
}

int faces[5] = {4,6,8,12,20};

ll ways[M][M];

ll get(int n, int col){
	if(n == 4) return tetrahedron(col);
	if(n == 6) return cube(col);
	if(n == 8) return octahedron(col);
	if(n == 12) return dodec(col);
	if(n == 20) return icosah(col);
	return 0;
}

ll fact[N];
ll finv[N];

ll C(int n, int k){
	if(n < 0) return 0;
	return (fact[n] * finv[k] % MOD) * finv[n-k] % MOD;
}

void preprocess(){
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % MOD;
	finv[N-1] = fast(fact[N-1], MOD-2);
	for(int i = N-2; i >= 0; i--){
		finv[i] = (finv[i+1] * (i+1)) % MOD;
	}

	for(int i = 0; i < 5; i++){
		int x = faces[i];
		for(int j = 1; j <= faces[i]; j++){
			ways[x][j] = get(x, j);
		}
	}

	for(int i = 0; i < 5; i++){
		int x = faces[i];
		for(int j = 2; j <= x; j++){
			for(int k = 1; k < j; k++){
				ways[x][j] -= C(j,k) * ways[x][k] % MOD;
				if(ways[x][j] < 0) ways[x][j] += MOD;
			}
		}
	}
}

int n, k, f;
int fc[5];
int ptr[N];

vector<int> g[N];

ll dp[N][5][M];

stack<int> st;

void dfs(int cur){
	st.push(cur);
	while(!st.empty()){
		cur = st.top();
		if(ptr[cur] == g[cur].size()){
			if(g[cur].size() == 0){
				for(int i = 0; i < f; i++){
					int x = fc[i];
					for(int j = 1; j <= min(x,k); j++){
						dp[cur][i][j] = ways[x][j];
					}
				}				
			}
			else{
				for(int i = 0; i < f; i++){
					int x = fc[i];
					int mn1 = min(x,k);
					for(int j = 1; j <= mn1; j++){
						ll t = ways[x][j];
						ll s = 1;
						foreach(it, g[cur]){
							int nxt = *it;
				
							ll tot = 0;
							for(int pl = 0; pl < f; pl++){
								if(pl == i) continue;
								int xx = fc[pl];
								int mn2 = min(xx,k-j);
								for(int jj = 1; jj <= mn2; jj++){
									tot += (C(k-j, jj) * dp[nxt][pl][jj] % MOD);
									if(tot >= MOD) tot -= MOD;
								}
							}
				
							s = (s * tot) % MOD;
						}
						dp[cur][i][j] = (s * t) % MOD;
					}
				}
			}
			st.pop();
		}
		else{
			st.push(g[cur][ptr[cur]++]);
		}
	}
}

int main(){
	preprocess();
	
	sd3(n,k,f);
	
	for(int i = 0; i < f; i++) sd(fc[i]);
	
	
	for(int i = 2; i <= n; i++){
		int pr; sd(pr);
		g[pr].pb(i);
	}
	
	dfs(1);
	
	ll ans = 0;
	
	for(int i = 0; i < f; i++){
		int x = fc[i];
		for(int j = 1; j <= min(x,k); j++){
			ans += C(k,j) * dp[1][i][j] % MOD;
			if(ans >= MOD) ans -= MOD;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
