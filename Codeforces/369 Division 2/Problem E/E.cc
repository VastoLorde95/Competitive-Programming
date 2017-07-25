#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

long long fast(long long a, long long b, long long MOD){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

const ll MOD = 1e6 + 3;

int main(){
	ll n, k;
	cin >> n >> k;
		
	if(n <= 59 and (1ll << n) < k){
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}
	
	ll a, b;
	
	b = fast(2, n, MOD);
	b = fast(b, k-1, MOD);	
	
	a = 1;
	
	ll x = (k-1) / MOD;
	ll y = (k-1) % MOD;
	
	ll t = fast(2, n, MOD);
	for(int i = 1; i <= MOD; i++){
		a *= (t - i + MOD) % MOD;
		a %= MOD;
	}
	a = fast(a, x, MOD);
	
	for(int i = 1; i <= y; i++){
		a *= (t - i + MOD) % MOD;
		a %= MOD;
	}

	ll tot = 0, tmp = k-1, pw = 2;
	while(pw <= tmp){
		tot += tmp / pw;
		pw <<= 1;
	}
	
	a = a * fast(fast(2, tot, MOD), MOD-2, MOD) % MOD;
	b = b * fast(fast(2, tot, MOD), MOD-2, MOD) % MOD;

	a = (b-a+MOD) % MOD; 
	
	cout << a << ' ' << b << endl;		
		
	return 0;
}
