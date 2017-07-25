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

long long x,y;
int n, m, a, b;
vector<pair<int, int> > mx, mn;

int main(){
	sd2(n,m);
	cin >> x >> y;
	for(int i = 0; i < n; i++){
		sd2(a,b);
		mx.pb(mp(a,b));
	}
	for(int i = 0; i < m; i++){
		sd2(a,b);
		mn.pb(mp(a,b));
	}
	
	int mx1 = 0, mx2 = 0;
	for(int i = 0; i < n; i++){
		if(mx[i].fi > mx1){
			mx1 = mx[i].fi;
			mx2 = mx[i].se;
		}
		else if(mx[i].fi == mx1 and mx[i].se > mx2){
			mx2 = mx[i].se;
		}
	}
	
	int mx3 = 0, mx4 = 0;
	for(int i = 0; i < n; i++){
		if(mx[i].se > mx4){
			mx4 = mx[i].se;
			mx3 = mx[i].fi;
		}
		else if(mx[i].se == mx4 and mx[i].fi > mx3){
			mx3 = mx[i].fi;
		}
	}
	
	int mx5 = 0, mx6 = 0;
	for(int i = 0; i < m; i++){
		if(mn[i].fi > mx5){
			mx5 = mn[i].fi;
			mx6 = mn[i].se;
		}
		else if(mn[i].fi == mx5 and mn[i].se > mx6){
			mx6 = mn[i].se;
		}
	}
	
	int mx7 = 0, mx8 = 0;
	for(int i = 0; i < m; i++){
		if(mn[i].se > mx8){
			mx8 = mn[i].se;
			mx7 = mn[i].fi;
		}
		else if(mn[i].se == mx8 and mn[i].fi > mx7){
			mx7 = mn[i].fi;
		}
	}
	
	long long v1 = mx1+mx3;
	long long v2 = mx2+mx4;
	v1 -= mx5;
	v1 -= mx7;
	v2 -= mx6;
	v2 -= mx8;
	
	if(mx1 > mx5 or mx4 > mx8){
		puts("Max");
		return 0;
	}
	
	if(v1 < 0 and v2 < 0){
		puts("Min");
		return 0;
	}

	if((long long)x+mx1-mx5 < 0 and (long long)y+mx2-mx6 < 0 and (long long)x+mx3-mx5 < 0 and (long long)y+mx4-mx6 < 0){
		puts("Min");
		return 0;
	}
	if((long long)x+mx1-mx7 < 0 and (long long)y+mx2-mx8 < 0 and (long long)x+mx3-mx7 < 0 and (long long)y+mx4-mx8 < 0){
		puts("Min");
		return 0;
	}
	
	puts("Max");
	
	return 0;
}
