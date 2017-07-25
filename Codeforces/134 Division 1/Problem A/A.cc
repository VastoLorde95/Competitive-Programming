#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, x, y, p[101], rank[101];
vector<pair<int, int> > drifts;
set<int> distinct;

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void create_set(int x){
	p[x] = x;
	rank[x] = 0;
	return;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(rank[px] > rank[py]) p[py] = px;
	else p[px] = py;
	if(rank[px] == rank[py]) rank[py] = rank[py] + 1;
	return;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(x,y);
		drifts.pb(mp(x,y));
		create_set(i);
		for(int j = 0; j < i; j++){
			if(drifts[j].fi == x or drifts[j].se == y){
				merge(j,i);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		distinct.insert(find(i));
	}
	
	cout << distinct.size() -1 << endl;
	

	return 0;
}
