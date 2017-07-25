#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 110;
const ll INF = 1ll << 60;

ll dp[N][N][N];

int n, m, k;
int c[N];

ll p[N][N];

int main(){ _
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> p[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int r = 0; r <= k; r++){
			for(int j = 0; j <= m; j++){
				dp[i][r][j] = INF;
			}
		}
	}
	
	dp[0][0][0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i and j <= k; j++){
			if(c[i] == 0){
				for(int r = 1; r <= m; r++){
					dp[i][j][r] = dp[i-1][j][r] + p[i][r];
					for(int rr = 1; rr <= m; rr++){
						if(rr == r) continue;
						dp[i][j][r] = min(dp[i][j][r], dp[i-1][j-1][rr] + p[i][r]);
					}
				}	
			}
			else{
				for(int rr = 1; rr <= m; rr++){
					if(rr == c[i]){
						dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j][rr]);
					}
					else{
						dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][rr]);
					}
				}
			}
		}
	}
	
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= i and j <= k; j++){
//			for(int c = 1; c <= m; c++){
//				tr(meta, i, j, c, dp[i][j][c]);
//			}
//		}
//	}
	
	ll mn = INF;
	for(int i = 1; i <= m; i++){
		mn = min(mn, dp[n][k][i]);
	}
	
	if(mn == INF) mn = -1;
	cout << mn << endl;
	
	return 0;
}
