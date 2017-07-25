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

typedef long double ld;

ld a, d, x, y;
int n, cur;



int main(){
	cin >> a >> d >> n;
	
	while(d >= 4*a) d -= 4*a;
	
	for(int i = 0; i < n; i++){
		ld tmp = d;
		while(tmp > 0){
//			tr4(cur,x,y,tmp);
			if(cur == 0){
				if(x+tmp < a){
					x += tmp;
					tmp = 0;
				}
				else{
					cur = (cur+1)%4;
					tmp -= (a-x);
					x = a;
				}
			}
			else if(cur == 1){
				if(y+tmp < a){
					y += tmp;
					tmp = 0;
				}
				else{
					cur = (cur+1)%4;
					tmp -= (a-y);
					y = a;
				}
			}
			if(cur == 2){
				if(x-tmp > 0){
					x -= tmp;
					tmp = 0;
				}
				else{
					cur = (cur+1)%4;
					tmp -= x;
					x = 0;
				}
			}
			else if(cur == 3){
				if(y-tmp > 0){
					y -= tmp;
					tmp = 0;
				}
				else{
					cur = (cur+1)%4;
					tmp -= y;
					y = 0;
				}
			}
		}
		printf("%.5lf %.5lf\n", (double) x, (double) y);
	}
	
	
	return 0;
}
