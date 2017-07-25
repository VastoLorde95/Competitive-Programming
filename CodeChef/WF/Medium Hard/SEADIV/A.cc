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

const int N = 1001000;
const int L = 10100;
const int K = 7*7*7*7*7*7*7*7*7*7;

ll pwrs[10];

char a[N];
char b[L];
int l;

vector<ll> A;
vector<ll> B;

void pad(vector<ll> &v){
	if(v.size() > l) v.resize(l);
	while(v.size() < l) v.pb(0);
}

void convert(vector<ll> &v){
	ll num = 0;
	ll pwr = 0;
	
	int j = 0;	
	for(int i = 0; i < v.size(); i++){
		num += v[i] * pwrs[pwr++];
		if(pwr == 10){
			v[j++] = num;
			num = 0;			
			pwr = 0;
		}
	}
	if(pwr) v[j++] = num;
	
	v.resize(j);
}

void get(){
	scanf("%s", a);
	scanf("%s", b);
	sd(l);
	
	int n1 = strlen(a);
	int n2 = strlen(b);
	
	A.clear();
	B.clear();
	
	for(int i = 0; i < n1; i++){
		A.pb(a[i]-'0');
	}
	
	for(int i = 0; i < n2; i++){
		B.pb(b[i]-'0');	
	}
	
	while(B.back() == 0){
		A.pop_back();
		B.pop_back();
	}
	
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	pad(A);
	pad(B);
	
	convert(A);
	convert(B);
}

ll inv(ll a, ll b = (K - K/7) - 1){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%K;
		a = (a*a)%K;
		b >>= 1;
	}
	return ret;
}

void sub(ll mul, int start){
	ll carry = 0, val;
	vector<ll> C;
	
	for(ll i : B){
		val = i * mul + carry;
		C.pb(val % K);
		carry = val / K;
	}
	C.pb(carry);
	
	for(int i = start; i < A.size(); i++){
		A[i] -= C[i-start];
		if(A[i] < 0){
			A[i] += K;
			C[i-start+1]++;
		}
	}
}

void solve(){
	get();
	
	vector<ll> res;
	
	assert(A.size() == B.size());

	// since B does not end with a zero, inverse exists!
	ll ii = inv(B[0]);
	
	for(int i = 0; i < A.size(); i++){
		ll d = A[i] * ii % K;
		res.pb(d);
		sub(d, i);
	}
	
	vector<int> R;
	for(ll i : res){
		ll j = i;
		
		if(j == 0){
			for(int i = 0; i < 10; i++) R.pb(0);
			continue;
		}
		
		vector<int> d;
		while(j){
			d.pb(j % 7);
			j /= 7;
		}
		
		while(d.size() < 10) d.pb(0);
		for(int k : d) R.pb(k);
	}
	
	while(R.size() > l) R.pop_back();
	while(R.size() > 1 and R.back() == 0) R.pop_back();
	
	reverse(R.begin(), R.end());
	
	for(int i : R) printf("%d", i);
	printf("\n");
}

int main(){
	pwrs[0] = 1;
	for(int i = 1; i < 10; i++) pwrs[i] = pwrs[i-1] * 7;

	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
