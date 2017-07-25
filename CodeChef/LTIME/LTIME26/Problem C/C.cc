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

typedef long long ll;

int t, x, y, a, b, di[2001000];
ll n, k, cnt, l1, l2, r1, r2, tot1, tot2;
set<ll> d1, d2;

int main(){
	sd(t);
	while(t--){
		scanf("%lld%lld", &n, &k);
		d1.clear(), d2.clear();
		cnt = 0;
		memset(di, 0, sizeof di);	
		
		
		for(int i = 0; i < k; i++){
			sd2(x,y);
			a = x-y, b = x+y;
			
			if(!d2.count(b)){
				cnt += n-abs(n+1-b);
				d2.insert(b);
				di[b] = 1;
			}
			
			d1.insert(a);
		}
		
		r2 = n+2, l2 = n;
		r1 = l1 = (n+1);
		r1 += 2;
		l1 -= 2;
		
		tot1 = tot2 = 0;
		
		if(di[n+1]) tot1 = 1;
				
		foreach(it, d1){
			ll tmp = n - abs(*it);
//			tr5(cnt,tmp,tot1,tot2,*it);
			cnt += tmp;
			if(tmp%2 == 0){
				ll tx = (n+1) - (tmp-1);
				ll ty = (n+1) + (tmp-1);
				
				if(l2 >= tx){
					while(l2 >= tx){
						if(di[l2]) tot2++;
						l2 -= 2;
					}
				}
				else{
					while(l2 < tx){
						if(di[l2]) tot2--;
						l2 += 2;
					}
				}
				
				if(r2 <= ty){
					while(r2 <= ty){
						if(di[r2]) tot2++;
						r2 += 2;
					}
				}
				else{
					while(r2 > ty){
						if(di[r2]) tot2--;
						r2 -= 2;
					}
				}
				cnt -= tot2;
				
//				tr6("#1",tx,ty,l2,r2,tot2);
				
			}
			else{
				
				ll tx = (n+1) - (tmp-1);
				ll ty = (n+1) + (tmp-1);
				
				if(tmp == 1){
					if(di[n+1]) cnt--;
				}
				else{
					if(l1 >= tx){
						while(l1 >= tx){
							if(di[l1]) tot1++;
							l1 -= 2;
						}
					}
					else{
						while(l1 < tx){
							if(di[l1]) tot1--;
							l1 += 2;
						}
					}
				
					if(r1 <= ty){
						while(r1 <= ty){
							if(di[r1]) tot1++;
							r1 += 2;
						}
					}
					else{
						while(r1 > ty){
							if(di[r1]) tot1--;
							r1 -= 2;
						}
					}
					cnt -= tot1;
				}
				
//				tr6("#2",tx,ty,l1,r1,tot1);
			}
//			tr5(cnt,tmp,tot1,tot2,*it);
		}	
			
		printf("%lld\n", (n*n)-cnt);
		
	}
	return 0;
}
