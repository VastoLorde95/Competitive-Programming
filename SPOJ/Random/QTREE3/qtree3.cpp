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
#define N 101000
#define LOGN 17

using namespace std;

int BLACK = 1;
int WHITE = 0;

struct point{
	int color, ind;
	
	void assign_leaf(int x, int y){
		color = x;
		ind = y;
	}
	
	void merge(point& left, point& right){
		if(left.color == BLACK){
			color  = BLACK;
			ind = left.ind;
		}
		else if(right.color == BLACK){
			color = BLACK;
			ind = right.ind;
		}
		else{
			color = WHITE;
			ind = -1;
		}
	}
	
};

vector<int> adj_list[N];
int n, q, a, b, c;
int chain_no, chain_ind[N], chain_head[N], pos_in_base[N], chain_count[N], color[N];
int base_array[N], reverse_map[N], ptr;
int depth[N], pa[N], subtree_size[N]; 
point s_tree[N*6];

void init(int i, int l, int r){
	if(l+1 == r){
		s_tree[i].assign_leaf(base_array[l], l);
		return;
	}
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	
	init(left, l, mid);
	init(right, mid, r);
	
	s_tree[i].merge(s_tree[left],s_tree[right]);
	return;
}

void update_tree(int i, int l, int r, int x){
	if(l > x or r <= x)	//Not in range
		return;
	if(l == x and l+1 == r){	//Perfectly in range
		s_tree[i].color = 1 - s_tree[i].color;
		if(s_tree[i].color == BLACK){
			s_tree[i].ind = l;
		}
		else{
			s_tree[i].ind = -1;
		}
		return;
	}
	
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	
	update_tree(left, l, mid, x);		//Update left half
	update_tree(right, mid, r, x);		//Update right half
	
	s_tree[i].merge(s_tree[left],s_tree[right]);		//Merge the result
	return;
}

point query_tree(int i, int l, int r, int x, int y){
	if(l >= y or r <= x){	//Completely out of range
		point res;
		res.assign_leaf(WHITE, -1);
		return res;
	}
	else if(l >= x and r <= y)
		return s_tree[i];
	
	int left = (i<<1), right = left + 1, mid = (l+r)>>1;
	point res, le = query_tree(left, l, mid, x, y), ri = query_tree(right, mid, r, x, y);
	res.merge(le, ri);
	return res;
}

int query_up(int u, int v){
	if(color[v] == BLACK)
		return 1;
	else if(u == v){
		return -1;
	}

	
	int uchain, vchain = chain_ind[v], ind = -1;
	point temp;
	while(1){
		uchain = chain_ind[u];
		if(uchain == vchain){
			if(u == v) break;
			
			//if(chain_count[uchain] > 0){
				temp = query_tree(1, 0, ptr, pos_in_base[v]+1, pos_in_base[u]+1);
				if(temp.color == BLACK)
					ind = temp.ind;
			//}
			break;	
		}
		//if(chain_count[uchain] > 0){
			temp = query_tree(1, 0, ptr, pos_in_base[chain_head[uchain]], pos_in_base[u] + 1);
			if(temp.color == BLACK)
				ind = temp.ind;
		//}
		
		u = pa[chain_head[uchain]];
	}
	
	if(ind == -1)
		return -1;
	else
		return reverse_map[ind] + 1;	 
	
}

void hld(int cur, int prev){
	if(chain_head[chain_no] == -1){
		chain_head[chain_no] = cur;
	}
	chain_ind[cur] = chain_no;		//The chain number in which a node belongs
	pos_in_base[cur] = ptr;			//The position of the node in base_array
	reverse_map[ptr] = cur;
	base_array[ptr++] = WHITE;		//Cost of the edge connecting current node to its parent
	
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
	
	return;
}

void dfs(int cur, int prev, int d){
	pa[cur] = prev;			//The immediate ancestor of the current node
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

int main(){
	
	sd2(n,q);
	
	for(int i = 0; i < n; i++){
		chain_head[i] = -1;
		color[i] = WHITE;
		chain_count[i] = 0;
	}	
	
	for(int i = 1; i < n; i++){
		sd2(a,b);
		a--, b--;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	
	chain_no = 0, ptr = 0;
	dfs(root, -1, 0);		//Will compute the subtree size of each node, their depths and immediate ancestors;
	hld(root, -1);			//Decompose the tree into log(N) number of linear chains
	init(1, 0, ptr);		//Initialize the segment 
	
	for(int i = 0; i < q; i++){
		sd2(a,b);
		if(a == 0){
			int node = b-1;
			color[node] = 1 - color[node];
			if(color[node] == WHITE){
				chain_count[chain_ind[node]]--;
			}
			else{
				chain_count[chain_ind[node]]++;
			}
			update_tree(1, 0, ptr, pos_in_base[node]);
		}
		else{
			printf("%d\n",query_up(b-1,0));
		}
	}

	return 0;
}
