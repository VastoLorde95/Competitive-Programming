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

int t, n, m, s, q, r[20001], p, expand;
long long cost;
vector<int> pos, sp;

int main(){
	sd(t);
	while(t--){
		sd2(n,m); sd2(s,q); memset(r, 0, sizeof r);
		pos.clear(); sp.clear();
		expand = 0;
		
		for(int i = 0; i < m; i++){
			sd(p);
			r[p] = p;
			pos.pb(p);
		}
		
		for(int i = 1; i <= n+n; i++){
			r[i] = max(r[i], r[i-1]);
		}
		
		cost = 1e18;
		
		for(int len = pos[0]-1; len <= n; len++){
			int cur = 1, prev = -1;
			bool ok = true;
			
			vector<int> tmp;
			while(cur <= n){
				if(r[cur+len] <= prev){
					ok = false;
					break;
				}
				else{
					prev = r[cur+len];
					tmp.pb(r[cur+len]);
					cur = r[cur+len]+len+1;
				}
			}
			
			if(ok){
				long long ncost = ((long long) q*len) + ((long long) s*tmp.size());
				
				if(ncost < cost){
					cost = ncost;
					sp = tmp;
					expand = len;
				}
			}
		}
		
		printf("%d %d\n", (int) sp.size(), expand);
		foreach(it, sp) printf("%d ", *it); printf("\n");
	}
	return 0;
}
