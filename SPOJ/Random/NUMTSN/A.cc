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
const int MOD = 1000000007;

const int N = 52;
const int M = 17;

int dp[N][M][M][M][2];


void add(int &x, int y){
	x += y;
	if(x >= MOD) x -= MOD;
}

vector<int> digits(string x){
	vector<int> ret;
	
	for(char c : x) ret.pb(c - '0');
	return ret;
}

ll get(string x){
	vector<int> v = digits(x);
	
	int n = v.size();
	
	int lim = n / 3;
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= lim; j++){
			for(int k = 0; k <= lim; k++){
				for(int l = 0; l <= lim; l++){
					for(int eq = 0; eq < 2; eq++){
						dp[i][j][k][l][eq] = 0;	
					}
				}
			}
		}
	}
	
	dp[0][0][0][0][1] = 1;
	
	
	for(int i = 0; i < n; i++){
		
		int xx = min(i, lim);
		for(int j = 0; j <= xx; j++){
			int yy = min(lim, n-j);
			for(int k = 0; k <= yy; k++){
				int zz = min(lim, n-j-k);
				for(int l = 0; l <= zz; l++){
					
					int mx = max(j,max(k,l));
					int mreq = 3*mx - j - k - l;
					if(i + mreq > n) continue;
					
					for(int eq = 0; eq < 2; eq++){
						ll val = dp[i][j][k][l][eq];
						if(!val) continue;
						
						int mnd = (eq)? v[i] : 9;
						
						for(int nd = 0; nd <= mnd; nd++){
							int neq = (eq and nd == v[i]);
							
							if(nd != 3 and nd != 6 and nd != 9){
								add(dp[i+1][j][k][l][neq], val);
								continue;
							}
							
							int nj = j, nk = k, nl = l;
							
							if(nd == 3) nj++;
							else if(nd == 6) nk++;
							else if(nd == 9) nl++;
							
							if(nj > 16 or nk > 16 or nl > 16) continue;
						
							add(dp[i+1][nj][nk][nl][neq], val);	
						}
					}
				}
			}	
		}
	}
	
	int res = 0;
	for(int i = 1; i < M; i++){
		for(int j = 0; j < 2; j++){
			add(res, dp[n][i][i][i][j]);		
		}
	}
	
	return res;
}

void solve(){
	string a, b;
	cin >> a >> b;
	
	int x = 0, y = 0, z = 0;
	for(char c : a) if(c == '3') x++; else if(c == '6') y++; else if(c == '9') z++;
	
	int flag = (x == y) and (y == z) and (x > 0);	
	
	cout << (get(b) - get(a) + flag + MOD) % MOD << endl;
}

int main(){ _
	int t;
	cin >> t;
	
//	cout << get(t) << endl;
//	t = 0;	
	
	while(t--) solve();
	return 0;
}
