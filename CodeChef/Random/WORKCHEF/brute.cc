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

map<pii, int> h;

ll get(ll x, ll k){
	h.clear();
	
	for(int mask = 1; mask < (1<<9); mask++){
		for(int i = 1; i <= x; i++){
			int dmask = 0;

			int tmp = i;
			while(tmp){
				int ldig = tmp % 10;
				tmp /= 10;
				if(ldig > 0) dmask |= (1 << (ldig-1));
			}
			
			if((dmask&mask) != mask) continue;
			
			vector<int> d;
			for(int j = 1; j <= 9; j++){
				if(dmask&(1<<(j-1))) d.pb(j);
			}
			
			bool ok = true;
			for(int y : d) if(i % y != 0) ok = false;
			
			if(ok) h[mp(mask, dmask)]++;
		}
	}
	
	foreach(it, h){
		tr(*it);
	}
}

void solve(){
	ll a, b, k;
	cin >> a >> b >> k;
	
	get(b,k);
	get(a,k);
}

int main(){
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
