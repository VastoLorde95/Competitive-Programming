#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
 
using namespace std;
 
#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 2000000009
 
typedef pair<int,int> PII;
typedef vector<int> VI;
 
 
//////////////////////////////////////////////////////////////////////
// Min cost bipartite matching via shortest augmenting paths
//
// This is an O(n^3) implementation of a shortest augmenting path
// algorithm for finding min cost perfect matchings in dense
// graphs.  In practice, it solves 1000x1000 problems in around 1
// second.
//
//   cost[i][j] = cost for pairing left node i with right node j
//   Lmate[i] = index of right node that left node i pairs with
//   Rmate[j] = index of left node that right node j pairs with
//
// The values in cost[i][j] may be positive or negative.  To perform
// maximization, simply negate the cost[][] matrix.
//////////////////////////////////////////////////////////////////////
 
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
 
double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
  int n = int(cost.size());
 
  // construct dual feasible solution
  VD u(n);
  VD v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
 
  // construct primal solution satisfying complementary slackness
  Lmate = VI(n, -1);
  Rmate = VI(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
	Lmate[i] = j;
	Rmate[j] = i;
	mated++;
	break;
      }
    }
  }
 
  VD dist(n);
  VI dad(n);
  VI seen(n);
 
  // repeat until primal solution is feasible
  while (mated < n) {
 
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
 
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++)
      dist[k] = cost[s][k] - u[s] - v[k];
 
    int j = 0;
    while (true) {
 
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
		if (seen[k]) continue;
		if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
 
      // termination condition
      if (Rmate[j] == -1) break;
 
      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
		if (seen[k]) continue;
		const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
		if (dist[k] > new_dist) {
		  dist[k] = new_dist;
		  dad[k] = j;
		}
      }
    }
 
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
 
    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
 
    mated++;
  }
 
  double value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
 
  return value;
}
 
#define N 10010
 
pair<PII , PII> ar[N];
 
int br[N],cr[N];
 
void solve()
{
    int n,m;
    sd(n);sd(m);
    for(int i=1;i<=n;i++)
    {
        sd(ar[i].S.F);
        sd(ar[i].S.S);
        sd(ar[i].F.S);
        ar[i].F.F = ar[i].S.F + ar[i].S.S;
    }
    sort(ar+1,ar+n+1);
 
    for(int i=0;i<m;i++)
    {
        sd(br[i]);
    }
    if(m<n)
    {
        for(int i=m;i<n;i++)
        {
            br[i] = 0;
        }
        m=n;
    }
    sort(br,br+m);
    int j = m-1;
    LL ans1 = 0;
    for(int i=n;i>0;i--)
    {
        if(ar[i].F.F >= br[j])
        {
            cr[i] = br[j];
        }
        else
        {
            cr[i] = ar[i].F.F;
        }
        ans1 += cr[i];
        //cout<<cr[i]<<endl;
        j--;
    }
    VVD cost;
    cost.resize(n);
    for(int i=0;i<n;i++)
    {
        cost[i].resize(n);
        for(int j=0;j<n;j++)
        {
            if(ar[i+1].F.F >= cr[j+1])
            {
                cost[i][j] = max(0,cr[j+1] - ar[i+1].S.F);
                cost[i][j] *= ar[i+1].F.S;
            }
            else
            {
                cost[i][j] = INF;
                cost[i][j] *= cost[i][j];
            }
            //cout<<cost[i][j]<<" "<<max(0,cr[j+1] - ar[i+1].S.F)<<" ";
        }
        //cout<<endl;
    }
 
    VI a,b;
 
    LL ans2 = MinCostMatching(cost,a,b);
 
 
    cout<<ans1<<" "<<ans2<<endl;
 
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
} 
