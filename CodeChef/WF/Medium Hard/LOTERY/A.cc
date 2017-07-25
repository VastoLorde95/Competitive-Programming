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
 
const int MOD = 1e9 + 7;
const int N = 100001;
 
inline int fast(int a, int b){
	int ret = 1;
	while(b){
		if((b&1)) ret = (ll) ret * a %MOD;
		a = (ll) a * a % MOD;
		b >>= 1;
	}
	return ret;
}
 
int isprime[N];
int ppro[N];
int ippro[N];
int invp[N];
vector<int> primes;

void pre(int n){
	isprime[2] = 1;
	for(int i = 3; i <= n; i += 2) isprime[i] = 1;
	
	for(int i = 3; i * i <= n; i += 2){
		if(!isprime[i]) continue;
		for(int j = i * i; j <= n; j += i) isprime[j] = 0;
	}
	
	ppro[0] = 1;
	for(int i = 1; i <= n; i++){
		if(isprime[i]){
			ppro[i] = (ll) ppro[i-1] * i % MOD;
			invp[i] = fast(i, MOD-2);
			primes.pb(i);
		}
		else ppro[i] = ppro[i-1];
		ippro[i] = fast(ppro[i], MOD-2);
	}
}
 
int solve(int n, int k){
	int rt = sqrt(n) + 1;
	int ans = 1;
	
	int num, mx;
	for(int p : primes){
		if(p >= rt) break;
		
		num = p;
		mx = 1;
		
		while(num <= n){
			if((n/num)*num >= n-k+1)
				mx = num;
			else break;
			num *= p;
		}
		
		if(mx > 1) ans = (ll) ans * mx % MOD;
	}
	
	int L = max(n-k+1, rt), R = n;
	
	ans = (ll) ans * ((ll) ppro[R] * ippro[L-1] % MOD) % MOD;
	
	int low = L, high = R, x, y;
	
	for(int i = 2; i <= rt; i++){
		x = (L-1) / i + 1, y = R / i;
		
		x = max(x, rt);
		
		if(x > y) continue;
		if(x >= low) continue;
		
		high = min(low-1, y);		
		low = x;
		
		ans = (ll) ans * ((ll) ppro[high] * ippro[low-1] % MOD) % MOD; 
		
		i = max(i+1, R / high) - 1;
	}
	
	return ans;	
}
 
int c[N*10];
int d[N*10];
 
int main(){
	int t;
	sd(t);
	
	int n, k;
	scanf("%d%d", &n, &k);
 
	int a, b, m;
	scanf("%d%d%d", &a, &b, &m);
	
	pre(m);
	
	for(int i = 1; i < t; i++) scanf("%d", c+i);
	for(int i = 1; i < t; i++) scanf("%d", d+i);
	
	int ans = solve(n, k);
	
	printf("%d\n", ans);
	
	for(int i = 1; i < t; i++){
		n = 1 + ((ll) a * ans + c[i]) % m;
		k = 1 + ((ll) b * ans + d[i]) % n;
		
		ans = solve(n, k);
		
		printf("%d\n", ans);
	}
	
	return 0;
} 
