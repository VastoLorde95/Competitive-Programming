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
const int MOD = 1e9 + 7;

char s[N];
int cnt[N][2];
int dp[2][N];
int p[N];

int c[N][N];

void solve(){
	int n, k;
	sd2(n,k);
	scanf("%s", s);
	
	memset(p, 0, sizeof p);
	
	for(int i = 1; i < n; i++){
		if(n%i) continue;
		
		for(int j = 0; j < i; j++) cnt[j][0] = cnt[j][1] = 0;
		
		for(int j = 0; j < n; j++){
			cnt[j%i][s[j]-'0']++;
		}
		
		for(int j = 0; j <= k; j++) dp[0][j] = 0;
		dp[0][0] = 1;
		
		int id = 0;
		for(int j = 0; j < i; j++){
			id ^= 1;
			
			for(int t = 0; t <= k; t++){
				dp[id][t] = 0;
			}
			
			for(int t = k; t >= 0; t--){
				if(!dp[1-id][t]) continue;
				if(t + cnt[j][0] <= k)
					(dp[id][t+cnt[j][0]] += dp[1-id][t]) %= MOD;
				if(t + cnt[j][1] <= k)
					(dp[id][t+cnt[j][1]] += dp[1-id][t]) %= MOD;
			}
		}
		
		for(int j = 0; j <= k; j++){
			p[i] += dp[id][j];
			if(p[i] >= MOD) p[i] -= MOD;
		}
		
		for(int j = 1; j < i; j++){
			if(i % j == 0){
				p[i] -= p[j] - MOD;
				if(p[i] >= MOD) p[i] -= MOD;
			}
		}
	}
	
	int per = 0;
	for(int i = 1; i < n; i++){
		per += p[i];
		if(per >= MOD) per -= MOD;
	}
	
	int tot = 0;
	for(int i = 0; i <= k; i++){
		tot += c[n][i];
		if(tot >= MOD) tot -= MOD;
	}
	
	tot -= per - MOD;
	if(tot >= MOD) tot -= MOD;
	
	printf("%d\n", tot);
	
	return;
}

int main(){
	c[0][0] = 1;
	for(int i = 1; i < N; i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++){
			c[i][j] = c[i-1][j] + c[i-1][j-1];
			if(c[i][j] >= MOD) c[i][j] -= MOD;
		}
	}
	
	int t; sd(t);
	while(t--) solve();
	return 0;
}
