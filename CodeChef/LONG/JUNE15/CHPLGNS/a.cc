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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int MAX_N = 100100;

int t, n, x, y, m;
vector<pair<int, int> > poly[MAX_N];
vector<pair<long long, int> > area;

int ans[MAX_N];

long long s1, s2, a;

int main(){
	sd(t);
	while(t--){
		sd(n);
		area.clear();
		for(int i = 0; i < n; i++){
			poly[i].clear();
			
			sd(m);
			
			for(int j = 0; j < m; j++){
				sd2(x,y);
				poly[i].pb(mp(x,y));
			}
			
			poly[i].pb(poly[i][0]);
			
			s1 = 0, s2 = 0, a = 0;
			
			for(int j = 0; j < m; j++){
				s1 += poly[i][j].fi * poly[i][j+1].se;
				s2 += poly[i][j].se * poly[i][j+1].fi;
			}
			
			a = abs(s1-s2);
			
			area.pb(mp(a,i));
		}
		
		sort(area.begin(), area.end());		
	
		for(int i = 0; i < n; i++){
			ans[area[i].se] = i;
		}
		
		for(int i = 0; i < n; i++){
			printf("%d ", ans[i]);
		}
		
		printf("\n");
	}
	
	return 0;
}
