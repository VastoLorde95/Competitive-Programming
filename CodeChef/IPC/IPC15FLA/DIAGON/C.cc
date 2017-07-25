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

int d[N];
int dep[N];

int main(){
	int n, m, k;
	sd3(n,m,k);

	for(int i = 1; i <= n; i++){
		sd(d[i]);
	}	
		
	for(int i = 0; i < m; i++){
		int a, b; sd2(a,b);	
		dep[b] = max(dep[b], a);
	}	
	
	ll ans = 0;
	int prev = 0, nxt = -1;
	
	bool nodep = true;
	
	for(int i = 1; i <= n; i++){
		if(d[i] > k){
			ans += 2ll * (d[n] - k);
			if(nxt >= i){
				ans += 3ll * (k - prev);
			}
			else{
				ans += k - prev;
			}
			prev = k;
			break;
		}
		
		if(nodep){
			ans += d[i] - prev;
			prev = d[i];
			if(dep[i]){
				nxt = dep[i];
				nodep = false;
			}
		}
		else{
			if(dep[i] > nxt){
				nxt = dep[i];
			}
			
			if(i == nxt){
				ans += 2ll * (d[i] - prev);
				nodep = true;
			}
		}
	}		
	
	ans += k - prev;
	
	printf("%lld\n", ans);
	
	return 0;
}
