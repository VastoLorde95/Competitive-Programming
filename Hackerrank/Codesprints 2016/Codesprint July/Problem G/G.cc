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

const int N = 5010;

ll w[N], x[N];
ll dp1[2][N];
ll dp2[2][N];
ll cost[N][N];

int main(){
	int n, k;
	sd2(n,k);
	
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld", x+i,w+i);
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			cost[j][i] = cost[j-1][i] + (w[j] * (x[j] - x[i]));
		}
		for(int j = i-1; j >= 0; j--){
			cost[j][i] = cost[j+1][i] + (w[j] * (x[i] - x[j]));
		}
	}
	
	int id = 1;
	dp1[1][1] = 0;
	dp2[1][1] = 0;
	for(int i = 2; i <= n; i++){
		dp2[id][i] = cost[1][i];
		dp1[id][i] = dp2[id][i];
		for(int j = 1; j < i; j++){
			dp1[id][i] = min(dp1[id][i], dp2[id][j] + cost[i][j]);
		}
	}
	
	for(int m = 2; m <= k; m++){
		id ^= 1;
		
		int pos1 = m-1, pos2 = m;				
		for(int i = m; i <= n; i++){
			int hi = i-1; ll mn = 1ll << 60;
			for(int j = pos1; j <= hi; j++){
				ll x = dp1[id^1][j] + cost[j+1][i];
				if(x < mn){
					mn = x;
					pos1 = j;
				}
			}
			
			dp2[id][i] = mn;
			
			hi = i, mn = 1ll << 60;
			for(int j = pos2; j <= hi; j++){
				ll x = dp2[id][j] + cost[i][j];
				if(x < mn){
					mn = x;
					pos2 = j;
				}
			}
			
			dp1[id][i] = mn;
		}
	}
	printf("%lld\n", dp1[id][n]);
	
	
	return 0;
}
