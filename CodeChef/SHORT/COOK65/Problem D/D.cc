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

#define meta __FUNCTION__,__LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 9;
const int M = 19;
const int MAX_SUM = 80;
const int STATE = 3;

const int MOD = 1e9 + 7;

int n, s[N];
ll x[N];

int dp[M][N][1 << N][MAX_SUM][STATE];

void add(int &x, int y){
	x += y; if(x >= MOD) x -= MOD;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d %lld", s+i, x+i);
	
	dp[0][0][0][0][0] = 1;
	
	for(int i = 0; i < M-1; i++){
		// compute the number of ways we can obtain a certain 'sum' with a given 'mask' and 'state' and 'sum' in the previous step
		// by assigning different digits on the i'th position for each of the n numbers in the vector
		for(int j = 0; j < n; j++){
			for(int mask = 0; mask < (1 << n); mask++){
				for(int sum = 0; sum < MAX_SUM; sum++){
					for(int state = 0; state < 3; state++){
						int val = dp[i][j][mask][sum][state], d = x[j] % 10;
						
						if(val == 0) continue;
						
						int next_mask = mask & ((1 << n) - 1 - (1 << j)), bit = s[j];
						for(int nd = 0; nd < d; nd++){
							add(dp[i][j + 1][next_mask | (bit << j)][sum + nd][state], val);
						}
						
						add(dp[i][j + 1][mask][sum + d][state], val);
						
						bit ^= 1;
						for(int nd = d+1; nd < 10; nd++){
							add(dp[i][j + 1][next_mask | (bit << j)][sum + nd][state], val);	
						}
					}
				}
			}
		}
		
		// now given the given final mask and the sum that this kind of profile can make,
		// we can find out the state and the carry over in the next iteration i.e. choosing the i'th digits
		// of each element of v
		for(int mask = 0; mask < (1 << n); mask++){
			for(int sum = 0; sum < MAX_SUM; sum++){
				int carry = sum / 10, d = sum % 10;
				if(d != 7){
					add(dp[i+1][0][mask][carry][0], dp[i][n][mask][sum][0]);
					if(d != 4) add(dp[i+1][0][mask][carry][0], dp[i][n][mask][sum][1]);
				}
				else{
					add(dp[i+1][0][mask][carry][1], dp[i][n][mask][sum][0]);
					add(dp[i+1][0][mask][carry][1], dp[i][n][mask][sum][1]);
				}
				
				
				add(dp[i+1][0][mask][carry][2], dp[i][n][mask][sum][2]);
				if(d == 4) add(dp[i+1][0][mask][carry][2], dp[i][n][mask][sum][1]);
			}
		}
		
		for(int j = 0; j < n; j++) x[j] /= 10;
	}
	
	int ans = dp[M-1][0][0][4][1];
	for(int i = 0; i < 10; i++) add(ans, dp[M-1][0][0][i][2]);
	
	printf("%d\n", ans);
		
	return 0;
}
