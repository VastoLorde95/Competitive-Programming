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

const int M = 524288 + 10;

ll d[M];
ll x[M];
int f[M];
int pos[M];

void solve(){
	ll h;
	scanf("%lld", &h);
	
	ll n, m;
	scanf("%lld%lld", &n, &m);
	
	for(int i = 0; i < m; i++){
		f[i] = 0;
		pos[i] = -1;
	}
	
	ll a, b, ind;
	scanf("%lld%lld%lld", &a, &b, &ind);
	
	for(int i = 0; i < m; i++){
		scanf("%lld", d+i);
	}

	assert(x[0] == 0);

	for(int i = 1; i <= m+1; i++){
		f[ind]++, pos[ind] = i;
		
		x[i] = x[i-1] + d[ind];
		ind = (a * ind + b) % m;
	}
		
	if(n-1 <= m+1){
		
		ll ans = h * x[n-1];
		if(ans%2 == 0){
			printf("%lld.0\n", ans/2);
		}	
		else{
			printf("%lld.5\n", ans/2);
		}
		return;
	}
	
	ind = -1;
	for(int i = 0; i < m; i++){
		if(f[i] > 1){
			ind = i;
			break;
		}	
	}
	
	assert(ind != -1);
	
	ll sum = d[ind];
	ll tid = (ind * a + b) % m;
	ll len = 1;
	
	while(tid != ind){
		sum += d[tid];
		len++;
		tid = (tid * a + b) % m;
	}

	ll cur = x[pos[ind]-1];
	cur += sum * ((n-1-pos[ind]+1) / len);
	
	ll rem = (n-1-pos[ind]+1) % len;

	assert(tid == ind);
	for(int i = 0; i < rem; i++){
		cur += d[tid];
		tid = (tid * a + b) % m;		
	}
	
	ll ans = cur * h;
	
	assert(ans > 0);
	
	if(ans%2 == 0){
		printf("%lld.0\n", ans/2);
	}	
	else{
		printf("%lld.5\n", ans/2);
	}
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
