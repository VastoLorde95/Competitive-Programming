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

const int N = 100100;

int n;
ll a[N];
ll l[N];
ll r[N];

int main(){ _
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	if(n == 1){
		cout << a[0] + 1 << endl;
		return 0;
	}
	
	if(n == 2){
		cout << max(a[0], a[1]) << endl;
		return 0;
	}
	
	l[0] = a[0];
	for(int i = 1; i < n; i++){
		l[i] = __gcd(l[i-1], a[i]);
	}
	
	r[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
		r[i] = __gcd(r[i+1], a[i]);
	}

	ll v = l[n-2];
	if(v > 1 and a[n-1] % v != 0){
		cout << v << endl;
		return 0;
	}
	
	v = r[1];
	if(v > 1 and a[0] % v != 0){
		cout << v << endl;
		return 0;
	}
	
	for(int i = 1; i < n-1; i++){
		ll v = __gcd(l[i-1], r[i+1]);
		if(v > 1 and a[i] % v != 0){
			cout << v << endl;
			return 0;
		}
	}
	
	
	
	return 0;
}
