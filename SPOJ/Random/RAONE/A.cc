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

const int N = 10;

int dp[N][9*N*2 + 1][2];

vector<int> digits(int x){
	vector<int> res;
	while(x){
		res.pb(x%10);
		x /= 10;
	}
	return res;
}

int get(int x){
	if(x <= 0) return 0;
	
	vector<int> v = digits(x);
	reverse(v.begin(), v.end());
	
	int n = v.size();
		
	memset(dp, 0, sizeof dp);
	
	int off = 90;
	
	dp[0][off][1] = 1;
	for(int i = 0; i < n; i++){
		for(int sum = -90; sum <= 90; sum++){
			for(int eq = 0; eq < 2; eq++){
				int val = dp[i][off+sum][eq];
				if(!val) continue;
				
				int mnd = (eq)? v[i] : 9;
				
				for(int nd = 0; nd <= mnd; nd++){
					int pos = (n-i);
					
					int nsum = (pos&1)? sum - nd : sum + nd;
					int neq = (eq and nd == v[i]);
					
					dp[i+1][off+nsum][neq] += val;
				}				
			}
		}
	}
	
	int res = dp[n][off+1][0] + dp[n][off+1][1];
	return res;
	
}

void solve(){
	int f, t;
	cin >> f >> t;
	int ans;
	if(f > t) ans = 0;
	else ans = get(t) - get(f-1);
	cout << ans << '\n';
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
