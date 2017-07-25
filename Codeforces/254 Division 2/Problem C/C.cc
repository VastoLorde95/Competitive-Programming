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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m;
int x[501], removed[501], s, e;
int g[501][501], degree[501], sum[501];
vector<pair<int, pair<int, int> > > edges;
vector<pair<int, pair<int, int> > > mst;

const int N = 501;
int p[N], rank[N], size[N];

void create(int x){
	p[x] = x, rank[x] = 0;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(rank[px] > rank[py]) p[py] = px; else p[px] = py;
	if(rank[px] == rank[py]) rank[py] = rank[py] + 1;
	return;
}

int main(){
	sd2(n,m);
	
	if(m == 0){
		cout << 0 << endl; return 0;
	}
	
	for(int i = 1; i <= n; i++){
		sd(x[i]);
		s += x[i];
		create(i);
	}
	
	long double cur = 0;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		sd3(a,b,c);
		cur = max(cur, (long double)(x[a]+x[b]) / (long double) (c));
	}	
	
	printf("%.15lf\n", (double) cur);
	
	return 0;
}
