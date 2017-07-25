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
 
const int N = 300;
 
ll n, m, e;
ll c[N];
ll d[N];
 
int get(ll diff){
	int j = 1;
	int ret = 0;
	for(int i = 1; i <= m; i++){
		int id = -1;
		for(int k = j; k <= n; k++){
			if(abs(c[k] - diff - d[i]) <= e){
				id = k;
				break;
			}
			
			if(c[k] - diff >= d[i] and abs(c[k] - diff - d[i]) > e){
				j = k;
				break;
			}
		}
		
		if(id != -1){
			ret++;
			if(ret == min(n,m)) break;
			j = id + 1;
		}
	}
	
	return ret;
}
 
void solve(){
	cin >> n >> m >> e;
	
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	
	for(int i = 1; i <= m; i++){
		cin >> d[i];
	}
	
	sort(c + 1, c + n + 1);
	sort(d + 1, d + m + 1);
	
	set<ll> pts;
	for(int i = 1; i <= m; i++){
		pts.insert(d[i] - e);
	}
	
	int best = 0;
	
	foreach(it, pts){
		ll x = *it;
		
		for(int i = 1; i <= n; i++){
			// if ith point is located at x
			ll diff = c[i] - x;
			
			best = max(best, get(diff));	
		}
	}
	
	cout << best << endl;
	
}
 
int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
} 
