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

long long n, k, a[100000], mx, res, cnt[100001], tot;

int main(){ _
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	tot = 1;
	cnt[0] = 0;
	
//	for(int i = 0; i < n; i++){
//		cout << a[i] << " ";
//	}
//	cout << endl;
	
	for(int i = 1; i < n; i++){
		if(a[i] == a[i-1]){
			cnt[i+1] = cnt[i];
			tot++;
			continue;
		}
		
		cnt[i+1] = cnt[i] + tot*(a[i]-a[i-1]);
		tot++;
	}
	
//	for(int i = 0; i < n; i++){
//		cout << cnt[i+1] << endl;
//	}
	
	for(int i = 0; i < n; i++){
		int lo = 1, hi = i+2, mid;
		while(lo+1 < hi){
			mid = (lo+hi)/2;
			
			if((cnt[i+1] - cnt[i-mid+1])-((i+1-mid)*(a[i]-a[i-mid])) <= k){
				lo = mid;
			}
			else{
				hi = mid;
			}
			
		}
		
		if(lo > mx){
			mx = lo, res = a[i];
		}
	}
	
	cout << mx << " " << res << endl;
	
	return 0;
}
