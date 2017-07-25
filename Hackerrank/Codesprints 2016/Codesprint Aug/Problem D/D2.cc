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

const int N = 1010;

char a[N];
char b[N];

int dp[N][N];

void solve(){
	scanf("%s%s",a,b);
	int n = strlen(a);
	int m = strlen(b);
	
	if(n < m){
		puts("NO");
		return;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dp[i][j] = 0;
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] <= 'Z'){
				cnt++;
				if(a[i] == b[j]){
					if(i-1 >= 0 and j-1 >= 0) dp[i][j] = dp[i-1][j-1];
					else if(i-1 >= 0) dp[i][j] = (cnt == 1);
					else if(j-1 >= 0) dp[i][j] = 0;
					else dp[i][j] = 1;
				}
				else dp[i][j] = 0;
			}
			else{
				if(a[i] - 32 == b[j]){
					if(i-1 >= 0 and j-1 >= 0) dp[i][j] = dp[i-1][j-1];
					else if(i-1 >= 0) dp[i][j] = (cnt == 0);
					else if(j-1 >= 0) dp[i][j] = 0;
					else dp[i][j] = 1;
					
					if(i-1 >= 0) dp[i][j] |= dp[i-1][j];
				}
				else{
					if(i-1 >= 0) dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	
	if(dp[n-1][m-1]) puts("YES"); else puts("NO");
	
}

int main(){
	int q; sd(q);
	while(q--) solve();
	return 0;
}
