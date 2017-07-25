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

const int N = 33000;

const ld PI = 3.1415926535897932384626433832795;

void solve(){
	ld r, k;
	cin >> r >> k;
	
	ld x = k / 100.0;
	
	ld low = r*r + x*x - r*x*2.0;
	ld hi = r;
	
	ll bound = sqrt(r) + 0.5;
	
	tr(bound);
	
	for(ll i = 1; i <= bound; i++){
		ll a = i * i, b, tot;
		ll lo = 1, hi = r, mid;
		while(lo + 1 < hi){
			mid = (lo + hi) / 2;
			
			b = mid * mid;
			
			tot = a + b;
			if(tot < low) lo = mid;
			else if(tot > hi) hi = mid;
			else{
				cout << i << ' ' << mid << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main(){ _
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
