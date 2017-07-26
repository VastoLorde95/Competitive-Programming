#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

typedef long long ll;

const int N = 1000100;

ll MOD = 1e9 + 7;

int n, k;
ll a[N];
ll sum1[N], sum2[N], res[N];

int main(){
	sd2(n,k);
	for(ll i = 1; i <= n; i++){
		scanf("%lld",a+i);
		sum1[i] = a[i]%MOD;
		sum2[i] = (a[i]*((i*i)%MOD))%MOD;
	}
	
	for(ll i = 1; i <= n; i++){
		sum1[i] += sum1[i-1];
		if(sum1[i] >= MOD) sum1[i] -= MOD;
		sum2[i] += sum2[i-1];
		if(sum2[i] >= MOD) sum2[i] -= MOD;
	}
	
	ll sum3 = 0;
	for(ll i = 1; i <= k; i++){
		sum3 += ((i-1)*a[i])%MOD;
		if(sum3 >= MOD) sum3 -= MOD;
	}
	
	res[1] = sum2[k];
	for(ll i = 2; i <= n-k+1; i++){
		ll term = (sum1[i+k-2] - sum1[i-1] + MOD)%MOD;
		sum3 = (sum3 - term + MOD)%MOD;
		sum3 = (sum3 + (((1ll*(k-1))*a[i+k-1])%MOD))%MOD;;
		res[i] = (sum2[i+k-1]-sum2[i-1]+MOD)%MOD;
		res[i] = (res[i] - ((((1ll*i)*i-1)%MOD)*((sum1[i+k-1]-sum1[i-1]+MOD)%MOD))%MOD + MOD)%MOD;
		res[i] = (res[i] - (((2ll*(i-1))*sum3)%MOD) + MOD)%MOD;
	}
	
	for(int i = 1; i <= n-k+1; i++){
		printf("%lld ", res[i]);
	}
	puts("");
	
	return 0;
}
