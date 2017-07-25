#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 1011;

string a, b, c, d;
int t;

int dp[N][N];
int dp2[N][N][2];

int cnt1[N], cnt2[N];

int x[26], y[26];

int main(){ _
	cin >> t;
	while(t--){
		cin >> a;
		cin >> b;
		
		int n = a.length();
		int m = b.length();
		
		for(int i = 0; i < n; i++){
			cnt1[a[i]-'a']++;
		}
		for(int i = 0; i < m; i++){
			cnt2[b[i]-'a']++;
		}
		
		c = a;
		d = b;
		reverse(c.begin(), c.end());
		reverse(d.begin(), d.end());
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i-1] == c[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		
		int l1 = dp[n][n];
		
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				if(b[i-1] == d[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		
		int l2 = dp[m][m];
		
		if(l1%2 != 1 or l2%2 != 1){
			printf("%d\n", l1+l2);
		}
		else{
			memset(x, 0, sizeof x);
			memset(y, 0, sizeof y);
			
			int mx = l1+l2-1;

			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(a[i-1] == c[j-1]){
						dp[i][j] = dp[i-1][j-1] + 1;
					}
					else{
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
					}
				}
			}

			for(int i = 1; i <= n; i++){
				int c = a[i-1]-'a';
				x[c] = max(x[c], 1 + 2*dp[i-1][n-i]);
			}
			
			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= m; j++){
					if(b[i-1] == d[j-1]){
						dp[i][j] = dp[i-1][j-1] + 1;
					}
					else{
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
					}
				}
			}
			
			for(int i = 1; i <= m; i++){
				int c = b[i-1]-'a';
				y[c] = max(y[c], 1 + 2*dp[i-1][m-i]);
			}
			
			for(int i = 0; i < 26; i++){
				mx = max(mx, x[i]+y[i]);
			}
			
			printf("%d\n", mx);
			
		}
		
	}
	return 0;
}

