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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

void rotate(int &x, int &y, int val){
	if(!val) return;
	swap(x,y);
}

int main(){
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	for(int i = 0; i < 2; i++){
		rotate(x1, y1, i);
		for(int j = 0; j < 2; j++){
			rotate(x2, y2, j);
			for(int k = 0; k < 2; k++){
				rotate(x3, y3, k);
//				tr6(x1,y1,x2,y2,x3,y3);
				if(x1 == x2 and x2 == x3 and x1 == y1+y2+y3){
					int n = x1;
					printf("%d\n", n);
					for(int l = 0; l < y1; l++){
						for(int x = 0; x < n; x++){
							printf("A");
						}
						printf("\n");
					}
					for(int l = 0; l < y2; l++){
						for(int x = 0; x < n; x++){
							printf("B");
						}
						printf("\n");
					}
					for(int l = 0; l < y3; l++){
						for(int x = 0; x < n; x++){
							printf("C");
						}
						printf("\n");
					}
					return 0;	
				}
				
				if(x1+x2+x3 == y1 and y1 == y2 == y3){
					int n = y1;
					printf("%d\n", n);
					for(int l = 0; l < n; l++){
						for(int x = 0; x < x1; x++){
							printf("A");
						}
						for(int x = 0; x < x2; x++){
							printf("B");
						}
						for(int x = 0; x < x3; x++){
							printf("C");
						}
						printf("\n");
					}
					return 0;	
				}
				
				vector<pair<pair<int, int>, int> > v;
				v.pb(mp(mp(x1,y1),1));
				v.pb(mp(mp(x2,y2),2));
				v.pb(mp(mp(x3,y3),3));
				sort(v.begin(), v.end());
				if(v[2].fi.fi == v[0].fi.fi+v[1].fi.fi and v[0].fi.se == v[1].fi.se and v[0].fi.se + v[2].fi.se == v[2].fi.fi){
					int n = v[2].fi.fi;
					printf("%d\n", n);
					for(int l = 0; l < n-v[2].fi.se; l++){
						char c;
						if(v[0].se == 1) c = 'A';
						else if(v[0].se == 2) c = 'B';
						else c = 'C';
						for(int x = 0; x < v[0].fi.fi; x++){
							printf("%c", c);
						}
						if(v[1].se == 1) c = 'A';
						else if(v[1].se == 2) c = 'B';
						else c = 'C';
						for(int x = 0; x < v[1].fi.fi; x++){
							printf("%c", c);
						}
						printf("\n");
					}
					for(int l = 0; l < v[2].fi.se; l++){
						char c;
						if(v[2].se == 1) c = 'A';
						else if(v[2].se == 2) c = 'B';
						else c = 'C';
						for(int x = 0; x < n; x++){
							printf("%c", c);
						}
						printf("\n");
					}
					return 0;
				}
				
			}
		}
	}
	
	puts("-1");
	
	return 0;
}
