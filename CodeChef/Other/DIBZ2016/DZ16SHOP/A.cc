#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, A)  __typeof(A) x(A)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
ll l = v.size(); for(ll i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 310;
const ll INF = (1ll<<40);

// min cost bipartite matching, to make it max profit, negate the cost matrix during initialization

int n, matchingCount;
ll res, cost[N][N], lx[N], ly[N];
int match[N][N], mate1[N], mate2[N], pre1[N], pre2[N];
ll p[N];
int pi[N];

pii q[N*2];
int front, back;

void addEdge(int i, int j, ll c){ cost[i][j] = c; }

void reinitialize(int _n){
	n = _n;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) match[i][j] = 0;
}

void dualInitialization(){
	res = 0;
	for(int i = 1; i <= n; i++){
		lx[i] = cost[i][1];
		for(int j = 2; j <= n; j++) lx[i] = min(lx[i], cost[i][j]);
	}
	
	for(int j = 1; j <= n; j++){
		ly[j] = cost[1][j] - lx[1];
		for(int i = 2; i <= n; i++) ly[j] = min(ly[j], cost[i][j] - lx[i]);
	}
	
}

void primalInitialization(){
	for(int i = 1; i <= n; i++) mate1[i] = mate2[i] = -1;
	matchingCount = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(mate2[j] == -1 and cost[i][j] - lx[i] - ly[j] == 0){
				match[i][j] = 1;
				matchingCount++;
				mate1[i] = j, mate2[j] = i;
				res += cost[i][j];
				break;
			}
		}
	}
}

void pathInitialization(){
	for(int i = 1; i <= n; i++){
		pre1[i] = pre2[i] = -1;
		p[i] = INF, pi[i] = -1;
	}

	front = back = 0;
	for(int i = 1; i <= n; i++){
		if(mate1[i] == -1){
			pre1[i] = 0;
			q[back++] = mp(i,0);				
			for(int j = 1; j <= n; j++){
				ll tmp = cost[i][j] - lx[i] - ly[j];
				if(tmp < p[j]) p[j] = tmp, pi[j] = i;
			}
		}
	}
}

void labelingPropogation(int &path){
	while(front < back){
		int u = q[front].fi, type = q[front].se; front++;
		if(type == 0){
			// propogation occurs along edges that are not part of the current partial matching and with zero reduced cost
			for(int j = 1; j <= n; j++){
				if(pre2[j] == -1 and cost[u][j] - lx[u] - ly[j] == 0){
					pre2[j] = u;
					q[back++] = mp(j,1);
				}
			}
		}
		else{
			// propogation occurs along edges belonging to the current parital mathching
			int v = mate2[u];
			if(v != -1){
				if(pre1[v] == -1){
					pre1[v] = u;
					q[back++] = mp(v,0);						
					for(int j = 1; j <= n; j++){
						ll tmp = cost[v][j] - lx[v] - ly[j];
						if(pre2[j] == -1 and tmp < p[j]) p[j] = tmp, pi[j] = v;
					}
				}
			}
			else{
				path = u; break;
			}
		}
	}
}	

void dualIteration(){
	ll del = INF;
	// find the least reduced cost along unlabeled columns corresponding to labeled rows
	for(int j = 1; j <= n; j++) if(pre2[j] == -1) del = min(del, p[j]);
	for(int i = 1; i <= n; i++) if(pre1[i] != -1) lx[i] += del;
	for(int j = 1; j <= n; j++){
		if(pre2[j] != -1) ly[j] -= del;
		else{
			p[j] -= del;
			if(p[j] == 0){
				pre2[j] = pi[j];
				q[back++] = mp(j,1);
			}
		}
	}
}

void primalIteration(int &path){
	int j = path, i;
	while(j != 0){
		i = pre2[j];
		mate1[i] = j, mate2[j] = i;
		match[i][j] = 1;
		matchingCount++;
		res += cost[i][j];

		j = pre1[i];
		if(j != 0){
			match[i][j] = 0;
			res -= cost[i][j];
			matchingCount--;
		}
	}
}

ll minCostBipartiteMatching(){
	dualInitialization();
	primalInitialization();
	
	while(matchingCount < n){
		// initialize the path variables for the next augmentation
		pathInitialization();
		
		int path = -1;
		while(path == -1){
			// search for an augmenting path in the current equality subgraph
			while(path == -1 and front < back) labelingPropogation(path);
			// path was not found, make some new node admissible and try again
			if(path == -1) dualIteration();
		}
		// augment the current matching via the augmenting path
		primalIteration(path);
	}
	return res;
}

const int M = 10100;
int X[N], Y[N], P[N];
int A[M];
int countingSort[M/10];

void solve(){
	int n, m;
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		sd3(X[i], Y[i], P[i]);
	}
	
	memset(countingSort, 0, sizeof countingSort);

	const ll inf = 1e9 + 1;
	
	int mx = 0, mn = inf;
	for(int i = 1; i <= m; i++){
		sd(A[i]);
		countingSort[A[i]]++;
		mx = max(mx, A[i]);
		mn = min(mn, A[i]);
	}

	m = min(m, n);
	
	for(int i = mx, j = 1; i >= mn and j <= m ; i--){
		while(j <= m and countingSort[i] > 0){
			A[j++] = i;
			countingSort[i]--;
		}
	}
	
	reinitialize(n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(X[i] + Y[i] <= A[j]) cost[i][j] = (1ll*Y[i]*P[i]) + (ll) (A[j] - X[i] - Y[i]) * inf;
			else if(X[i] <= A[j]) cost[i][j] = (ll) (A[j] - X[i]) * P[i];
			else cost[i][j] = 0;
		}
		if(m < n) for(int j = m+1; j <= n; j++) cost[i][j] = 0;
	}
	
	int maxgoods = 0;
	for(int i = 1; i <= m; i++) maxgoods += A[i];
	
	ll cost = minCostBipartiteMatching();
	printf("%d %d\n", (int) (maxgoods - cost/inf), (int) (cost%inf));
}

int main(){
	int t; sd(t);
	while(t--){
		solve();
	}
	return 0;
}
