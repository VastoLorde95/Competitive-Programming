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

const int N = 510;

int dp[2][N][N];
int n, k;
int c[N];

int main(){
	sd2(n,k);
	for(int i = 1; i <= n; i++){
		sd(c[i]);
	}
	
	dp[0][0][0] = 1;
	int id = 0;
	for(int i = 1; i <= n; i++){
		id ^= 1;
		for(int j = 0; j <= k; j++){
			for(int r = 0; r <= j; r++){
				dp[id][j][r] = dp[1-id][j][r];
			}
		}
		for(int j = 0; j <= k; j++){
			for(int r = 0; r <= j; r++){
				if(dp[1-id][j][r] and j + c[i] <= k){
					dp[id][j+c[i]][r] = 1;
					dp[id][j+c[i]][r+c[i]] = 1;
				}
			}
		}
	}
	
	vector<int> ans;
	for(int i = 0; i <= k; i++){
		if(dp[id][k][i]) ans.pb(i);
	}
	
	printf("%d\n", (int) ans.size());
	foreach(it, ans) printf("%d ", *it); puts("");
	return 0;
}
