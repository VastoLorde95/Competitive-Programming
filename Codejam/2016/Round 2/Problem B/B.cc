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
typedef long double ld;

const int N = 201;

double p[N];
ld dp[N][N];
int n, k;

ld get(vector<int> &pr){
	memset(dp, 0, sizeof dp);
	
	int nn = pr.size();
	dp[0][1] = p[pr[0]];
	dp[0][0] = 1.0f - p[pr[0]];
	for(int i = 1; i < nn; i++){
		for(int j = 0; j <= i+1; j++){
			if(j > 0)
				dp[i][j] = dp[i-1][j-1] * p[pr[i]] + dp[i-1][j] * (1.0f - p[pr[i]]);
			else
				dp[i][j] = dp[i-1][j] * (1.0f - p[pr[i]]);
		}
	}
	
	return dp[nn-1][k/2];
}

void solve(){
	sd2(n,k);
	for(int i = 1; i <= n; i++){
		scanf("%lf", p+i);
	}

	sort(p+1, p+n+1);
	
	ld ans = 0;
	
	for(int i = 1; i+k-1 <= n; i++){
		vector<int> pr;
		for(int j = i; j <= i+k-1; j++){
			pr.pb(j);
		}
		
		ans = max(ans, get(pr));
		
	}
	
	printf("%.9lf\n", (double) ans);
	
}

int main(){
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
