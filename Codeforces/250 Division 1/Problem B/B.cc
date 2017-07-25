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

const int N = 100100;
int p[N], rank[N], size[N];

void create(int x){
	p[x] = x;
	rank[x] = 0;
	size[x] = 1;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(rank[px] > rank[py]) p[py] = px, size[px] += size[py];
	else p[px] = py, size[py] += size[px];
	
	if(rank[px] == rank[py]) rank[py] = rank[py] + 1;
	return;
}

int n, m, x, y, val[100100];
vector<int> g[100100];
vector<pair<int, int> > v;

long long ans;

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		sd(val[i]);
		v.pb(mp(val[i], i));
	}
	
	sort(v.begin(), v.end(), greater<pair<int, int> >());
	
	for(int i = 0; i < m; i++){
		sd2(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	
	for(int i = 0; i < n; i++){
		int cur = v[i].se; create(cur);
		long long cnt = 0, cnt2 = 1;
		set<int> found;
		
		foreach(it, g[cur]){
			if(val[*it] >= val[cur] and size[*it] > 0 and !found.count(find(*it))){
				
				found.insert(find(*it));
				
				cnt += (long long)(size[find(*it)]*cnt2);
				cnt2 += size[find(*it)];
				merge(cur, *it);
			}
		}
		ans += (long long)cnt*val[cur];
	}
	
	long double res = (long double) 2.0f/(long double) n;
	res /= (long double) (n-1);
	
	res *= ans;
	
	printf("%.15lf\n", (double) (res));
	return 0;
}
