/*
By Anudeep Nekkanti
Editorial at www.blog.anudeep.com/persistent-segment-trees-explained-with-spoj-problems
Question at http://www.spoj.com/problems/COT/
O( (N+M) * log N )
*/
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

using namespace std;

#define sz size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)

#define N 111111
#define LN 19

int v[N], pa[N][LN], RM[N], depth[N], maxi = 0;
vector <int> adj[N];
map <int, int> M;

struct node
{
	int count;
	node *left, *right;
	
	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}
		
	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL); //see line 135

node * node::insert(int l, int r, int w)
{
	if(l <= w && w < r)
	{
	// If the node we are adding belongs to some range already covered by the segment tree of its parent, we need to create a new node corresponding to it for the segment tree rooted at the current node. This is one of the log(n) nodes that will be created.
		if(l+1 == r)
		{
			//cout<<"index "<<w<<" with count = "<<this->count+1<<endl;
			return new node(this->count+1, null, null);
		}
		
		int m = (l+r)>>1;
		
		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}
	// Out of range, we can use the node of the segment tree of the parent as the current node. This is because out of range means that we don't need to update this particular range of nodes.
	return this;
}

node *root[N];

void dfs(int cur, int prev)
{
	pa[cur][0] = prev;
	depth[cur] = (prev == -1 ? 0 : depth[prev] + 1);
	
	// Construct the segment tree for this node using parent segment tree
	// This is the formula we derived
	root[cur] = ( prev == -1 ? null : root[prev] )->insert( 0, maxi, M[v[cur]] );	// Create a persistent segment tree at node cur. for reach node that holds responsibility for M[v[cur]] we create a new node. For those nodes that don't hold any reponsiblity, we simple use the nodes of the parent's segment tree.
	
	rep(i, adj[cur].sz)
		if(adj[cur][i] != prev)
			dfs(adj[cur][i], cur);
}

int LCA(int u, int v)
{
	if(depth[u] < depth[v])
		return LCA(v, u);
		
	int diff = depth[u] - depth[v];
	
	rep(i, LN)
		if((diff>>i) & 1)
			u = pa[u][i];
			
	if(u != v)
	{
		fd(i, LN-1, 0)
			if(pa[u][i] != pa[v][i])
			{
				u = pa[u][i];
				v = pa[v][i];
			}
		u = pa[u][0];
	}
	return u;
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k)
{
	if(l+1 == r)
	{
		return l;
	}
	
	// This is the formula we derived
	int count = a->left->count + b->left->count - c->left->count - d->left->count;
	int m = (l+r)>>1;
	
	// We have enough on left, so go left
	if(count >= k)
		return query(a->left, b->left, c->left, d->left, l, m, k);
		
	// We do not have enough on left, go right, remove left elements count
	return query(a->right, b->right, c->right, d->right, m, r, k - count);
}

int main()
{
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	rep(i, n)
	{
		scanf("%d", &v[i]);
		M[v[i]];
	}
	
	maxi = 0;
	for( map <int, int > :: iterator it = M.begin(); it != M.end(); it++ )
	{
		M[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}
	
	// We compressed the given weights into the range [0..n)
	
	rep(i, n-1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	// Root the tree at some node.
	memset(pa, -1, sizeof pa);
	null->left = null->right = null;
	dfs(0, -1);
	
	// Build jump table for LCA in O( N log N ). pa[i][j] denotes the 2^ j th ancestor of i
	rep(i, LN-1)
		rep(j, n)
			if(pa[j][i] != -1)
				pa[j][i+1] = pa[pa[j][i]][i];
				
	while(m--)
	{
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		u--; v--;
		
		int lca = LCA(u, v);
		// Four nodes we spoke about are u, v, lca, parent(lca)
		int ans = query(root[u], root[v], root[lca], (pa[lca][0] == -1 ? null : root[ pa[lca][0] ]), 0, maxi, k);
		
		// Reverse Map the values, that is, uncompress
		printf("%d\n", RM[ans]);
	}
}
