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

const int K = 22;
const int N = 51;
const int M = 101;

double INF = 1e9;

double dp[K][M][N][3];
pii back[K][M][N][3];

int cost[N];
double ben[N];

int main(){
	while(true){
		int k, n, m;
		cin >> k >> n >> m;
		
		if(k == 0 and n == 0 and m == 0) break;

		for(int i = 0; i <= k; i++){
			for(int j = 0; j <= m; j++){
				for(int x = 0; x <= n; x++){
					dp[i][j][x][0] = dp[i][j][x][1] = dp[i][j][x][2] = -INF;
					back[i][j][x][0] = back[i][j][x][1] = back[i][j][x][2] = mp(-1,-1);
				}
			}
		}
	
		dp[0][0][0][0] = 0;
	
		for(int i = 1; i <= n; i++){
			cin >> cost[i] >> ben[i];
		}
		
		for(int d = 1; d <= k; d++){
			for(int b = 1; b <= m; b++){
				for(int i = 1; i <= n; i++){
					if(cost[i] <= b){
						double mx = -INF;
						pii id = mp(-1,-1);
					
						for(int j = 0; j <= n; j++){
							if(i == j) continue;
						
							if(dp[d-1][b-cost[i]][j][0] > mx){
								mx = dp[d-1][b-cost[i]][j][0];
								id = mp(j,0);
							}
						
							if(dp[d-1][b-cost[i]][j][1] > mx){
								mx = dp[d-1][b-cost[i]][j][1];
								id = mp(j,1);
							}
						}

						dp[d][b][i][0] = mx + ben[i];
						back[d][b][i][0] = id;
					}
				
					if(2 * cost[i] <= b){
						dp[d][b][i][1] = dp[d-1][b-cost[i]][i][0] + (ben[i] * 0.5);
						back[d][b][i][1] = mp(i,0);
					}
				
					if(3 * cost[i] <= b){
						double v1 = dp[d-1][b-cost[i]][i][1];
						double v2 = dp[d-1][b-cost[i]][i][2];
					
						if(v1 > v2){
							dp[d][b][i][2] = v1;
							back[d][b][i][2] = mp(i,1);
						}
						else{
							dp[d][b][i][2] = v2;
							back[d][b][i][2] = mp(i,2);	
						}
					}
				}
			}
		}
	
		double best = 0;
		pii id = mp(-1,-1);
		int budg = 0;
		
		for(int b = 0; b <= m; b++){
			for(int i = 1; i <= n; i++){
				for(int j = 0; j < 3; j++){
					if(dp[k][b][i][j] > best){
						best = dp[k][b][i][j];
						id = mp(i,j);
						budg = b;
						
					}
				}
			}	
		}
	
		printf("%.1lf\n", best);
		if(best == 0){
			cout << endl;
			continue;
		}
		
		vector<int> ans;
		
		while(k > 0){
			int x = id.fi;
			
			assert(1 <= x and x <= n);
			
			ans.pb(x);
			id = back[k][budg][x][id.se];
			budg -= cost[x];
			k--;
		}
		
		reverse(ans.begin(), ans.end());
		
		foreach(it, ans) cout << *it << ' ';
		cout << endl << endl;
	}
	
	return 0;
}
