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

const int N = 110;
const ll MOD = 1e9 + 7;

ll m[N][N], ret[N][N], res[N][N], n;

void mul(ll a[N][N], ll b[N][N]){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			res[i][j] = 0;			
			for(int k = 1; k <= n; k++){
				res[i][j] += (a[i][k] * b[k][j]) % MOD;
				if(res[i][j] >= MOD) res[i][j] -= MOD;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = res[i][j];
	return;
}

void fast(ll exponent){
	for(int i = 1; i <= n; i++) ret[i][i] = 1;
	
	while(exponent > 0){
		if(exponent%2) mul(ret, m);
		mul(m, m);
		exponent >>= 1;
	}
	
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) m[i][j] = ret[i][j];
	return;
}


int main(){ _
	ll k, aa[N];
	cin >> n >> k;

	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		cin >> aa[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			ll b = (aa[i]^aa[j]);
			
			if(__builtin_popcountll(b)%3 == 0){
				m[i][j] = 1;
			}
		}
	}
	
	fast(k-1);
	
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			ans += m[i][j];
			if(ans >= MOD) ans -= MOD;
		}
	}
	
	assert(ans >= 0 and ans < MOD);
	cout << ans << endl;
	
	return 0;
}
