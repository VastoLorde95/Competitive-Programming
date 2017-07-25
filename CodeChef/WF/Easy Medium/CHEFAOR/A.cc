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

const int N = 5010;

int a[N];
int sor[N][N];
ll dp[N][N];
int K[N][N];

void solve(){
	int n, k;
	sd2(n,k);

	for(int i = 0; i < n; i++) sd(a[i]);
	
	for(int i = 0; i < n; i++){
		int val = 0;
		for(int j = i; j < n; j++){
			val |= a[j];
			sor[i][j] = val;
		}
	}
	
	for(int j = 1; j <= k; j++){
		K[j][n] = n-1;
		for(int i = n-1; i >= 0; i--){
			K[j][i] = 0;
			dp[j][i] = sor[0][i];
			
			for(int r = K[j-1][i]; r <= K[j][i+1]; r++){
				ll val = ((r > 0) ? dp[j-1][r-1] : 0) + sor[r][i];
				if(val > dp[j][i]){
					dp[j][i] = val;
					K[j][i] = r;
				}
			}
		}
	}
	
	printf("%lld\n", dp[k][n-1]);
}



int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
