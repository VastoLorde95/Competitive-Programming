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

int n, l[5], r[5], mx;
double dp[5][10001], ans;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(l[i], r[i]);
		mx = max(mx, r[i]);
	}
	
	for(int i = 1; i <= mx; i++){
		for(int j = 1; j < (1<<n); j++){
			vector<int> s;
			for(int k = 0; k < n; k++){
				if((j&(1<<k)) > 0) s.pb(k);
			}
			if(s.size() < 2) continue;
			
			double p = 1;
			
			for(int k = 0; k < n; k++){
				if((j&(1<<k)) > 0){
					if(l[k] <= i and i <= r[k]){
						p /= (double) (r[k]-l[k]+1);
					}
					else{
						p = 0;
					}
				}
				else{
					if(l[k] < i){
						if(r[k] >= i){
							p *= (i - l[k]);
							p /= (double) (r[k]-l[k]+1);
						}
					}
					else{
						p = 0;
					}
				}
			}
			
			
			ans += p*i;
			
//			tr2(i,j)
//			foreach(it, s) cout << *it << ", "; cout << endl;
			
			foreach(it, s){
				p = 1;
//				tr4("before",i,j,*it);
				for(int k = 0; k < n; k++){
					if(k == *it){
						if(r[k] > i){
							if(l[k] <= i){
								p *= (r[k]-i);
								p /= (double) (r[k]-l[k]+1);
								
							}
						}
						else{
							 p = 0;
							 break;
						}
					}
					else if((j&(1<<k)) > 0){
						if(l[k] <= i and i <= r[k]){
							p /= (double) (r[k]-l[k]+1);
						}
						else{
							p = 0;
							break;
						}
					}
					else{
						if(l[k] < i){
							if(r[k] >= i){
								p *= (i - l[k]);
								p /= (double) (r[k]-l[k]+1);
							}
						}
						else{
							p = 0;
							break;
						}
					}
				}
				ans += p*i;
			}
			
		}
	}
	
	printf("%.11lf\n", ans);
	
	return 0;
}
