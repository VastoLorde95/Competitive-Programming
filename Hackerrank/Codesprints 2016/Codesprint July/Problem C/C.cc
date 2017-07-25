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

const int N = 1000100;
const int M = 26;
const ll MOD = 1e9 + 7;

ll cnt[N][M];
ll rcnt[N][M];
ll dp[M][M];

int main(){ _
	string s;
	cin >> s;
	
	vector<int> v;
	for(char c : s) v.pb(c-'a');
	
	int n = v.size();
	
	for(int i = 0; i < n; i++){
		int x = v[i];
		if(i == 0){
			cnt[i][x] = 1;
		}
		else{
			for(int j = 0; j < M; j++) cnt[i][j] = cnt[i-1][j];
			cnt[i][x]++;
		}
	}
	
	for(int i = n-1; i >= 0; i--){
		int x = v[i];
		if(i == n-1){
			rcnt[i][x] = 1;
		}
		else{
			for(int j = 0; j < M; j++) rcnt[i][j] = rcnt[i+1][j];
			rcnt[i][x]++;
		}
	}
	
	ll ans = 0;
	for(int i = n-1; i > 1; i--){
		int x = v[i], y = v[i-1];
		for(int j = 0; j < M; j++){
			dp[x][j] += rcnt[i+1][j];
			if(dp[x][j] >= MOD) dp[x][j] -= MOD;
		}
		
		for(int j = 0; j < M; j++){
			ans += cnt[i-2][j] * dp[y][j] % MOD;
			if(ans >= MOD) ans -= MOD;
		}
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}
