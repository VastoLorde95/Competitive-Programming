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
set<pair<int, int> > s;
set<pair<pair<int, int>, pair<int, int> > > seg;
pair<int, int> p1, p2;
pair<int, int> p[4];

int main(){
	int x1, x2, y1, y2;
	
	for(int i = 0; i < 4; i++){
		sd2(x1,y1); sd2(x2,y2);
		
		p1 = mp(x1,y1);
		p2 = mp(x2,y2);
		
		if(x1 != x2 and y1 != y2){
			puts("NO");
			return 0;
		}
		if(p1 == p2){
			puts("NO");
			return 0;	
		}
		
		if(seg.find(mp(p1,p2)) != seg.end() or seg.find(mp(p2,p1)) != seg.end()){
			puts("NO");
			return 0;
		}
		
		s.insert(p1);
		s.insert(p2);
		
		seg.insert(mp(p1,p2));
		seg.insert(mp(p2,p1));
	}
	
	if(s.size() != 4){
		puts("NO");
		return 0;
	}
	
	int cur = 0;
	
	for(set<pair<int,int> >::iterator it = s.begin(); it != s.end(); it++){
		p[cur++] = *it;	
	}
	
	if(p[0].fi == p[1].fi and p[2].fi == p[3].fi and p[0].se == p[2].se and p[1].se == p[3].se) 
		puts("YES");	
	else
		puts("NO");
	
	return 0;
}
