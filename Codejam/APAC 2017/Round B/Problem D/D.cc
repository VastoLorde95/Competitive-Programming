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

const int N = 5100;

ll f[N], tmp;
int n, m, dp1[N], dp2[N], dp3[N];

int solve(){
	sd2(n,m);
	
	f[0] = 1;
	for(int i = 1; i <= n; i++) f[i] = f[i-1] * i % m;
	
	dp1[0] = dp2[0] = dp3[0] = 0;
	
	for(int i = 1; i <= n; i++){
		dp3[i] = f[i];
		for(int j = 1; j < i; j++){
			dp3[i] -= f[i-j] * dp3[j] % m;
			if(dp3[i] < 0) dp3[i] += m;
		}
	}
	
	for(int i = 1; i <= n; i++){
		dp1[i] = dp2[i] = 0;
		for(int j = 1; j <= i; j++){
			tmp = dp1[i-j] + f[i-j];
			if(tmp >= m) tmp -= m;
			
			dp1[i] += tmp * dp3[j] % m;
			if(dp1[i] >= m) dp1[i] -= m;
			
			tmp = dp2[i-j] + f[i-j];
			if(tmp >= m) tmp -= m;
			tmp = tmp + dp1[i-j] * 2 % m;
			
			dp2[i] += tmp * dp3[j] % m;
			if(dp2[i] >= m) dp2[i] -= m;
		}
	}
	return dp2[n];
}

int main(){
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}
