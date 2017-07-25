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

typedef unsigned long long ll;
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

const int N = 65;
const int M = 47+1;

ll dp[N][M][2];
vector<int> lucky = {4,7,44,47};

vector<int> itob(ll x){
	vector<int> ret;
	while(x){
		ret.pb(x&1);
		x >>= 1;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

ll get(vector<int> v, bool flag){
	int n = v.size();
	
	int lim = 0;
	for(int i = 0; i < 4 and lucky[i] <= n; i++){
		lim = lucky[i];
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= lim; j++){
			dp[i][j][0] = dp[i][j][1] = 0;
		}
	}
	
	dp[0][0][1] = 1;
	for(int i = 0; i < n; i++){
		for(int s = 0; s <= lim; s++){
			for(int eq = 0; eq < 2; eq++){
				ll val = dp[i][s][eq];
				if(!val) continue;
				
				int mnd = (eq)? v[i] : 1;
				for(int nd = 0; nd <= mnd; nd++){
					int ns = s + nd;
					if(ns > lim) break;
					int neq = (eq and nd == v[i]);
					
					dp[i+1][ns][neq] += val;
				}
			}
		}
	}
	
	ll res = 0;
	
	for(int num : lucky){
		if(num > n) break;
		res += dp[n][num][0];
		if(flag) res += dp[n][num][1];
	}
	
	return res;
}

void solve(){
	ll a, b;
	cin >> a >> b;
	vector<int> A = itob(a);
	vector<int> B = itob(b);
	
	cout << get(B,1) - get(A,0) << '\n';
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
