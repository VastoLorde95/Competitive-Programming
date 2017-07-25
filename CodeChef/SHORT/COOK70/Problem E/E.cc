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

const int N = 11;

bitset<N> dp[N];
int coins[15] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};

int main(){
	dp[0][0] = 1;
	for(int i = 1; i < N; i++){
		dp[i] = (dp[i-1] << 1) | (dp[i-1]);
		for(int j = 1; j < 15; j++){
			if(coins[j] > i) break;
			dp[i] &= ((dp[i-coins[j]] << coins[j]) | dp[i-coins[j]]);
		}
		dp[i][i] = 1;
	}

	for(int i = 1; i < N; i++){
		tr(meta, i, dp[i]);
	}	
	
	int t; sd(t);
	for(int i = 0; i < t; i++){
		int c, l;
		sd2(c,l);
		
		for(int j = c; j >= l; j--){
			if(dp[j].test(l)){
				printf("%d\n", j);
				break;
			}
		}
	}
	return 0;
}
