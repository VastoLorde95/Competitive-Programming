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
	vector<int> v;
	while(x) v.pb(x % 10), x /= 10;
	reverse(v.begin(), v.end());
	return v;
}

const int N = 20;

ll dp[N][11][11][4][2][2];

ll get(ll x){
	vector<int> v = itov(x);
	int n = v.size();
	
	memset(dp, 0, sizeof dp);
	
	dp[0][10][10][0][1][0] = 1;
	for(int i = 0; i < n; i++){
		for(int x = 0; x <= 10; x++){
			for(int y = 0; y <= 10; y++){
				for(int st = 0; st < 4; st++){
					for(int eq = 0; eq < 2; eq++){
						for(int nz = 0; nz < 2; nz++){
							ll val = dp[i][x][y][st][eq][nz];
							if(!val) continue;
						
							// x, y, nd
							// 0 -> kuch nahi hai bc
							// 1 -> even is there
							// 2 -> odd is there
							// 3 -> dono hai bc
						
							int mnd = (eq)? v[i] : 9;
							for(int nd = 0; nd <= mnd; nd++){
								if(nz == 0 and nd == 0){
									int nx = 10;
									int ny = 10;
									int neq = 0;
									int nst = 0;
									int nnz = 0;
									
									dp[i+1][nx][ny][nst][neq][nnz] += val;
									
									continue;
								}
								
								int nx = y;
								int ny = nd;
								int nnz = (nz or nd > 0);
								
								int neq = (eq and nd == v[i]);
								int nst;
								if(st == 0){
									if(nd == y) nst = 1;
									else if(nd == x) nst = 2;
									else nst = 0;
								}
								else if(st == 1){
									if(nd == x) nst = 3;
									else nst = 1;
								}
								else if(st == 2){
									if(nd == y) nst = 3;
									else nst = 2;
								}
								else{
									nst = 3;
								}
							
								dp[i+1][nx][ny][nst][neq][nnz] += val;
							}							
														
						}
					}
				}
			}
		}
	}
	
	
	ll res = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			res += dp[n][i][j][3][0][1];
			res += dp[n][i][j][3][1][1];
		}
	}
		
	return res;
}

void solve(){
	ll a, b;
	cin >> a >> b;
	cout << get(b) - get(a) << '\n';
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
