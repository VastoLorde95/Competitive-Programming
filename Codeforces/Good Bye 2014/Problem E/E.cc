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

#define trc(x) cout<<"*** Reached breakpoint "<<x<<" ***"<<endl;

using namespace std;

const int LOGN = 18;

int n, p, l, q, x, y;
int pa[LOGN][1<<LOGN], cost[LOGN][1<<LOGN], a[1<<LOGN], r[1<<LOGN], u[1<<LOGN];
vector<pair<int, int> > d;
stack<pair<int, int> > s;

void sparseTable(){
	for(int i = 0; i < n; i++){
		pa[0][i] = u[i];
		if(u[i] == n) cost[0][i] = 0;
		else cost[0][i] = d[u[i]].fi - r[i];
	}
	
	pa[0][n] = n;
	
	for(int j = 1; j < LOGN; j++){
		pa[j][n] = n;	
		for(int i = 0; i < n; i++){
			pa[j][i] = pa[j-1][pa[j-1][i]];
			cost[j][i] = cost[j-1][i] + cost[j-1][pa[j-1][i]];
		}
	}
	return;
}

void query(){
	int ret = 0;
	for(int i = LOGN-1; i >= 0 and x < y; i--){
		
		if(pa[i][x] > y) continue;
		
		ret += cost[i][x];
		x = pa[i][x];
	}
	printf("%d\n", ret);
	return;
}

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd2(p,l);
		d.pb(mp(p,l));
	}
	
	r[n-1] = d[n-1].fi + d[n-1].se;
	u[n-1] = n;
	
	s.push(mp(n-1, r[n-1]));
	
	for(int i = n-2; i >= 0; i--){
		r[i] = d[i].fi + d[i].se;
		
		while(!s.empty()){
			if(r[i] >= d[s.top().fi].fi){
				r[i] = max(r[i], r[s.top().fi]);
				s.pop();
			}
			else break;
		}
		
		if(!s.empty()) u[i] = s.top().fi; 
		else u[i] = n;
		
		s.push(mp(i, r[i]));
	}
	
	sparseTable();
	
	sd(q);
	while(q--){
		sd2(x,y);
		--x, --y;
		query();
	}
	
	return 0;
}
