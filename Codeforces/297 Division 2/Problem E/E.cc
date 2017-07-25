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

int n, k, a[30], nn, mm;
long long s, f[20], ans;
map<long long, long long> cnt[30];

int main(){ _
	cin >> n >> k >> s;
	
	f[0] = 1;
	for(int i = 1; i < 19; i++)	f[i] = f[i-1]*i;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	nn = (n+1)/2;
	mm = n-nn;
	
	cnt[0][0] = 1;
	
	for(int mask = 0; mask < (1<<nn); mask++){
		long long cur = 0;
		for(int ii = 0; ii < nn; ii++){
			if((mask&(1<<ii)) > 0){
				cur += a[ii];
			}
		}
		
		if(cur > s) continue;
		
		for(int nmask = mask; ; nmask = ((nmask-1)&mask)){
			int ex = 0; long long sum = cur;
			
			for(int i = 0; i < nn and ex <= k and sum <= s; i++){
				if((nmask&(1<<i)) > 0){
					ex++;
					if(a[i] < 19) sum += f[a[i]]-a[i]; else ex = 100;
				}
			}
			
			if(ex > k or sum > s or sum == 0){
				if(nmask == 0) break;
				continue;
			}
			
			cnt[ex][sum]++;
						
			if(nmask == 0) break;
		}
	}
	
	
	for(int mask = 0; mask < (1<<mm); mask++){
		long long cur = 0;
		for(int ii = 0; ii < mm; ii++){
			if((mask&(1<<ii)) > 0) cur += a[nn+ii];
		}
		
		if(cur > s) continue;
		
		for(int nmask = mask; ; nmask = ((nmask-1)&mask)){
			int ex = 0; long long sum = cur;
			
			for(int i = 0; i < mm and ex <= k and sum <= s; i++){
				if((nmask&(1<<i)) > 0){
					ex++;
					if(a[nn+i] < 19) sum += f[a[nn+i]]-a[nn+i]; else ex = 100;
				}
			}
			
			if(ex > k or sum > s){
				if(nmask == 0) break;
				continue;
			}
			
			for(int i = 0; i <= k-ex; i++) ans += cnt[i][s-sum];
						
			if(nmask == 0) break;
		}
	}
	
	tr(ans);
	
	return 0;
}
