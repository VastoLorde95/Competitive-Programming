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

int n, m, q;

vector<int> g[N];

vector<int> f[N];

int geth(int x){
	int tx = x, ret = 0;
	while(tx){
		ret ++;
		tx >>= 1;
	}
	return ret;
}

int getdis(int x, int y){
	int h1 = geth(x);
	int h2 = geth(y);
	
	if(h1 > h2){
		swap(x,y);
		swap(h1, h2);
	}

	int len = 0;
	while(h2 > h1){
		y /= 2;
		h2--;
		len++;
	}
	
	while(x != y){
		x /= 2;
		y /= 2;
		len += 2;
	}
	
	return len;
}

int main(){ _ 
	cin >> n >> m >> q;

	for(int i = 1; i <= m; i++){
		int k; cin >> k;
		while(k--){
			int x; cin >> x;
			f[i].pb(x);
		}
	}
	
	ll ans = 0;
	int cur = 1;
	while(q--){
		int x, y;
		cin >> x >> y;
		
		int mn = 1e9;
		
		for(auto &z : f[x]){
			int val = getdis(cur, z) + getdis(z, y);
			if(val < mn){
				mn = val;
			}
		}
		
		ans += mn;
		
		cur = y;
	}
	
	cout << ans << endl;
	
	return 0;
}
