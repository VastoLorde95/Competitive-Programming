#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef pair<int, int> pii;

const int N = 1<<18;
int n, q, p[N], rank[N], size[N], type, x, y, inf = 1e9;
set<pii> seg;
set<pii>::iterator it1, it2;

void create(int x){
	p[x] = x;
	rank[x] = 0;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(rank[px] > rank[py]) p[py] = px;
	else p[px] = py;
	if(rank[px] == rank[py]) rank[py] = rank[py] + 1;
	return;
}

int main(){
	sd2(n,q);
	for(int i = 1; i <= n; i++){
		create(i);
		seg.insert(mp(i,i));
	}
	
	while(q--){
		sd3(type,x,y);
		it1 = seg.upper_bound(mp(x,inf)); it1--;
		if(type == 1){
			it2 = seg.upper_bound(mp(y,inf)); it2--;
			if(find(it1->fi) != find(it2->fi)){
				merge(it1->fi, it2->fi);
			}
		}
		else if(type == 2){
			int l = it1->fi, r = it1->se + 1;
			while(r <= y){
				it2 = seg.upper_bound(mp(r,inf)); it2--;
				if(find(it1->fi) != find(it2->fi))
					merge(it1->fi, it2->fi);
				
				r = it2->se+1;
				seg.erase(it2);
			}
			seg.erase(it1);
			seg.insert(mp(l,r-1));
		}
		else{
			it2 = seg.upper_bound(mp(y,inf)); it2--;
			if(find(it1->fi) == find(it2->fi)) puts("YES"); else puts("NO");
		}
	}
	
	return 0;
}
