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

vector<int> itov(ll x){
	if(!x) return {0};
	vector<int> v;
	while(x){
		v.pb(x%10);
		x /= 10;
	}
	reverse(v.begin(), v.end());
	return v;
}

const int N = 20;
const int M = 9;
const int L = 2600;

ll dp[N][L][1<<M][2];

ll get(ll x, int k){
	if(k == 0) return x;
	if(x < 1) return 0;
	
	vector<int> v = itov(x);
	int n = v.size();	
	
	memset(dp, 0, sizeof dp);
	
	int lcm = 2520;
	
	dp[0][0][0][1] = 1;
	for(int i = 0; i < n; i++){
		for(int rem = 0; rem < lcm; rem++){
			for(int dmask = 0; dmask < (1<<M); dmask++){
				for(int eq = 0; eq < 2; eq++){
					ll val = dp[i][rem][dmask][eq];
					if(!val) continue;
								
					int mnd = (eq)? v[i] : 9;
					
					for(int nd = 0; nd <= mnd; nd++){
						int neq = (eq and nd == v[i]);
						int nrem = (rem * 10 + nd) % lcm;
						int nmask = dmask;
						if(nd) nmask |= 1 << (nd-1);
						
						dp[i+1][nrem][nmask][neq] += val;
					}
				}
			}
		}
	}
	
	ll res = 0;
	for(int mask = 0; mask < (1<<M); mask++){
		if(__builtin_popcount(mask) < k) continue;
		
		vector<int> digits;
		for(int i = 1; i <= M; i++){
			if(mask & (1 << (i-1))) digits.pb(i);
		}
		
		for(int rem = 0; rem < lcm; rem++){
			int cnt = 0;
			
			for(int d : digits){
				if(rem % d == 0){
					cnt++;
				}
			}
			
			if(cnt < k) continue;
			
			for(int eq = 0; eq < 2; eq++){
				res += dp[n][rem][mask][eq];
			}
		}
	}
	
	
	return res;
	
}

void solve(){
	ll a, b, k;
	cin >> a >> b >> k;
	cout << get(b, k) - get(a-1, k) << endl;
	
}

int main(){ _
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
