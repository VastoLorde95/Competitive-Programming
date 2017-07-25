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

const ll MOD = 1e9 + 7;
const int N = 2010;

int n, m;
string s;

ll dp[N][N];
ll dp2[N][N];

int main(){ _
	cin >> n >> m >> s;
	
	int cnt = 0, mn = 0;
	for(int i = 0; i < m; i++){
		if(s[i] == '(') cnt++;
		else cnt--;
		mn = min(mn, cnt);
	}
	
	mn = -mn;
	int del = n-m;
	
	if(mn > del){
		cout << 0 << endl;
		return 0;
	}
	
	dp[0][0] = 1;
	for(int i = 1; i <= del; i++){
		for(int j = 0; j <= i; j++){
			if(j > 0){
				dp[i][j] += dp[i-1][j-1];
				if(dp[i][j] >= MOD) dp[i][j] -= MOD;
			}
			dp[i][j] += dp[i-1][j+1];
			if(dp[i][j] >= MOD) dp[i][j] -= MOD;
		}
	}

	for(int i = 0; i <= del; i++){
		for(int j = mn; j <= i; j++){
			if(j+cnt <= del){
				dp2[del-i][j+cnt] += dp[i][j];
				if(dp2[del-i][j+cnt] >= MOD) dp2[del-i][j+cnt] -= MOD;
			}
		}
	}

	for(int i = del; i >= 0; i--){
		for(int j = 0; j <= n; j++){
			dp2[i][j] += dp2[i+1][j+1];
			if(dp2[i][j] >= MOD) dp2[i][j] -= MOD;
			if(j > 0){
				dp2[i][j] += dp2[i+1][j-1];
				if(dp2[i][j] >= MOD) dp2[i][j] -= MOD;
			}
		}
	}
	
	cout << dp2[0][0] << endl;
	
	return 0;
}
