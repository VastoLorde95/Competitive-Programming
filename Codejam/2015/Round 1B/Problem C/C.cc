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

using namespace std;

int t, n, d[1000], h[1000], m[1000], tot;
double d1, d2, s1, s2, t1, t2;

int main(){
	sd(t);
	for(int T = 1; T <= t; T++){
		sd(n);
		for(int i = 0; i < n; i++){
			sd3(d[i], h[i], m[i]);
			tot += h[i];
		}
		
		if(tot == 1){
			printf("Case #%d: %d\n", T, 0);
		}
		else{
			if(n == 1){
				s1 = (double)360/d[0];
				s2 = (double)360/(d[0]+1);
				
				t2 = (360 - d[0])/s2;
				t1 = (720 - d[0])/s1;
				
				if(t1 <= t2){
					printf("Case #%d: %d\n", T, 1);
				}
				else{
					printf("Case #%d: %d\n", T, 0);
				}
			}
			else{
				if(m[0] == m[1]){
					printf("Case #%d: %d\n", T, 0);
				}
				else{
					vector<pair<int, int> > temp;
					temp.pb(mp(d[0], m[0]));
					temp.pb(mp(d[1], m[1]));
					sort(temp.begin(), temp.end());
					
					if(m[0] > m[1]){
						// the guy nearer to me is slower
						d1 = (tmp[0].fi + 360 - tmp[1].fi);
						d2 = 360 - tmp[0].fi;
						
						s1 = 360/tmp[0].se;	// my speed
						s2 = (360/(tmp[1].se)) - (360/(tmp[0].se));
						
						t1 = d2/s1;
						t2 = d1/s2;
						
						if(t2 <= t1){
							printf("Case #%d: %d\n", T, 1);
						}
						else{
							printf("Case #%d: %d\n", T, 0);
						}
					}
					else{
						
					}
					
				}
			}
		}
	}	
	return 0;
}
