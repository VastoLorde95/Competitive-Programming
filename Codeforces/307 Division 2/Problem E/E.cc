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

int n, q, l, r, x, y, rt, type, group[500100];
long long up[800], num[500100];
vector<pair<long long, int> > a[800];

int main(){
	sd2(n,q);
	rt = int(ceil(sqrt(n)));
	
	int grp = 0;
	
	for(int i = 0; i < n; i++){
		sd(x);
		num[i] = x;
		a[grp].pb(mp(x,i));
		group[i] = grp;
		
		if(a[grp].size() == rt) grp++;
	}
	
	for(int i = 0; i <= grp; i++){
		sort(a[i].begin(), a[i].end());
	}
	
	while(q--){
		sd(type);
		
		if(type == 1){
			sd3(l,r,x);
			l--, r--;
			for(int i = group[l]+1; i <= group[r]-1; i++){
				up[i] += x;
			}
			
			a[group[l]].clear(); a[group[r]].clear();
			for(int i = l, j = group[l]; group[i] == j and i <= r; i++){
				num[i] += x;
			}
			
			int s = l, g = group[l];
			while(s >= 0 and group[s] == g) s--;
			s++;
			for(; s < n and group[s] == g; s++){
				a[g].pb(mp(num[s],s));
			}
			
						
			if(group[l] != group[r]){
				for(int i = r, j = group[r]; group[i] == j; i--){
					num[i] += x;
				}
				s = r, g = group[r];
				while(s >= 0 and group[s] == g) s--;
				s++;
				
				for(; s < n and group[s] == g; s++){
					a[g].pb(mp(num[s],s));
				}
				
			}
			
			sort(a[group[l]].begin(), a[group[l]].end());
			sort(a[group[r]].begin(), a[group[r]].end());
			
		}
		else{
			sd(y);
			int mx = 0, mn = 10000000;
			for(int i = 0; i <= grp; i++){
				if(a[i].size() == 0) continue;
			
				int lo = -1, hi = a[i].size()-1, mid;
				while(lo+1 < hi){
					mid = (lo+hi)/2;
					if(a[i][mid].fi + up[i] >= y) hi = mid;
					else lo = mid;
				}
				
				if(a[i][hi].fi + up[i] != y) continue;
				
				mn = min(mn, a[i][hi].se);
				
				lo = 0, hi = a[i].size();
				while(lo+1 < hi){
					mid = (lo+hi)/2;
					if(a[i][mid].fi + up[i] > y) hi = mid;
					else lo = mid;
				}
				
				if(a[i][lo].fi + up[i] != y) continue;
				
				mx = max(mx, a[i][lo].se);
			}
			
			if(mn == 10000000){
				printf("-1\n");
			}
			else{
				printf("%d\n", mx-mn);
			}
		}
	}
	
	return 0;
}
