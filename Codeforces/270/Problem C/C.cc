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

int n, p, inf = 1e9;
pair<string, string> u[100100];
vector<int> v;
map<string, int> mm;
map<string, int> rank;

int lis(){
	int sz = v.size(), len = 0;
	vector<int> m(sz, inf);
	for(int i = 0; i < sz; i++){
		*lower_bound(m.begin(), m.end(), v[i]) = v[i];
	}
	
	while(len < sz and m[len] != inf) len++;
	
	return len;
}

int main(){ _
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> u[i].fi >> u[i].se;
		mm[u[i].fi] = mm[u[i].se] = i;
	}
	
	int r = 1;
	foreach(it, mm){
		rank[it->fi] = r++;
	}
	
	for(int i = 1; i <= n; i++){
		cin >> p;
		
		int r1 = rank[u[p].fi], r2 = rank[u[p].se];
		
		v.pb(max(r1,r2));
		v.pb(min(r1,r2)); 
	}
	
	
	int l = lis(); 
	if(l == n) puts("YES"); else puts("NO");
	
	return 0;
}
