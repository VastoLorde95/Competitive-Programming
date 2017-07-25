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

const int N = 501;
const int B = 300300;
const int base = 130000;
const int INF = 1e9;

int dp[2][B];

int iter;

pair<int, int> compute(vector<int> &v, int sum){
	int up = base+sum;
//	for(int i = base-sum; i <= up; i++) dp[0][i] = 0;
//	for(int i = 0; i < B; i++){
//		dp[0][i] = 0;
//	}
	dp[0][base+v[0]] = ++iter;
	dp[0][base-v[0]] = iter;
	
	int n = v.size(), id = 0;
	
//	int iter = 1;
	sum = v[0];
	for(int i = 1; i < n; i++){
		id ^= 1;
		++iter;
		for(int j = base-sum; j <= base+sum; j++){
			if(dp[1-id][j] == iter-1){
//				tr(meta, j-base, j-base+v[i], j-base-v[i], v[i], i);
				dp[id][j-v[i]] = iter;
				dp[id][j+v[i]] = iter;
			}
		}
		sum += v[i];
//		for(int j = base-sum; j <= base+sum; j++){
//			tr(meta, j-base, dp[id][j], dp[1-id][j]);
//		}
	}
	
	return mp(id, iter);
}

int n;
vector<int> h, v;

void solve(){
	sd(n);
	
	int a; sd(a);
	char c;
	
	h.clear();
	v.clear();
	
	int x;	
	for(int i = 0; i < n; i++){
		scanf(" %c %d", &c, &x);
		if(i&1) v.pb(x);	
		else h.pb(x);
	}
	
	if(n <= 2){
		printf("NO\n");
		return;
	}
	
//	tr(meta, v);
//	tr(meta, h);
	
	int sum = 0;
	foreach(it, h) sum += *it;
	
	pii p = compute(h, sum);
	int id = p.fi, iter = p.se;

	int ans = 0;
	
	int mn = INF;
	if(dp[id][base] != iter){
		int up = base+sum;
		for(int i = base-sum; i <= up; i++){
			if(dp[id][i] == iter) mn = min(mn, abs(i - base));
		}
	}
	else
		mn = 0;
	ans += mn;
	
//	tr(meta, mn);
	
	sum = 0;
	foreach(it, v) sum += *it;
	p = compute(v, sum); 
	id = p.fi, iter = p.se; 
	
	mn = INF;
	if(dp[id][base-a] == iter and a <= sum)
		mn = 0;
	else{
		int up = base + sum;
		for(int i = base-sum; i <= up; i++){
			if(dp[id][i] == iter) mn = min(mn, abs(i - base + a));
		}
	}
	
//	tr(meta, mn, dp[id][base-a], iter);
	
	ans += mn;
	
	if(ans >= INF){
		assert(1 < 0);
		printf("NO\n");
		return;
	}
	
	printf("%d\n", ans);
	
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
