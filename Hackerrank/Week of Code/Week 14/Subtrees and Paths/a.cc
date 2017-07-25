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
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define root 1
#define N 110001
#define LOGN 17

using namespace std;

vector<int> adj_list[N];

int n, a, b, q, MINN = -2000000000;

int chain_no, chain_ind[N], chain_head[N], pos_in_base[N], pos_in_base2[N];

int base_array[N], ptr;

int depth[N], pa[LOGN][N], subtree_size[N]; 

int s_tree[4*N], lazy[4*N];

char instr[7];


void upd(int id, int l, int r, int x){	// Lazy propogation utility function
	lazy[id] += x;
	s_tree[id] += x;	//the maximum of all the nodes in the range l to r will increase by x
	return;
}

void shift(int id, int l, int r){	// Lazy propogation utility function
	int left = (id<<1), right = left + 1, mid = (l+r)>>1;
	upd(left, l, mid, lazy[id]);
	if(l != r)
		upd(right, mid, r, lazy[id]);
	lazy[id] = 0;	//succesfully propogated the load on the load to the children
	return;
}

// The segments of the tree are of the form [l, r)

void update_tree(int i, int x, int y, int l, int r, int val){
	
	if(x >= r or l >= y)	//Not in range
		return;
	if(x <= l and r <= y){	//Perfectly in range
		upd(i, l, r, val);
		return;
	}
	
	shift(i, l, r);	//Both children are responsible so propogate all updates to children
	
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	
	update_tree(left, x, y, l, mid, val);		//Update left half
	update_tree(right, x, y, mid, r, val);		//Update right half
	
	s_tree[i] = max(s_tree[left], s_tree[right]);	//Merge the result
	
	return;
}

// The segments of the tree are of the form [l, r)

int query_tree(int i, int l, int r, int x, int y){
	if(l >= y or r <= x){	//Completely out of range
			return MINN;
	}
	else if(l >= x and r <= y){
		return s_tree[i];
	}
	
	shift(i, l, r);	//Both children are responsible so propogate all updates to children
	
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	
	return max(query_tree(left, l, mid, x, y), query_tree(right, mid, r, x, y));
}

int query_up(int u, int v){		//This assumes that v is the ancestor of u
	int uchain, vchain = chain_ind[v], ans = MINN;
	
	while(1){
		uchain = chain_ind[u];
		
		if(uchain == vchain){		//We are in the same chain and hence we can directly perform the query from u to v
			ans = max(ans, query_tree(1, 0, ptr, pos_in_base[v] , pos_in_base[u] + 1));
			break;	
		}
		//Query from u to its chain head
		ans = max(ans, query_tree(1, 0, ptr, pos_in_base[chain_head[uchain]], pos_in_base[u] + 1));
		
		u = pa[0][chain_head[uchain]];	//Go to the next chain
	}
	
	return ans;	 
}

int LCA(int u, int v){	//Compute the lowest common ancestor using the sparse table - O(log(n))
	if(depth[u] < depth[v])
		swap(u, v);
		
	int diff = depth[u] - depth[v];
	
	for(int i = 0; i < LOGN; i++)
		if((diff>>i) & 1)
			u = pa[i][u];
			
	if(u != v){
		for(int i = LOGN-1; i >= 0; i--){
			if(pa[i][u] != pa[i][v])
			{
				u = pa[i][u];
				v = pa[i][v];
			}
		}
		u = pa[0][u];
	}
	return u;
}

void hld(int cur, int prev){	// Build Heavy-Light Chains. O(n)
	if(chain_head[chain_no] == -1){
		chain_head[chain_no] = cur;
	}
	chain_ind[cur] = chain_no;		//The chain number in which a node belongs
	pos_in_base[cur] = ptr;			//The position of the node in base_array
	base_array[ptr++] = 0;		//Cost of the edge connecting current node to its parent
	
	int s_child = -1, l = adj_list[cur].size();
	
	for(int i = 0; i < l; i++){
		if(adj_list[cur][i] != prev){
			if(s_child == -1 || subtree_size[adj_list[cur][i]] > subtree_size[s_child]){
				s_child = adj_list[cur][i];					//The child with maximum subtree size
			}
		}
	}
	
	if(s_child != -1){					//This condition will fail for leaf nodes, so we will have nothing else left to do
		hld(s_child, cur);	//Add the special child to the current chain
	}
	
	for(int i = 0; i < l; i++){
		if(adj_list[cur][i] != s_child and adj_list[cur][i] != prev){
			chain_no++;
			hld(adj_list[cur][i], cur);		//Decompose the normal children into new chains
		}
	}
	
	pos_in_base2[cur] = ptr;	//The position of the last node of the subtree rooted at "cur" in the base array	
	
	return;
}

void dfs(int cur, int prev, int d){
	pa[0][cur] = prev;			//The immediate ancestor of the current node
	depth[cur] = d;				//The depth of the current node
	subtree_size[cur] = 1;		//The size of the subtree rooted at the current node
	int l = adj_list[cur].size();
	for(int i = 0; i < l; i++){
		if(adj_list[cur][i] != prev){
			dfs(adj_list[cur][i], cur, d+1);						//Performing dfs on the neighbour of each node
			subtree_size[cur] += subtree_size[adj_list[cur][i]];	//Updating the size of the subtree		
		}
	}
	return;
}

void query(int u, int v){
	int lca = LCA(u,v);
	printf("%d\n",max(query_up(u,lca),query_up(v,lca)));
	return;
}

void change(int t, int val){
	update_tree(1, pos_in_base[t], pos_in_base2[t], 0, ptr, val);
	return;
}

int main(){
	sd(n);
	
	for(int i = 0; i <= n; i++){
		chain_head[i] = -1;
		for(int j = 0; j < LOGN; j++)
			pa[j][i] = -1;
	}	
	
	for(int i = 1; i < n; i++){
		sd2(a,b);
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	
	chain_no = 0, ptr = 0;
	dfs(root, -1, 0);		//Will compute the subtree size of each node, their depths and immediate ancestors;
	hld(root, -1);		//Decompose the tree into log(N) number of linear chains
	
	for(int i = 1; i < LOGN; i++){					//Compute the jump table for lca using dynamic programming
		for(int j = 0; j <= n; j++){
			if(pa[i-1][j] != -1)
				pa[i][j] = pa[i-1][pa[i-1][j]];
		}
	}
	
	sd(q);
	
	while(q--){
		scanf("%s",instr);
		if(instr[0] == 'a'){
			sd2(a,b);
			change(a,b);	// add b to all nodes in subtree of a
		}
		else{
			sd2(a,b);
			query(a,b);		// print maximum between path from a to b
		}
	}
	return 0;
}
