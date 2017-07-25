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
const ll MOD = 1e9 + 7;

void mul(ll a[][2], ll b[][2]){
	ll res[2][2];
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			res[i][j] = 0;			
			for(int k = 0; k < 2; k++){
				res[i][j] += (a[i][k] * b[k][j]) % MOD;
				if(res[i][j] >= MOD) res[i][j] -= MOD;
			}
		}
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			a[i][j] = res[i][j];
		}
	}
	return;
}

void fast(ll m[][2], ll b){
	ll ret[2][2];
	ret[0][0] = ret[1][1] = 1;
	ret[1][0] = ret[0][1] = 0;
	
	while(b){
		if(b&1){
			mul(ret, m);
		}
		mul(m, m);
		b >>= 1;
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			m[i][j] = ret[i][j];
		}
	}
}

ll query(ll x){
	ll tmp[2][2];
		
	tmp[0][0] = tmp[0][1] = tmp[1][0] = 1;
	tmp[1][1] = 0;

	fast(tmp, x-1);
	
	return tmp[0][0];
}

int n, m;

ll a[N];

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		scanf("%lld", a+i);
	}

	while(m--){
		int t, l, r, x;
		sd3(t,l,r);
		l--, r--;
		
		if(t == 1){
			sd(x);
			for(int i = l; i <= r; i++){
				a[i] += x;
			}
		}
		else{
			ll tot = 0;
			for(int i = l; i <= r; i++){
				tot += query(a[i]);
				tot %= MOD;
			}
			printf("%lld\n", tot);
		}
	}	
	
	return 0;
}
