#include <bits/stdc++.h>
 
#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
 
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
 
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
#define func __FUNCTION__
#define line __LINE__
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pii;
 
template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}
 
template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
ll l = v.size(); for(ll i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}
 
void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}
 
const ll N = 310;
const ll INF = (1ll<<50);
 
// min cost bipartite matching, to make it max profit, negate the cost matrix during initialization
struct Hungarian{
	ll n, card;
	ll res;
	ll cost[N][N];
	ll x[N][N];
	ll lX[N], lY[N];
	ll mateX[N], mateY[N];
	
	ll pre1[N], pre2[N];
	ll p[N], pi[N];
	
	Hungarian(ll _n) : n(_n) { };
	
	void addEdge(ll i, ll j, ll c){
		cost[i][j] = c;
	}
	
	void dualInitialization(){
		res = 0;
		for(ll i = 1; i <= n; i++){
			lX[i] = INF;
			for(ll j = 1; j <= n; j++){
				lX[i] = min(lX[i], cost[i][j]);
			}
		}
		
		for(ll j = 1; j <= n; j++){
			lY[j] = INF;
			for(ll i = 1; i <= n; i++){
				lY[j] = min(lY[j], cost[i][j] - lX[i]);
			}
		}
		
	}
	
	void primalInitialization(){
		for(ll i = 1; i <= n; i++) mateX[i] = mateY[i] = -1;
		card = 0;
		
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				if(cost[i][j] - lX[i] - lY[j] == 0 and mateX[i] == -1 and mateY[j] == -1){
					x[i][j] = 1;
					card++;
					mateX[i] = j;
					mateY[j] = i;
					res += cost[i][j];
				}
			}
		}
	}
	
	void pathInitialization(queue<pii> &q){
		for(ll i = 1; i <= n; i++){
			pre1[i] = pre2[i] = -1;
			p[i] = INF;
			pi[i] = -1;
		}
 
		for(ll i = 1; i <= n; i++){
			if(mateX[i] == -1){
				pre1[i] = 0;
				q.push(mp(i,0));
				
				for(ll j = 1; j <= n; j++){
					if(cost[i][j] - lX[i] - lY[j] < p[j]){
						p[j] = cost[i][j] - lX[i] - lY[j];
						pi[j] = i;
					}
				}
			}
		}
	}
	
	void labelingPropogation(queue<pii> &q, ll &path){
		while(!q.empty()){
			ll u = q.front().fi, v = q.front().se; q.pop();
			
			if(v == 0){
				for(ll j = 1; j <= n; j++){
					if(pre2[j] == -1 and cost[u][j] - lX[u] - lY[j] == 0){
						pre2[j] = u;
						q.push(mp(j,1));
					}
				}
			}
			else{
				ll v = mateY[u];
				if(v != -1){
					if(pre1[v] == -1){
						pre1[v] = u;
						q.push(mp(v,0));
						
						for(ll j = 1; j <= n; j++){
							if(cost[u][j] - lX[u] - lY[j] < p[j]){
								p[j] = cost[u][j] - lX[u] - lY[j];
								pi[j] = u;
							}
						}
						
					}
				}
				else{
					path = u;
				}
			}
		}
	}	
	
	void dualIteration(queue<pii> &q){
		ll del = INF;
		for(ll j = 1; j <= n; j++){
			if(pre2[j] == -1) del = min(del, p[j]);
		}
		
		for(ll i = 1; i <= n; i++){
			if(pre1[i] != -1) lX[i] += del;
		}
		
		for(ll j = 1; j <= n; j++){
			if(pre2[j] != -1) lY[j] -= del;
		}
		
		for(ll j = 1; j <= n; j++){
			if(pre2[j] == -1) p[j] -= del;
		}
		
		for(ll j = 1; j <= n; j++){
			if(pre2[j] == -1 and p[j] == 0){
				pre2[j] = pi[j];
				q.push(mp(j,1));
			}
		}
	}
	
	void primalIteration(ll &path){
		ll j = path;
		while(j != 0){
			ll i = pre2[j];
			mateX[i] = j;
			mateY[j] = i;
			x[i][j] = 1;
			card++;
			res += cost[i][j];
			
			j = pre1[i];
			if(j != 0){
				x[i][j] = 0;
				res -= cost[i][j];
				card--;
			}
		}
	}
	
	ll minCostBipartiteMatching(){
		dualInitialization();
		primalInitialization();
		
		while(card < n){
			queue<pii> q;
			pathInitialization(q);
			
			ll path = -1;
			
			while(path == -1){
				while(path == -1 and !q.empty()) labelingPropogation(q, path);
				if(path == -1) dualIteration(q);
			}
			primalIteration(path);
		}
		return res;
	}
};
 
const int M = 10100;
ll X[N], Y[N], P[N];
ll A[M];
 
void solve(){
	ll n, m; sd2(n,m);
	for(ll i = 1; i <= n; i++){
		sd3(X[i], Y[i], P[i]);
	}
	
	for(ll i = 1; i <= m; i++){
		sd(A[i]);
	}
	
	sort(A+1, A+m+1, greater<ll>());
	
	m = min(m, n);
	
	Hungarian *h = new Hungarian(n);
	
	const ll inf = 1e9 + 1;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			if(X[i] + Y[i] <= A[j]) h->addEdge(i, j, Y[i]*P[i] + (A[j] - X[i] - Y[i]) * inf);
			else if(X[i] <= A[j]) h->addEdge(i, j, (A[j] - X[i]) * P[i]);
			else h->addEdge(i, j, 0);
		}
		if(m < n){
			for(ll j = m+1; j <= n; j++){
				h->addEdge(i, j, 0);
			}
		}
	}
	
	ll maxgoods = 0;
	for(ll i = 1; i <= m; i++) maxgoods += A[i];
	
	ll cost = h->minCostBipartiteMatching();
	printf("%lld %lld\n", maxgoods - cost/inf, cost%inf);
}
 
int main(){
	ll t; sd(t);
	while(t--) solve();
	return 0;
}
