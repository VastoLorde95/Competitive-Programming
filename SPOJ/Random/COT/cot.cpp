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

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

#define sz size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)

#define N 111111
#define LN 19

int val[N], jump_table[N][LN], RM[N], depth[N], maxi = 0;
vector <int> adj_list[N];
map <int, int> compresser;

struct node{
	int count;
	node *left, *right;
	
	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}
		
	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);

node * node::insert(int l, int r, int w){
	if(l <= w && w < r){
	// If the node we are adding belongs to some range already covered by the segment tree of its parent, we need to create a new node corresponding to it for the segment tree rooted at the current node. This is one of the log(n) nodes that will be created.
		if(l+1 == r){
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

void dfs(int cur, int prev){
	jump_table[cur][0] = prev;
	depth[cur] = (prev == -1 ? 0 : depth[prev] + 1);
	
	// Construct the segment tree for this node using parent segment tree
	// This is the formula we derived
	root[cur] = ( prev == -1 ? null : root[prev] )->insert( 0, maxi, compresser[val[cur]] );	// Create a persistent segment tree at node cur. for reach node that holds responsibility for compresser[val[cur]] we create a new node. For those nodes that don't hold any reponsiblity, we simple use the nodes of the parent's segment tree.
	
	rep(i, adj_list[cur].sz)
		if(adj_list[cur][i] != prev)
			dfs(adj_list[cur][i], cur);
}

int LCA(int u, int v){
	if(depth[u] < depth[val])
		swap(u,v);
		
	int diff = depth[u] - depth[v];
	
	rep(i, LN)
		if((diff>>i) & 1)
			u = jump_table[u][i];
			
	if(u != v){
		fd(i, LN-1, 0)
			if(jump_table[u][i] != jump_table[v][i])
			{
				u = jump_table[u][i];
				v = jump_table[v][i];
			}
		u = jump_table[u][0];
	}
	return u;
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k){
	while(1){
		if(l+1 == r) return l;
	
		// This is the formula we derived
		int count = a->left->count + b->left->count - c->left->count - d->left->count;
		int m = (l+r)>>1;
	
		// We have enough on left, so go left
		if(count >= k)
			a = a->left, b = b->left, c = c->left, d = d->left, r = m;
		// We do not have enough on left, go right, remove left elements count
		else
			a = a->right, b = b->right, c = c->right, d = d->right, l = m, k -= count;
	}
}

int main(){
	int n, m, u, v, k, lca, ans;
	
	scanf("%d%d", &n, &m);
	
	rep(i, n){
		scanf("%d", &val[i]);
		compresser[val[i]];
	}
	
	maxi = 0;
	for( map <int, int > :: iterator it = compresser.begin(); it != compresser.end(); it++){
		compresser[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}
	
	// We compressed the given weights into the range [0..n)
	
	rep(i, n-1){
		scanf("%d%d", &u, &v);
		u--; v--;
		adj_list[u].pb(v);
		adj_list[v].pb(u);
	}
	
	// Root the tree at some node.
	memset(jump_table, -1, sizeof jump_table);
	null->left = null->right = null;
	dfs(0, -1);
	
	// Build jump table for LCA in O( N log N ). jump_table[i][j] denotes the 2^ j th ancestor of i
	for(int i = 0; i < LN-1; i++)
		for(int j = 0; j < n; j++)
			if(jump_table[j][i] != -1)
				jump_table[j][i+1] = jump_table[jump_table[j][i]][i];
				
	while(m--){
		//int u, val, k;
		scanf("%d%d%d", &u, &v, &k);
		u--; v--;
		
		lca = LCA(u, v);
		// Four nodes we spoke about are u, val, lca, parent(lca)
		ans = query(root[u], root[v], root[lca], (jump_table[lca][0] == -1 ? null : root[ jump_table[lca][0] ]), 0, maxi, k);
		
		// Reverse Map the values, that is, uncompress
		printf("%d\n", RM[ans]);
	}
}

