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

const int N = 200100;
const int MOD = 1e9 + 7;

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}


int n;
int nxt[N];

int vis[N];
int ts[N], tme;
int done[N];

int tot;
ll ans = 1;

void dfs(int x){
	if(vis[x]){
		if(done[x]) return;
		ans *= (fast(2, tme - ts[x] + 1) - 2 + MOD) % MOD;
		ans %= MOD;
		tot += tme - ts[x] + 1;		
		return;
	}
	
	vis[x] = 1;
	ts[x] = ++tme;
	
	dfs(nxt[x]);
	
	done[x] = 1;
}


int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		sd(nxt[i]);
	}
	
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	
	ans *= fast(2, n - tot);
	ans %= MOD;
	
	cout << ans << endl;
	
	
	return 0;
}
