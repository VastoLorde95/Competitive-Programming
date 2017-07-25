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

const int N = 100100;
const ll MOD = 1e9 + 7;

int k;

ll a[N];

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){ _
	cin >> k;
	
	bool even = false;
	bool ones = true;
	for(int i = 1; i <= k; i++){
		cin >> a[i];
		if(a[i] != 1) ones = false;
		if(a[i]%2 == 0) even = true;
	}
	
	if(ones){
		cout << "0/1" << endl;
		return 0;
	}
	
	ll p = 1;
	for(int i = 1; i <= k; i++){
		p = (p * (a[i] % (MOD-1))) % (MOD-1);
	}
	
	ll num = (fast(2,p) * fast(2,MOD-2)) % MOD;
	if(even){
		num = (num + 1) % MOD;
	}
	else num = (num - 1 + MOD) % MOD;
	
	num = (num * fast(3,MOD-2)) % MOD;
	
	ll den = ((fast(2,p) * fast(2,MOD-2)) % MOD);// * fast(2,MOD-2)) % MOD;
	
	cout << num << '/' << den << endl;
	
	return 0;
}
