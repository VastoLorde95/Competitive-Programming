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

const int N = 50100;
const ll INF = 1ll << 60;

vector<int> g[N];
map<ll, int> s[N];
int ptr[N];
ll c[N];
ll up1[N], up2[N];
ll ans, sum;

void makeSets(int x, int p){
	int mx = 0, id = -1, sid = -1;
	
	foreach(it, g[x]){
		if(*it == p) continue;
		makeSets(*it, x);
		
		c[x] += c[*it];
		if(s[ptr[*it]].size() > mx){
			mx = s[ptr[*it]].size(), id = ptr[*it], sid = *it;
		}
	}
	
	if(id == -1){
		ptr[x] = x;
		s[x][c[x]]++;
	}
	else{
		ptr[x] = id;

		foreach(it, g[x]){
			if(*it == p or *it == sid) continue;
			foreach(jt, s[ptr[*it]]){
				s[ptr[x]][jt->fi] += jt->se;
			}
		}
		s[ptr[x]][c[x]]++;
		
	}
	
	if(c[x] >= sum - c[x] and c[x] <= (sum - c[x]) * 2){
		ll t = sum - c[x], tm = c[x] - (sum - c[x]);
		int id = ptr[x];
		if(s[id][t] > 0 or s[id][tm] > 0){
			ans = min(ans, t - tm);	
		}
	}
	
	if(c[x] >= sum - c[x] and c[x] >= (sum - c[x]) * 2 and c[x] % 2 == 0 and c[x] != 0){
		ll t = c[x] / 2;
		int id = ptr[x];
		if(s[id][t] > 0){
			ans = min(ans, t - (sum - c[x]));	
		}
	}
	
	if(c[x] <= sum - c[x] and c[x] * 2 >= sum - c[x]){
		int id = ptr[x];
		up1[x] = s[id][c[x]];
		up2[x] = s[id][(sum - c[x]) - c[x]];
	}
}

void solve(){
	int n; sd(n);
	
	ans = INF;
	sum = 0;
	
	for(int i = 1; i <= n; i++){
		g[i].clear();
		s[i].clear();
		ptr[i] = i;
		scanf("%lld", c+i);
		sum += c[i];
		up1[i] = up2[i] = -1;
	}
	
	for(int i = 1; i < n; i++){
		int x, y; sd2(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	
	makeSets(1,-1);
	
	for(int i = 2; i <= n; i++){
		if(up1[i] == -1) continue;
		
		ll t = c[i], tm = sum - t * 2;
		int id = ptr[1];
		if(s[id][t] > up1[i] or s[id][tm] > up2[i]){
			ans = min(ans, t - tm);
		}
	}
	
	if(ans == INF) ans = -1;
	
	printf("%lld\n", ans);
	
}

int main(){
	int q; sd(q);
	while(q--) solve();
	return 0;
}
