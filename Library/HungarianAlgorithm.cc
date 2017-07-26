#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(match, a)  __typeof(a) match(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S match, const Strings&... rest){cout<<match<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

/*
Hungarian Alogrithm O(n^3) min cost bipartite matching. To make it max profit, negate the cost matrix.
Primal and Dual form a strong dual pair.

Dual constraints are:
=> lx and ly are unrestrained
=> lx(i) + ly(j) <= c(i,j)
=> Slack varaible = c'(i,j) = c(i,j) - lx(i) - ly(j) >= 0. Also called the reduced cost.
=> Complementary Slackness condition imply that c'(i,j) * x(i,j) = 0 i.e. an edge can belong to a partial matching iff its reduced
cost it 0.

reducedCost = cost(i,j) - lx(i) - ly(j)
*/

#define Cost ll

const int N = 310;
const Cost INF = (1ll<<40);

int n, matchingCount, match[N][N], matchx[N], matchy[N], pre1[N], pre2[N], pi[N];
Cost res, cost[N][N], lx[N], ly[N], p[N];

pii q[N*2];
int front, back;

void reinitialize(int _n){
	n = _n;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) match[i][j] = 0;
}

/*
Initialize any feasible dual solution
*/
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

/*
Find the primal solution corresponding to the complementary slackness conditions
CSC imply that only edges in the equality subgraph can be part of any partial matching
*/
void primalInitialization(){
	for(int i = 1; i <= n; i++) matchx[i] = matchy[i] = -1;
	matchingCount = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(matchy[j] == -1 and cost[i][j] - lx[i] - ly[j] == 0){
				match[i][j] = 1, matchingCount++;
				matchx[i] = j, matchy[j] = i;
				res += cost[i][j];
				break;
			}
		}
	}
}

/*
Initialize path variables for next bfs
*/
void pathInitialization(){
	for(int i = 1; i <= n; i++){
		pre1[i] = pre2[i] = -1;
		p[i] = INF, pi[i] = -1;
	}

	// empty the bfs queue
	front = back = 0;
	
	// since matching is not maximum, there exists at least one node in S such that matchx[i] = -1
	for(int i = 1; i <= n; i++){
		if(matchx[i] == -1){
			pre1[i] = 0;
			q[back++] = mp(i,0);				
			for(int j = 1; j <= n; j++){
				ll tmp = cost[i][j] - lx[i] - ly[j];
				if(tmp < p[j]) p[j] = tmp, pi[j] = i;
			}
		}
	}
}

/*
Breadth-First Search to find an augmenting path in the equality subgraph
*/
void findAugmentingPath(int &path){
	// all edges belong to the equality subgraph
	while(front < back){
		int u = q[front].fi, type = q[front].se; front++;
		if(type == 0){
			// propogation occurs along edges that are not part of the current partial matching
			for(int j = 1; j <= n; j++){
				if(pre2[j] == -1 and cost[u][j] - lx[u] - ly[j] == 0){
					pre2[j] = u;
					q[back++] = mp(j,1);
				}
			}
		}
		else{
			// propogation occurs along edges belonging to the current parital mathching
			int v = matchy[u];
			if(v != -1){
				if(pre1[v] == -1){	// so that we don't go backwards in the bfs
					pre1[v] = u;
					q[back++] = mp(v,0);						
					for(int j = 1; j <= n; j++){
						ll tmp = cost[v][j] - lx[v] - ly[j];
						if(pre2[j] == -1 and tmp < p[j]) p[j] = tmp, pi[j] = v;
					}
				}
			}
			else{
				// we have found an augmenting path
				path = u; break;
			}
		}
	}
}	

/*
Update dual solution

Find the least reduced cost 'del' along unlabeled columns corresponding to labeled rows. These correspond to edges which are 
not part of the current partial matching because they are not part of the equality subgraph (and edges in the perfect 
matching must belong to the equality subgraph due to complementary slackness conditions). Now we will update the current 
dual solution such that we get some new feasible edges (i.e. making at least one unreachable node in T reachable) in the equality
subgraph and at the same time we will remove all those edges (i,j) from the equality subgraph which are not part of the current
partial matching (i is unreachable, j is reachable but matchy[j] != i. Their reduced cost will become negative). Since these edges
are unreachable, they can't be part of any augmenting path as well, hence our search for an augmenting path won't be hindered by the
absence of this edge (we are just concerned about finding an augmenting path and not bothered about the actual contents of the
equality subgraph as long as we can guarantee improvement in our search).

If matching is not perfect (i.e. maximal but not maximum) then some augmenting path must exist. Eventually all nodes become reachable
after n iterations of this function and we are guaranteed to find an augmenting path since if matching is not maximum at least one node
in T has matchy[j] = -1.

Solution is updated as follows:
For all reachable edges with (i,j) unlabelled nodes in j, we add del to lx(i) i.e. subtract del from the reduced cost.
For all edges (i,j) which were already admissible, we subtract del from ly(j) to keep them admissible in the new solution as well

*/
void dualIteration(){
	Cost del = INF;
	for(int j = 1; j <= n; j++) if(pre2[j] == -1) del = min(del, p[j]);
	for(int i = 1; i <= n; i++) if(pre1[i] != -1) lx[i] += del;
	for(int j = 1; j <= n; j++){
		if(pre2[j] != -1) ly[j] -= del;
		else{
			p[j] -= del;
			if(p[j] == 0){
				// this node is feasible now, add it to the equality subgraph and append it to bfs queue
				pre2[j] = pi[j];
				q[back++] = mp(j,1);
			}
		}
	}
}

/*
Increase the matching count by making appropriate changes on the augmenting path
*/
void primalIteration(int &path){
	int j = path, i;
	while(j != 0){
		i = pre2[j];
		matchx[i] = j, matchy[j] = i;
		match[i][j] = 1, matchingCount++;
		res += cost[i][j];

		j = pre1[i];
		if(j != 0){
			match[i][j] = 0, matchingCount--;
			res -= cost[i][j];
		}
	}
}

Cost minCostBipartiteMatching(){
	dualInitialization();
	primalInitialization();
	
	// we will have at most n augmentations
	while(matchingCount < n){
		pathInitialization();
		
		int path = -1;
		while(path == -1){
			while(path == -1 and front < back) findAugmentingPath(path);
			if(path == -1) dualIteration();
		}
		primalIteration(path);
	}
	return res;
}

int main(){

	return 0;
}
