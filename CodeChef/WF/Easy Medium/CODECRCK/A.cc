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

const ld A = sqrt(2) + sqrt(6);
const ld B = sqrt(2) - sqrt(6);

ld fast(ld a, ll b){
	ld ret = 1;
	
	if(b > 0){
		while(b){
			if((b&1)) ret *= a ;
			a *= a;
			b >>= 1;
		}
	}
	else if(b < 0){
		b = -b;
		while(b){
			if((b&1)) ret /= a;
			a *= a;
			b >>= 1;
		}
	}
	
	return ret;
}

void caseA(ll i, ll k, ll s, ll a_i, ll b_i){
	ll S_i = a_i + b_i;
	ll T_i = a_i - b_i;
	
	ll pwr = ((k-i)/2)*4 - s;
	
	if((k-i) % 2 == 0){
		cout << fast(2, pwr) * S_i << endl;
	}
	else{
		cout << fast(2, pwr) * (A * S_i + B * T_i) << endl;
	}
}

void caseB(ll i, ll k, ll s, ll a_i, ll b_i){
	ll S_i = a_i + b_i;
	ll T_i = a_i - b_i;

	ll pwr = -((i-k)/2)*4 - s;
	
	if((i-k) % 2 == 0){
		cout << fast(2, pwr) * S_i << endl;
	}
	else{
		pwr -= 4;
		cout << fast(2, pwr) * (A * S_i + B * T_i) << endl;
	}
}

int main(){
	ll i, k, s, a_i, b_i;
	cin >> i >> k >> s >> a_i >> b_i;
	
	cout << fixed << setprecision(10);
	
	if(k >= i){
		caseA(i, k, s, a_i, b_i);
	}
	else{
		caseB(i, k, s, a_i, b_i);
	}
	
	return 0;
}
