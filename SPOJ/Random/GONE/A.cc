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

const int N = 8;

int dp[N][9*N][2];
vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};

vector<int> digits(int x){
	vector<int> res;
	while(x){
		res.pb(x % 10);
		x /= 10;
	}
	
	reverse(res.begin(), res.end());
	
	return res;
}

int get(int x){
	if(x <= 1) return 0;
	
	vector<int> d = digits(x);
	
	int n = d.size();
	
	memset(dp, 0, sizeof dp);
	
	dp[0][0][1] = 1;
	for(int i = 0; i < n; i++){
		for(int sum = 0; sum <= 9 * i; sum++){
			for(int eq = 0; eq < 2; eq++){
				int val = dp[i][sum][eq];
				if(!val) continue;
				
				for(int nd = 0; nd < 10; nd++){
					if(eq and nd > d[i]) break;
					
					int neq = (eq and nd == d[i]);
					int nsum = sum + nd;
					
					dp[i+1][nsum][neq] += val;
				}
			}
		}
	}
	
	int res = 0;
	for(int p : pr){
		for(int eq = 0; eq < 2; eq++){
			res += dp[n][p][eq];
		}
	}
	
	return res;
}

void solve(){
	int f, t;
	cin >> f >> t;
	
	if(f > t){
		cout << 0 << endl;
		return;
	}
	
	cout << get(t) - get(f-1) << endl;
}

int main(){ _
	int c;
	cin >> c;
	while(c--) solve();
	return 0;
}
