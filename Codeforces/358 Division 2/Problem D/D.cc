#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
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

const int N = 1010;
const int K = 11;
const int INF = 1e9;

string s, t;
int n, m, k;

int dp[N][N][K][2];

int main(){ _
	cin >> n >> m >> k;
	cin >> s >> t;
	
	s = 'a' + s;
	t = 'a' + t;
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int b = 0; b <= k; b++){
				for(int c = 0; c < 2; c++){
					if(b == 0 and c == 0)
						dp[i][j][b][c] = 0;
					else
						dp[i][j][b][c] = -INF;
				}
			}
		}
	}
	
	dp[0][0][0][0] = 0;
	
	
	for(int b = 1; b <= k; b++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(s[i] == t[j]){
					dp[i][j][b][1] = max(dp[i-1][j-1][b][1] + 1, max(dp[i-1][j-1][b-1][1] + 1, dp[i-1][j-1][b-1][0] + 1));
//					dp[i][j][b][1] = max(dp[i][j][b][1], 
//						max(max(dp[i-1][j][b][0], dp[i-1][j][b][1]), max(dp[i][j-1][b][0], dp[i][j-1][b][1])));
				}
				
				dp[i][j][b][0] = max(max(dp[i-1][j][b][0], dp[i][j-1][b][0]), max(dp[i-1][j][b][1], dp[i][j-1][b][1]));
				
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int b = 0; b < 2; b++){
				ans = max(ans, dp[i][j][k][b]);
			}
		}
	}
	
	assert(ans >= k);
	
	tr(ans);
	
	return 0; 
}
