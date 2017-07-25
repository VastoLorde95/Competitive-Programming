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

const int N = 2010;
int p[N], rnk[N], size[N];
const ll MOD = 1e9 + 7;

void create(int x){
	p[x] = x, rnk[x] = 0;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	if(rnk[px] > rnk[py]) p[py] = px;
	else p[px] = py;
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}

int ss[N][N];

void solve(){
	int n, m;
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		create(i);
		for(int j = 1; j <= n; j++){
			ss[i][j] = 0;
	}
	
	for(int i = 0; i < m; i++){
		int l, r; sd2(l,r);
	
		for(int j = l, k = r; j < k; j++, k--){
			if(ss[j][k]) break;
			merge(j,k);
			ss[j][k] = 1;
		}
	}
	
	set<int> s;
	for(int i = 1; i <= n; i++){
		s.insert(find(i));
	}
	
	int x = s.size();
	ll ans = 1;
	
	while(x--){
		ans = ans * 26 % MOD;
	}
	
	printf("%lld\n", ans);
	
	
}

int main(){
	int t; sd(t);
	while(t--) solve();	
	return 0;
}
