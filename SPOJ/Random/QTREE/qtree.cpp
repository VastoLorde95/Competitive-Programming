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

#define root 0
#define N 10001
#define LOGN 14

using namespace std;

vector<int> adj_list[N], costs[N], indexx[N];
int t, n, a, b, c;
int chain_no, chain_ind[N], chain_head[N], pos_in_base[N];
int base_array[N], ptr;
int depth[N], pa[LOGN][N], other_end[N], subtree_size[N]; 
int s_tree[N*2];
char instr[7];

void init(int i, int l, int r){
	if(l+1 == r){					//Different from the segment tree template where you you l == r.
		s_tree[i] = base_array[l];	//This is because we are initalizing as l,m; m,r instead of l,m; m+1,r
		return;
	}
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	
	init(left, l, mid);
	init(right, mid, r);
	
	s_tree[i] = s_tree[left] > s_tree[right] ? s_tree[left]: s_tree[right];
	
	return;
}

void update_tree(int i, int l, int r, int x, int val){
	//cout<<"Are we there yet?"<<endl;
	if(l > x or r <= x)	//Not in range
		return;
	if(l == x and l+1 == r){	//Perfectly in range
		s_tree[i] = val;
		return;
	}
	
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	
	update_tree(left, l, mid, x, val);		//Update left half
	update_tree(right, mid, r, x, val);		//Update right half
	
	s_tree[i] = s_tree[left] > s_tree[right] ? s_tree[left]: s_tree[right];		//Merge the result
	return;
}

int query_tree(int i, int l, int r, int x, int y){
	if(l >= y or r <= x)	//Completely out of range
		return -1;
	else if(l >= x and r <= y)
		return s_tree[i];
	
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	
	return max(query_tree(left, l, mid, x, y), query_tree(right, mid, r, x, y));
}

int query_up(int u, int v){		//This assumes that v is the ancestor of u
	if(u == v) return 0;

	int uchain, vchain = chain_ind[v], ans = -1;
	
	while(1){
		uchain = chain_ind[u];
		
		if(uchain == vchain){		//We are in the same chain and hence we can directly perform the query from u to v
			if(u == v) break;
			//query from u to v since we are in the final chain
			ans = max(ans, query_tree(1, 0, ptr, pos_in_base[v] + 1, pos_in_base[u] + 1));
			break;	
		}
		//Query from u to its chain head
		ans = max(ans, query_tree(1, 0, ptr, pos_in_base[chain_head[uchain]], pos_in_base[u] + 1));
		u = pa[0][chain_head[uchain]];	//Go to the next chain
	}
	
	return ans;	 
}

int LCA(int u, int v){
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

void hld(int cur, int cost,	int prev){
	if(chain_head[chain_no] == -1){
		chain_head[chain_no] = cur;
	}
	chain_ind[cur] = chain_no;		//The chain number in which a node belongs
	pos_in_base[cur] = ptr;			//The position of the node in base_array
	base_array[ptr++] = cost;		//Cost of the edge connecting current node to its parent
	
	int s_child = -1, new_cost, l = adj_list[cur].size();
	
	for(int i = 0; i < l; i++){
		if(adj_list[cur][i] != prev){
			if(s_child == -1 || subtree_size[adj_list[cur][i]] > subtree_size[s_child]){
				s_child = adj_list[cur][i];					//The child with maximum subtree size
				new_cost = costs[cur][i];					//The cost of the edge connecting the special child to the current node
			}
		}
	}
	if(s_child != -1){					//This condition will fail for leaf nodes, so we will have nothing else left to do
		hld(s_child, new_cost, cur);	//Add the special child to the current chain
	}
	
	for(int i = 0; i < l; i++){
		if(adj_list[cur][i] != s_child and adj_list[cur][i] != prev){
			chain_no++;
			hld(adj_list[cur][i], costs[cur][i], cur);		//Decompose the normal children into new chains
		}
	}
	
	return;
}

void dfs(int cur, int prev, int d){
	pa[0][cur] = prev;			//The immediate ancestor of the current node
	depth[cur] = d;				//The depth of the current node
	subtree_size[cur] = 1;		//The size of the subtree rooted at the current node
	int l = adj_list[cur].size();
	for(int i = 0; i < l; i++){
		if(adj_list[cur][i] != prev){
			other_end[indexx[cur][i]] = adj_list[cur][i];			//The other end of the current edge
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

void change(int edge, int val){
	update_tree(1, 0, ptr, pos_in_base[other_end[edge]], val);
	return;
}

int main(){
	sd(t);
	while(t--){
		
		sd(n);
		
		for(int i = 0; i < n; i++){
			adj_list[i].clear();		//Reset the containers to accomodate for new test case
			costs[i].clear();
			indexx[i].clear();
			chain_head[i] = -1;
			for(int j = 0; j < LOGN; j++)
				pa[j][i] = -1;
		}	
		
		for(int i = 1; i < n; i++){
			sd3(a,b,c);
			a--, b--;
			adj_list[a].push_back(b);
			adj_list[b].push_back(a);
			costs[a].push_back(c);
			costs[b].push_back(c);
			indexx[a].push_back(i-1);
			indexx[b].push_back(i-1);
		}
		
		chain_no = 0, ptr = 0;
		dfs(root, -1, 0);		//Will compute the subtree size of each node, their depths and immediate ancestors;
		hld(root, -1, -1);		//Decompose the tree into log(N) number of linear chains
		init(1, 0, ptr);		//Initialize the segment 
		
		for(int i = 1; i < LOGN; i++){					//Compute the jump table for lca using dynamic programming
			for(int j = 0; j < n; j++){
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
			}
		}
		
		while(1){
			scanf("%s",instr);	
			if(instr[0] == 'D')
				break;
			sd2(a,b);
			if(instr[0] == 'Q'){
				query(a-1, b-1);
			}
			else{
				change(a-1, b);
			}
		}
		
	}
	return 0;
}
