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

const int N = 1010;
const int K = 55;

const int INF = 1e9;

int a[N];
int b[N];
int dp[2][N][K][K];

int main(){ _
	int n, p, k;
	cin >> n >> p >> k;
	
	if(p > 2*(n+k-1)/k){
		p = 2*(n+k-1)/k;
	}
	
	int nn1;
	cin >> nn1;
	for(int i = 1; i <= nn1; i++){
		int x;
		cin >> x;
		a[x] = 1;
	}
	
	int nn2;
	cin >> nn2;
	for(int i = 1; i <= nn2; i++){
		int x;
		cin >> x;
		b[x] = 1;
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j <= p; j++){
			for(int x = 0; x <= k; x++){
				for(int y = 0; y <= k; y++){
					dp[i][j][x][y] = -INF;
				}
			}
		}
	}	
	
	
	dp[0][0][0][0] = 0;
	dp[1][0][0][0] = 0;
	
	int id = 0;
	for(int i = 1; i <= n; i++){
		id ^= 1;
		
		for(int j = 1; j <= p; j++){
			for(int x = 0; x < k; x++) for(int y = 0; y < k; y++) dp[id][j][x][y] = -INF;
			
			for(int x = 0; x < k; x++){
				for(int y = 0; y < k; y++){
					int &mx = dp[id][j][x][y];
					
					// started A, B already existed
					if(y != k-1){
						mx = max(mx, dp[!id][j-1][0][y+1] + (a[i] | b[i]));
					}
					
					// started A, B did not exist
					if(!y){
						mx = max(mx, dp[!id][j-1][0][0] + a[i]);
					}
					
					// started B, A already existed
					if(x != k-1){
						mx = max(mx, dp[!id][j-1][x+1][0] + (a[i] | b[i]));
					}
					
					// started B, A did not exist
					if(!x){
						mx = max(mx, dp[!id][j-1][0][0] + b[i]);
					}
					
					// started A and B
					if(j >= 2){
						mx = max(mx, dp[!id][j-2][0][0] + (a[i] | b[i]));
					}
					
					// both A and B already existed
					if(j >= 2 and x != k-1 and y != k-1){
						mx = max(mx, dp[!id][j][x+1][y+1] + (a[i] | b[i]));
					}
					
					// A already exists, B does not
					if(!y and  x != k-1){
						mx = max(mx, dp[!id][j][x+1][0] + a[i]);
					}
					
					// B already exists, A does not
					if(!x and y != k-1){
						mx = max(mx, dp[!id][j][0][y+1] + b[i]);
					}
					
					// none existed
					if(x == 0 and y == 0){
						mx = max(mx, dp[!id][j][x][y]);
					}
				}
			}
		}
	}
	
	int ans = 0;
	for(int j = 1; j <= p; j++){
		for(int x = 0; x < k; x++){
			for(int y = 0; y < k; y++){
				ans = max(ans, dp[id][j][x][y]);				
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
