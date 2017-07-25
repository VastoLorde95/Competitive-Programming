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

vector<int> htov(string s){
	vector<int> ret;
	for(char c : s){
		if(c <= '9') ret.pb(c-'0');
		else ret.pb(10 + c-'a'); 
	}
	
	reverse(ret.begin(), ret.end());
	
	return ret;
}

void sub(vector<int> &v){
	int n = v.size();
	
	if(n == 1 and v[0] == 0) return;
	
	int i = 0;
	while(i < n and v[i] == 0) i++;
	v[i]--;
	
	if(i > 0){
		for(int j = 0; j < i; j++) v[j] = 15;
		if(v[i] == 0 and (i+1) == v.size()) v.resize(i);
	}
	
	return;
	
}

const int N = 17;

ll dp[N][2][2];

ll get(vector<int> v){
//	tr(v);
	reverse(v.begin(), v.end());
	
	int n = v.size();
	
	ll res = 0;
	
	for(int d = 1; d < 16; d++){
		if((d/4)+1 > n) break;
		
		memset(dp, 0, sizeof dp);
		
		dp[0][1][0] = 1;
		
		for(int i = 0; i < n; i++){
			for(int eq = 0; eq < 2; eq++){
				for(int flag = 0; flag < 2; flag++){
					ll val = dp[i][eq][flag];
					if(!val) continue;
					
					int max_nd = min(d, (eq == 0)? 15 : v[i]);
					
					for(int nd = 0; nd <= max_nd; nd++){
						if(n-i-1 == d/4 and (nd & (1<<(d%4))) == 0) continue;
						
						int neq = (eq and nd == v[i]);
						int nflag = (flag or nd == d);
						
						dp[i+1][neq][nflag] += val;
					}
				}
			}
		}
		
		for(int eq = 0; eq < 2; eq++){
			res += dp[n][eq][1];			
		}
	}
	
	return res;
}

void solve(){
	string l, r;
	cin >> l >> r;
	
	vector<int> R = htov(r);
	vector<int> L = htov(l);
	
	sub(L);

	cout << get(R) - get(L) << endl;
}

int main(){ _
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
