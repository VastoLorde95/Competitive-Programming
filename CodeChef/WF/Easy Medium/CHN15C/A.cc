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

const int N = 110;

int a[N];
int dp[N][N];
int les[N][N][N];
int mor[N][N][N];

void solve(){
	int n;
	cin >> n;
	
	memset(les, 0, sizeof les);
	memset(mor, 0, sizeof mor);
	memset(dp, 0, sizeof dp);
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		les[i][0][n+1] = mor[i][0][n+1] = 0;
		
		if(i < n){
			for(int r = n; r > i; r--){
				if(a[r] > a[i]){
					mor[i][0][r] = mor[i][0][r+1] + 1;
					les[i][0][r] = les[i][0][r+1];
				}
				else if(a[r] < a[i]){
					mor[i][0][r] = mor[i][0][r+1];
					les[i][0][r] = les[i][0][r+1] + 1;
				}
				else{
					mor[i][0][r] = mor[i][0][r+1];
					les[i][0][r] = les[i][0][r+1];
				}
			}
		}
		if(i > 1){
			for(int l = 1; l < i; l++){
				if(a[l] > a[i]){
					mor[i][l][n+1] = mor[i][l-1][n+1] + 1;
					les[i][l][n+1] = les[i][l-1][n+1];
				}
				else if(a[l] < a[i]){
					mor[i][l][n+1] = mor[i][l-1][n+1];
					les[i][l][n+1] = les[i][l-1][n+1] + 1;
				}
				else{
					mor[i][l][n+1] = mor[i][l-1][n+1];
					les[i][l][n+1] = les[i][l-1][n+1];
				}
			}
			
//			if(i == 7){
//				tr(a[i], mor[i][i-1][n+1], les[i][i-1][n+1]);	
//			}
		}
		
		if(1 < i and i < n){
			int low = 0, high = 0;
			for(int l = 1; l < i; l++){
				if(a[l] > a[i]) high++;
				else if(a[l] < a[i]) low++;
				
				int x = 0, y = 0;
				for(int r = n; r > i; r--){
					if(a[r] > a[i]) x++;
					if(a[r] < a[i]) y++;
					
					mor[i][l][r] = high + x;
					les[i][l][r] = low + y;
				}
			}
		}
	}
	
	int ans = 1e9;
	for(int i = 0; i <= n; i++){
		for(int j = n+1; j > i; j--){
			if(i == 0 and j == n+1) continue;
			
			int mn = 1e9;
			if(i > 0){
				mn = min(mn, dp[i-1][j] + min(mor[i][i-1][j], les[i][i-1][j]));
			}
			if(j < n + 1){
				mn = min(mn, dp[i][j+1] + min(mor[j][i][j+1], les[j][i][j+1]));
			}
			
//			if(i == 7 and j == 9){
//				tr(dp[i-1][j], mor[i][i-1][j], les[i][i-1][j]);
//				tr(dp[i][j+1], mor[j][i][j+1], les[j][i][j+1]);
//			}
			
			dp[i][j] = mn;
			if(j == i+1){
				ans = min(ans, mn);
//				if(ans == 1){
//					tr(ans, i, j);
//					tr(dp[i-1][j], mor[i][i-1][j], les[i][i-1][j]);
//					tr(dp[i][j+1], mor[j][i][j+1], les[j][i][j+1]);
//				}
			}
		}
	}
	
//	for(int i = 1; i <= 8; i++){
//		tr(i, dp[i][9]);
//	}
	
//	tr(dp[3][n+1-3]);
//	
//	for(int i = 1; i <= n; i++){
//		for(int l = 0; l < i; l++){
//			for(int r = n+1; r > i; r--){
//				tr(i, l, r, mor[i][l][r], les[i][l][r]);
//			}
//		}
//		cout << endl;
//		cout << endl;
//	}
	
	cout << ans << endl;
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
