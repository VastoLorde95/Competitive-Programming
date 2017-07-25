#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int n, m, q, a, b, c, u, v, res;
unordered_map<int, int> uf[100001];	//map the vertex to its representative
unordered_map<int, int> rnk[100001];//rank of the vertex
map<pair<int, int>, int> memo;
vector<int> edges[100001];
unordered_set<int> col;

int fnd(int x){
	int r = x;
	while(uf[c][r] != r) r = uf[c][r];
	if(x != r){
		int k = uf[c][x];
		while(k != r){
			uf[c][x] = r;
			x = k;
			k = uf[c][k];
		}
	}
	return r;
}

/*void merge(int x, int y){
	int a1 = fnd(x), b1 = fnd(y);
	if(a1 == b1) continue;
	if(rnk[c][a1]  > rnk[c][b1])
		swap(a1,b1);
	else if(rnk[c][a1] == rnk[c][b1]) rnk[c][b1]++;
	uf[c][a1] = b1;
	return;
}*/

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd3(a,b,c);
		edges[a].push_back(c);
		edges[b].push_back(c);
		if(uf[c].find(a) != uf[c].end()){
			if(uf[c].find(b) != uf[c].end()){
				
				int a1 = fnd(a), b1 = fnd(b);
				if(a1 != b1){
					if(rnk[c][a1]  > rnk[c][b1])
						swap(a1,b1);
					else if(rnk[c][a1] == rnk[c][b1]) rnk[c][b1]++;
					uf[c][a1] = b1;
				}
			}
			else{
				rnk[c][b] = 1; uf[c][b] = b;
				
				int a1 = fnd(a), b1 = fnd(b);
				if(a1 != b1){
					if(rnk[c][a1]  > rnk[c][b1])
						swap(a1,b1);
					else if(rnk[c][a1] == rnk[c][b1]) rnk[c][b1]++;
					uf[c][a1] = b1;
				}
			}
		}
		else{
			rnk[c][a] = 1; uf[c][a] = a;
			if(uf[c].find(b) != uf[c].end()){
				
				int a1 = fnd(a), b1 = fnd(b);
				if(a1 != b1){
					if(rnk[c][a1]  > rnk[c][b1])
						swap(a1,b1);
					else if(rnk[c][a1] == rnk[c][b1]) rnk[c][b1]++;
					uf[c][a1] = b1;
				}
			}
			else{
				rnk[c][a] = rnk[c][b] = 1;
				uf[c][a] = a, uf[c][b] = b;
				
				int a1 = fnd(a), b1 = fnd(b);
				if(a1 != b1){
					if(rnk[c][a1]  > rnk[c][b1])
						swap(a1,b1);
					else if(rnk[c][a1] == rnk[c][b1]) rnk[c][b1]++;
					uf[c][a1] = b1;
				}
				
			}
		}
	}
	sd(q);
	for(int i = 0; i < q; i++){
		sd2(u,v);
		if(memo.find(make_pair(u,v)) != memo.end()){
			printf("%d\n",memo[make_pair(u,v)]);
			continue;
		}
		res = 0;
		col.clear();
		if(edges[u].size() <= edges[v].size()){
			for(vector<int>::iterator it = edges[u].begin(); it != edges[u].end(); it++){
				c = *it;
				if(uf[c].find(v) != uf[c].end() and col.find(c) == col.end()){
					if(fnd(u) == fnd(v)){
						res++;
						col.insert(c);
					}
				}
			}
		}
		else{
			for(vector<int>::iterator it = edges[v].begin(); it != edges[v].end(); it++){
				c = *it;
				if(uf[c].find(u) != uf[c].end() and col.find(c) == col.end()){
					if(fnd(u) == fnd(v)){
						res++;
						col.insert(c);
					}
				}
			}
		}
		
		printf("%d\n",res);
		memo[make_pair(u,v)] = memo[make_pair(v,u)] = res;
	}
	return 0;
}
